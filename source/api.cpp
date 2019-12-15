//
// Created by wellington on 15/12/2019.
//

#include "../header/api.h"

#define MOVIE_HASH_SIZE 6997
#define GENRES_HASH_SIZE 41
#define USER_HASH_SIZE 140009
#define TAG_HASH_SIZE 140009

void log(string log_msg){
    cout << log_msg << endl;
}

void alert(string msg){
    // TODO FILL WITH QT ALERT
    cout << msg << endl;
}

structures_handler load(string movie_file, string ratings_file, string tag_file){
    clock_t start, end;
    start = clock();

    // Populate Movie HashTable
    HashTable<IntHC, Movie> *movieHT = new HashTable<IntHC, Movie>(MOVIE_HASH_SIZE);
    TST *movieTST = new TST();
    HashTable<StringHashable, vector<Movie*>> *genres = new HashTable<StringHashable, vector<Movie*>>(GENRES_HASH_SIZE);

    ifstream file = ifstream(movie_file);
    if (file.is_open()) {
        string word;                   // line buffer
        getline(file, word);    // jumps the first line
        while (!file.eof()) {
            getline(file, word);    // get the line

            if (word.length() != 0) {
                Movie *movie = new Movie(word); // create a Movie based on csv line
                IntHC movieId = IntHC(movie->movieId);  // id hashable and comparable

                movieHT->insert(movieId, movie);
                for (string genre : movie->genres){
                    StringHashable genreSH(clear_string(genre));
                    vector<Movie*> *genreFromHT = genres->get(genreSH);

                    if (genreFromHT == nullptr){
                        genreFromHT = new vector<Movie*>();
                        genreFromHT->push_back(movie);
                    } else {
                        genreFromHT->push_back(movie);
                    }
                    genres->insert(genreSH, genreFromHT);
                }
                movieTST->insert(movie->title, movie->movieId);
            }
        }
        file.close();
    }
//    movieHT->show_info();
//    movieTST->show_info();
//    genres->show_info();
    log("Load Movie Hash Table...");
    log("Load Movie Trie...");
    log("Load Genres Hash Table...");

    // Populate User HashTable
    HashTable<IntHC, User> *userHT = new HashTable<IntHC, User>(USER_HASH_SIZE);

    file = ifstream(ratings_file);
    if (file.is_open()){
        string word;
        getline(file, word);
        while(!file.eof()) {
            getline(file, word);
            if (word.length() != 0) {
                // Here we populate the User on UserHT
                Rating *rating = new Rating(word);
                IntHC userId = IntHC(rating->userId);

                // verify if the user already exists
                User *user = userHT->get(userId);
                if (user != nullptr){
                    user->addRating(rating);
                    userHT->insert(userId, user);
                } else {
                    user = new User(userId.i);
                    user->addRating(rating);
                    userHT->insert(userId, user);
                }

                // verify if the movie exists
                Movie *movie = movieHT->get(rating->movieId);
                if (movie != nullptr){
                    movie->addRating(rating);
                    movieHT->insert(movie->movieId, movie);
                } else {
                    cout << "Movie doesn't exists on Movie HashTable" << endl;
                }
            }
        }
        file.close();
    }
    // show info
//    userHT->show_info();
    log("Load User Hash Table...");

    // Populate Tag HashTable
    HashTable<StringHashable, list<int>> *tagHT = new HashTable<StringHashable, list<int>>(TAG_HASH_SIZE);

    file = ifstream(tag_file);
    if (file.is_open()){
        string word;
        getline(file, word);
        while(!file.eof()) {
            getline(file, word);
            if (word.length() != 0) {
                // Here we populate the Tag on TagHT
                Tag *tag = new Tag(word);
                StringHashable stringTag = StringHashable(tag->tag);

                // verify if the movie already exists
                list<int> *moviesPerTag = tagHT->get(stringTag);
                if (moviesPerTag != nullptr){
                    moviesPerTag->push_back(tag->movieId);
                    tagHT->insert(stringTag, moviesPerTag);
                } else {
                    moviesPerTag = new list<int>();
                    moviesPerTag->push_back(tag->movieId);
                    tagHT->insert(stringTag, moviesPerTag);
                }
            }
        }
        file.close();
    }
    // show info
//    tagHT->show_info();
    log("Load Tag Hash Table...");

    end = clock();
    double time = (end - start)/(double)CLOCKS_PER_SEC;
    log("Time elapsed: " + to_string(time) +" s");

    structures_handler structuresHandler;
    structuresHandler.movieHT = movieHT;
    structuresHandler.movieTST = movieTST;
    structuresHandler.genres = genres;
    structuresHandler.userHT = userHT;
    structuresHandler.tagHT = tagHT;

    return structuresHandler;
}

