#ifndef LIBS
#define LIBS
#include <algorithm>
#include <bits/stdc++.h>
#endif

#ifndef UTILS
#define UTILS
#include "../../header/utils/utils.h"
#endif

using namespace std;


void random_list(int list[], int size){
    for (int i = 0; i < size; i++){
        list[i] = rand() % (size+1);
    }
}

void show_list(int list[], int size){
    printf("[");
    for (int i = 0; i < (size - 1); i++){
        printf("%d, ", list[i]);
    }
    printf("%d]\n", list[size - 1]);
}

void show_list(string list[], int size){
    printf("[");
    for (int i = 0; i < (size - 1); i++){
        cout << list[i] << ", ";
    }
    cout << list[size - 1] << "]\n";
}

void show_list(string list[], int l, int h){
    printf("[");
    for (int i = l; i < (h); i++){
        cout << list[i] << ", ";
    }
    cout << list[h] << "]\n";
}

int is_sorted(int C[], int tam) {
  for (int i=1; i<tam; i++) {
    if ( C[i-1] > C[i])
      return false;
  }
  return true;
}

bool is_sorted(string C[], int tam) {
  for (int i=1; i<tam; i++) {
    if ( C[i-1].compare(C[i]) < 0)
      return false;
  }
  return true;
}

// Measures time of of function f_sort
int benchmark(void(*f_sort)(int[] , int ), int input[], int N , char* name){
    clock_t start, end;
    double time = 0;

    if ( N < 100){
       printf("input: ");
       show_list(input,N);
    }

    start = clock();
    f_sort(input,N) ;
    end = clock();

    time = (end - start)/(double)CLOCKS_PER_SEC;

    if (!is_sorted(input,N)){
       fprintf(stderr,"ERROR in %s\n",name);
    }
    else{
       printf("%s;%d;%f\n", name, N , time);
    }

    if ( N < 100){
       printf("output: ");
       show_list(input,N);
    }

    return false;
}


// Measures time of of function f_sort
double benchmark(void(*f_sort)(string[] , int), string input[], int N , char* name){
    clock_t start, end;
    double time = 0;

    if ( N < 100){
       printf("input: ");
       show_list(input,N);
    }

    start = clock();
    f_sort(input,N) ;
    end = clock();

    time = (end - start)/(double)CLOCKS_PER_SEC;

/*     if (!is_sorted(input,N)){
       fprintf(stderr,"ERROR in %s\n",name);
       return -1;
    } */
/*     else{
       printf("%s;%d;%f\n", name, N, time);
    } */

    if ( N < 100){
       printf("output: ");
       show_list(input,N);
    }

    return time;
}

int fibonacci_sequence(int n) { 
    if (n <= 1) 
        return n; 
    return fibonacci_sequence(n-1) + fibonacci_sequence(n-2); 
}

vector<string> split(string str, string sep) {
    char* c_string = const_cast<char*>(str.c_str());
    char* current;

    vector<string> arr;
    current = strtok(c_string, sep.c_str());

    while(current != NULL){
        arr.push_back(current);
        current = strtok(NULL, sep.c_str());
    }
    return arr;
}

vector<string> split_csv(string str, char sep){
    vector<string> strings;
    string current;
    bool isUnderQuotationMarks = false;

    for (char c : str){
        if ((c == sep) && (!isUnderQuotationMarks) &&(!current.empty())){
            strings.push_back(current);
            current.clear();
        } else if ((c == '\"') && (current.back() != '\\')){
            isUnderQuotationMarks = !isUnderQuotationMarks;
        } else {
            if ((c == '\"') && (current.back() == '\\')){
                current.pop_back();
                current += '\"';
            } else{
                current += c;
            }
        }
    }

    if (!current.empty()){
        strings.push_back(current);
    }

    return strings;
}

vector<string> split_query(string str, char sep){
    vector<string> strings;
    string current;
    bool isUnderQuotationMarks = false;

    for (char c : str){
        if ((c == sep) && (!isUnderQuotationMarks) &&(!current.empty())){
            strings.push_back(current);
            current.clear();
        } else if ((c == '\'') && (current.back() != '\\')){
            isUnderQuotationMarks = !isUnderQuotationMarks;
        } else {
            if ((c == '\"') && (current.back() == '\\')){
                current.pop_back();
                current += '\"';
            } else{
                current += c;
            }
        }
    }

    if (!current.empty()){
        strings.push_back(current);
    }

    return strings;
}

string remove_quotation_marks(string in){
    in.erase(remove(in.begin(), in.end(), '\"'), in.end());
    return in;
}

