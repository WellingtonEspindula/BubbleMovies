#include "../header/mainwindow.h"
#include <QApplication>
#include "../header/api.h"

using namespace std;

int main(int argc, char ** argv){
//        TESTING SCRIPT OF CSV TRANSCRIPT
//    vector<string> strings = split_csv("359,7442,\"Just Great. Now Every1 Knows Ewan Is \\\"\\\"Hooded\\\"\\\"\",2007-08-26 13:22:31", ',');
//    for (string s : strings)
//        cout << s << endl;

// TESTING TST
/*    TST *testTST = new TST();
    testTST->insert("abcd", 3);
    testTST->insert("oii", 2);
    testTST->insert("a", 10);
//    testTST->show();
//    cout << testTST->exists("abc") << endl;
//    cout << testTST->exists("abcd") << endl;
//    cout << testTST->exists("oii") << endl;
//    cout << testTST->exists("a") << endl;
//    cout << testTST->exists("ab") << endl;
    vector<pair<string, int>> search = testTST->search("o");
    for (pair<string, int> somepair : search)
        cout << somepair.first << " " << somepair.second << endl;
    return 0;*/

   /* Movie *movieTst = new Movie();
    movieTst->movieId = 1;
    movieTst->title = "aaaa";
    movieTst->genres.push_back("abc");
    movieTst->genres.push_back("ddd");
    movieTst->ratings_count = 3;
    movieTst->ratings_sum = 10;

    Movie *movieTst1 = new Movie();
    movieTst1->movieId = 2;
    movieTst1->title = "bbbb";
    movieTst1->genres.push_back("abc");
    movieTst1->genres.push_back("ddd");
    movieTst1->ratings_count = 5;
    movieTst1->ratings_sum = 20;

    vector<Movie*> movies = vector<Movie*>();
    movies.push_back(movieTst);
    movies.push_back(movieTst1);

    hybrid_sort<Movie>(&movies[0], movies.size());

    for (Movie *moviee : movies)
        cout << moviee->title << endl;

    return 0;*/

    // Need 3 args to start the program
    if (argc < 3){
        alert("Missing arguments.\nEx.: ./bubblemovies movies.csv rating.csv tag.csv\n");
        return EXIT_FAILURE;
    }
    // LOADING DATA STRUCTURES
    structures_handler structures = load(argv[1], argv[2], argv[3]);

    // LOAD QT APPLICATION WINDOW
    QApplication a(argc, argv);
    MainWindow w(nullptr, &structures);
    w.show();

    return a.exec();

    // QUERIES
//    while (true){
//        string query_str;
//        cout << "\nQuery: ";
//        getline(cin, query_str);

//        query(structures, query_str);
//    }


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