void movie_query(vector<string> query_segments, TST *movieTST, HashTable<IntHC, Movie> *movieHT){
    // TODO search on Movie Trie
    string title = query_segments.at(1);
//            movi
}

void user_query(vector<string> query_segments, HashTable<IntHC, User> *userHT, HashTable<IntHC, Movie> *movieHT){
    IntHC userId = IntHC((stoi(query_segments.at(1))));
    User *user = userHT->get(userId);

    if (user != nullptr){
        for (auto *rating : user->ratings){
            Movie *movie = movieHT->get(IntHC(rating->movieId));
            cout << rating->rating << " " << movie->title << " " << movie->globalRating() << " " << movie->ratings_count << endl;
        }
    } else {
        alert("User doesn't exists in database");
    }
}

void top_genre_query(vector<string> query_segments, int n, HashTable<StringHashable, vector<Movie*>> *genres, HashTable<IntHC, Movie> *movieHT){
    StringHashable genre = StringHashable(clear_string(query_segments.at(1)));
    vector<Movie*> *movies = genres->get(genre);
    vector<Movie*> movies_cleaned;
//    printf("%d", movies->end());
    // Keep Movies with, at least, 1000 rating
    for (Movie *movie : (*movies)){
        if (movie->ratings_count >= 1000)
            movies_cleaned.push_back(movie);
    }

    insertion_sort<Movie>(&movies_cleaned[0], movies_cleaned.size());

    cout << "SORTED LIST: " << endl;
    for (int i = 0; i < n; i++){
        Movie *movie = movies_cleaned.at(i);
        cout << movie->title << " " << movie->globalRating() << endl;
    }
    // TODO
}

void tag_query(vector<string> query_segments, HashTable<StringHashable, list<int>> *tagHT, HashTable<IntHC, Movie> *movieHT){
    list<int> *moviesIds = tagHT->get(StringHashable(clear_string(query_segments.at(1))));
    list<int> selected_movies;

    if (moviesIds != nullptr){
        for (int movieId : *moviesIds){
            if (!contains(selected_movies, movieId)){
                bool movie_has_all_tags = true;
                for (int i = 1; i < query_segments.size(); i++){
                    list<int> *anotherMoviesIds = tagHT->get(StringHashable(clear_string(query_segments.at(i))));

                    bool exists = false;
                    if (anotherMoviesIds != nullptr){
                        exists = contains(*anotherMoviesIds, movieId);
                    }

                    if (!exists){
                        movie_has_all_tags = false;
                        break;
                    }
                }
                // if exists in all tags
                if (movie_has_all_tags)
                    selected_movies.push_back(movieId);
            }
        }

        for (int movieId : selected_movies){
            Movie *movie = movieHT->get(IntHC(movieId));
            cout << movie->movieId << " " << movie->title << " " << movie->globalRating() << " " << movie->ratings_count << endl;
        }

    }
}

void query(structures_handler structures, string query){
    // Query treatment
    vector<string> query_segments = split_query(query, ' ');
    string op = query_segments.at(0);
    if (op == "movie"){
        movie_query(query_segments, structures.movieTST, structures.movieHT);

    } else if (op == "user"){
        user_query(query_segments, structures.userHT, structures.movieHT);

    } else if (op.find("top") != string::npos){
        int top_n = stoi(op.substr(op.find("top")+3));
        top_genre_query(query_segments, top_n, structures.genres, structures.movieHT);

    } else if (op == "tags"){
        tag_query(query_segments, structures.tagHT, structures.movieHT);

    } else if (op == "quit") {
        exit(EXIT_SUCCESS);
    } else {
        alert("Operation not found!\nHelp commands:\n- movie <title or prefix>\n- user <userID>\n- top<N> '<genre>'\n- tags <list of tags>");
    }
}