string clear_string(string in){
    static auto dictionary = map<string, string>();
    dictionary.insert ( pair<string,string>("á","a") );
    dictionary.insert ( pair<string,string>("à","a") );
    dictionary.insert ( pair<string,string>("ã","a") );
    dictionary.insert ( pair<string,string>("â","a") );
    dictionary.insert ( pair<string,string>("ä","a") );
    dictionary.insert ( pair<string,string>("å","a") );
    dictionary.insert ( pair<string,string>("æ","a") );

    dictionary.insert ( pair<string,string>("Á","A") );
    dictionary.insert ( pair<string,string>("À","A") );
    dictionary.insert ( pair<string,string>("Ã","A") );
    dictionary.insert ( pair<string,string>("Â","A") );
    dictionary.insert ( pair<string,string>("Ä","A") );
    dictionary.insert ( pair<string,string>("Å","A") );
    dictionary.insert ( pair<string,string>("Æ","A") );

    dictionary.insert ( pair<string,string>("é","e") );
    dictionary.insert ( pair<string,string>("è","e") );
    dictionary.insert ( pair<string,string>("ê","e") );
    dictionary.insert ( pair<string,string>("ë","e") );

    dictionary.insert ( pair<string,string>("É","E") );
    dictionary.insert ( pair<string,string>("È","E") );
    dictionary.insert ( pair<string,string>("Ê","E") );
    dictionary.insert ( pair<string,string>("Ë","E") );

    dictionary.insert ( pair<string,string>("í","i") );
    dictionary.insert ( pair<string,string>("ì","i") );
    dictionary.insert ( pair<string,string>("î","i") );
    dictionary.insert ( pair<string,string>("ï","i") );

    dictionary.insert ( pair<string,string>("Í","I") );
    dictionary.insert ( pair<string,string>("Ì","I") );
    dictionary.insert ( pair<string,string>("Î","I") );
    dictionary.insert ( pair<string,string>("Ï","I") );

    dictionary.insert ( pair<string,string>("ó","o") );
    dictionary.insert ( pair<string,string>("ò","o") );
    dictionary.insert ( pair<string,string>("ô","o") );
    dictionary.insert ( pair<string,string>("ö","o") );
    dictionary.insert ( pair<string,string>("ø","o") );
    dictionary.insert ( pair<string,string>("õ","o") );

    dictionary.insert ( pair<string,string>("Ó","O") );
    dictionary.insert ( pair<string,string>("Ò","O") );
    dictionary.insert ( pair<string,string>("Ô","O") );
    dictionary.insert ( pair<string,string>("Ö","O") );
    dictionary.insert ( pair<string,string>("Ø","O") );
    dictionary.insert ( pair<string,string>("Õ","O") );

    dictionary.insert ( pair<string,string>("ú","u") );
    dictionary.insert ( pair<string,string>("ù","u") );
    dictionary.insert ( pair<string,string>("û","u") );
    dictionary.insert ( pair<string,string>("ü","u") );

    dictionary.insert ( pair<string,string>("Ú","U") );
    dictionary.insert ( pair<string,string>("Ù","U") );
    dictionary.insert ( pair<string,string>("Û","U") );
    dictionary.insert ( pair<string,string>("Ü","U") );

    dictionary.insert ( pair<string,string>("ñ","n") );
    dictionary.insert ( pair<string,string>("Ñ","N") );

    dictionary.insert ( pair<string,string>("ç","c") );
    dictionary.insert ( pair<string,string>("Ç","C") );

    dictionary.insert ( pair<string,string>("ý","y") );
    dictionary.insert ( pair<string,string>("Ý","Y") );

    string new_str;

    for (auto it = dictionary.begin(); it != dictionary.end(); it++){
        size_t index = 0;
        while (true) {
            /* Locate the substring to replace. */
            index = in.find(it->first, index);
            if (index == std::string::npos) break;

            /* Make the replacement. */
            in.replace(index, 2, it->second);

            /* Advance index forward so the next iteration doesn't pick it up as well. */
            index += 2;
        }
    }

    for (char c : in){

        c = toupper(c);

        if ( ((c >= 'A') && (c <= 'Z')) || ((c >= '0') && (c <= '9')) ){
            new_str += c;
        }

        if ( (c == ' ') && (new_str.back() != ' ') ){
            new_str += c;
        }

    }

    if (new_str.back() == ' '){
        new_str.pop_back();
    }

    return new_str;
}

bool contains(list<int> list, int value){
    for (int element : list){
        if (element == value){
            return true;
        }
    }
    return false;
}
