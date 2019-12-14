#ifndef LIBS
#define LIBS
#include <algorithm>
#include <bits/stdc++.h>
#endif

#ifndef MODELS
#define MODELS
#include "../header/model/rating.h"
#include "../header/model/user.h"
#include "../header/model/movie.h"
#include "../header/model/tag.h"
#endif

#ifndef INTERFACES
#define INTERFACES
#include "../header/interfaces/comparable.h"
#include "../header/interfaces/hashable.h"
#endif

#ifndef UTILS
#define UTILS
#include "../header/utils/stringHashable.h"
#include "../header/utils/utils.h"
#endif

#ifndef DATASTRUCTURES
#define DATASTRUCTURES
#include "../header/datastructures/hash.h"
#include "../header/datastructures/tst.h"
#endif


#define MOVIE_HASH_SIZE 6997
#define GENRES_HASH_SIZE 41
#define USER_HASH_SIZE 140009
#define TAG_HASH_SIZE 140009


#define M_CHAINING 2477
#define M_EABQ 20123

using namespace std;

// prototypes
vector<pair<string, string>> readFileToPairVector(string fileName);
vector<vector<int>> readFileToVectors(string fileName);
vector<string> readFileToStringVector(string fileName);
void writeList(string fileName, vector<vector<int>> list);
void writeList(string fileName, vector<string> list);
void writeStats(string fileName, vector<string> strings, double time);

void alert(string msg){
    cout << msg << endl;
}

int main(int argc, char ** argv){
//        TESTING SCRIPT OF CSV TRANSCRIPT
//    vector<string> strings = split_csv("359,7442,\"Just Great. Now Every1 Knows Ewan Is \\\"\\\"Hooded\\\"\\\"\",2007-08-26 13:22:31", ',');
//    for (string s : strings)
//        cout << s << endl;

// TESTING TST
//    TST *testTST = new TST();
//    testTST->insert("abcd", 3);
//    testTST->insert("oii", 2);
//    testTST->insert("a", 10);
//    cout << testTST->exists("abc") << endl;
//    cout << testTST->exists("abcd") << endl;
//    cout << testTST->exists("oii") << endl;
//    cout << testTST->exists("a") << endl;
//    cout << testTST->exists("ab") << endl;

    // PROJECT CODE
    clock_t start, end;
    start = clock();

     // Need 3 args to start the program
     if (argc < 3){
         alert("Missing arguments.\nEx.: ./bubblemovies movies.csv rating.csv tag.csv\n");
         return EXIT_FAILURE;
     }

    // Populate Movie HashTable
    HashTable<IntHC, Movie> *movieHT = new HashTable<IntHC, Movie>(MOVIE_HASH_SIZE);
    TST *movieTST = new TST();
    auto *genres = new HashTable<StringHashable, vector<int>>(GENRES_HASH_SIZE);

    ifstream file = ifstream(argv[1]);
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
                    vector<int> *genreFromHT = genres->get(genreSH);

                    if (genreFromHT == nullptr){
                        genreFromHT = new vector<int>();
                        genreFromHT->push_back(movie->movieId);
                    } else {
                        genreFromHT->push_back(movie->movieId);
                    }
                    genres->insert(genreSH, genreFromHT);
                }
                movieTST->insert(movie->title, movie->movieId);
            }
        }
        file.close();
    }
    movieHT->show_info();
    movieTST->show_info();
    genres->show_info();

    // Populate User HashTable
    auto *userHT = new HashTable<IntHC, User>(USER_HASH_SIZE);

    file = ifstream(argv[2]);
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
    userHT->show_info();

    // Populate Tag HashTable
    auto *tagHT = new HashTable<StringHashable, list<int>>(TAG_HASH_SIZE);

    file = ifstream(argv[3]);
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
    tagHT->show_info();

    end = clock();
    double time = (end - start)/(double)CLOCKS_PER_SEC;
    cout << "Time elapsed: " << time << " s" << endl;


    while (true){
        string query;
        cout << "\nQuery: ";
        cin >> query;

        // Query treatment
        vector<string> query_segments = split(query, " ");
        string op = query_segments.at(0);
        if (op == "movie"){
            // TODO search on Movie Trie
        } else if (op == "user"){
            // TODO
        } else if (op.find("top") != string::npos){
            // TODO

        } else if (op == "tags"){
            // TODO

        } else {
            alert("Operation not found!\nHelp commands:\n- movie <title or prefix>\n- user <userID>\n- top<N> '<genre>'\n- tags <list of tags>");
        }
    }


//     cout << hashTable->get((string) "Reign") << endl;
//     cout << hashTable->get((string) "Maddelena") << endl;
//     hashTable->remove((string) "Maddelena");
//     cout << hashTable->get((string) "Maddelena") << endl;


//    StringHashable* sh = new StringHashable("Abcd");
//    string s = "efgh";
//    Test<StringHashable*, string> teste(sh, s);
//    cout << "Teste: " << teste.hashing() << endl;
//    StringHashable* sh1 = new StringHashable("abcd");
//    cout << "Teste: " << sh->compare(*sh1) << endl;

    // DEPRECATED
    // // Calling the program: 
    // // ./lab04 insertion.txt search.txt
    // // where insertion.txt is any text file to be inserted on the hash table
    // // and search.txt is any text file to be searched on the hash table

    // // Need 3 args to start the program
    // if (argc < 3){
    //     printf("Missing arguments.\n Ex.: ./lab4 insert_list.txt search_list.txt\n");
    //     return EXIT_FAILURE;
    // }

    // vector<string> names = readFileToStringVector(argv[1]);
    // vector<string> search_names = readFileToStringVector(argv[2]);

    // // 1.1
    // // 1.1.1 - Chaning and Horner
    // HashTable table1 = create(M_CHAINING, HORNER, CHAINING);
    // // reading name files
    // for (string name : names){
    //     insert(&table1, name);
    // }

    // // 1.1.2 - Chaning and Fibonacci
    // HashTable table2 = create(M_CHAINING, FIBONACCI, CHAINING);
    // for (string name : names){
    //     insert(&table2, name);
    // }

    // // 1.1.3 - Quadratic probing and Horner
    // HashTable table3 = create(M_EABQ, HORNER, EABQ);
    // for (string name : names){
    //     insert(&table3, name);
    // }

    // // 1.1.4 - Quadratic probing and Fibonacci
    // HashTable table4 = create(M_EABQ, FIBONACCI, EABQ);
    // for (string name : names){
    //     insert(&table4, name);
    // }
    
    // // Shows Hash Table's info
    // printf("TABLE 1:\n");
    // show_info(table1);
    // printf("\n");
    
    // printf("TABLE 2:\n");
    // show_info(table2);
    // printf("\n");

    // printf("TABLE 3:\n");
    // show_info(table3);
    // printf("\n");

    // printf("TABLE 4:\n");
    // show_info(table4);
    // printf("\n");


    // // 1.3
    // HashTable selected_table = table4;

    // vector<string> names_found;
    // vector<string> names_not_found;
    
    // int access_summary = 0;
    // float access_avg = 0;
    
    // int minor_access = search(selected_table, search_names.at(0));
    // int major_access = search(selected_table, search_names.at(0));
    
    // for (string name : search_names){
    //     // string name = search_names.at(i);
    //     int result = search(selected_table, name);
    //     if (result == -1){
    //         names_not_found.push_back(name);
    //     }
    //     else {
    //         names_found.push_back(name);
    //         access_summary += result;

    //         if (result < minor_access){
    //             minor_access = result;
    //         }
            
    //         if (result > major_access){
    //             major_access = result;
    //         }
    //     }
    // }
    // printf("\n");
    // access_avg =  (float) access_summary / (float) names_found.size();

    // printf("Names found: ");
    // show_list(&names_found[0], names_found.size());
    // printf("\n");

    // printf("Names not found: ");
    // show_list(&names_not_found[0], names_not_found.size());
    // printf("\n");
    
    // printf("Average access number: %.2f\n", access_avg);
    // printf("\n");

    // vector<string> major_access_list;
    // vector<string> minor_access_list;
    // for (string name : search_names){
    //     int result = search(selected_table, name);
    //     if (result == major_access)
    //         major_access_list.push_back(name);
    //     if (result == minor_access)
    //         minor_access_list.push_back(name);
    // }

    // printf("Major access number: %d\n", major_access);
    // printf("Names: ");
    // show_list(&major_access_list[0], major_access_list.size());
    // printf("\n");
    
    // printf("Minor access number: %d\n", minor_access);
    // printf("Names: \n");
    // show_list(&minor_access_list[0], minor_access_list.size());
    // printf("\n");

    // // Test code: Runs for search name showing how many access each name has
    // // for (int i = 0; i < search_names.size(); i++){
    // //     string name = search_names.at(i);
    // //     cout << i+1 << ". " << name << ": " << search(selected_table, name) << endl;
    // // }
    // // show_list(&names[0], names.size());


    return 0;
}

vector<pair<string, string>> readFileToPairVector(string fileName){
    vector<pair<string, string>> string_vector = vector<pair<string, string>>();

    ifstream file (fileName);
    if (file.is_open()){
        string word;
        string word2;

        while(!file.eof()) {
            getline(file, word, ' ');
            getline(file, word2, '\n');

            string_vector.push_back(pair<string, string>(word, word2));
        }

        file.close();
    }
    return string_vector;
}


vector<string> readFileToStringVector(string fileName){
    vector<string> string_vector = vector<string>();

    ifstream file (fileName);
    if (file.is_open()){
        string word;

        while(!file.eof()) { 
            getline(file, word);
            if (word.length() != 0)
                string_vector.push_back(word);
        }

        file.close();
    }
    return string_vector;
} 

void writeList(string fileName, vector<vector<int>> list){
    ofstream file (fileName);
    if (file.is_open())
    {
        file << list.size() << "\n";
        for (int i = 0; i < list.size(); i++){
            file << list.at(i).size() << " ";
            for (int j = 0; j < (list.at(i).size() - 1); j++){
                file << list.at(i).at(j) << " ";
            }
            file << list.at(i).back() << "\n";
        }      
        file.close();
    }
}

void writeList(string fileName, vector<string> list){
    ofstream file (fileName);
    if (file.is_open())
    {
        for (int i = 0; i < (list.size() - 1); i++){
            file << list.at(i) << " ";
        }      
        file << list.back() << "\n";
        file.close();
    }
}

void writeStats(string fileName, vector<string> strings, double time){
    ofstream file (fileName);
    if (file.is_open())
    {
        file << "Foram ordenadas " << strings.size() << " palavras em " << time << " segundos\n";
        
        string stringAtual = "";
        int countStringAtual = 0;
        for (string element : strings){
            if (element != stringAtual){
                if (!stringAtual.empty()){
                    file << countStringAtual << "\n";
                }
                stringAtual = element;
                file << "ocorrencias de " << stringAtual << ": ";
                countStringAtual = 1;
            } else {
                countStringAtual++;
            }
        }
        file << countStringAtual << "\n";
        file.close();
    }
}
