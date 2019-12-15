#ifndef LIBS
#define LIBS
#include <algorithm>
#include <bits/stdc++.h>
#endif

#ifndef UTILS
#define UTILS
#include "../../header/utils/stringHashable.h"
#include "../../header/utils/intHC.h"
#include "../../header/utils/utils.h"
#include "../../header/utils/sort.h"
#endif

//TST.h
#ifndef TST_H
#define TST_H
//#define DEBUG_PROGRAM_MEMORY

using namespace std;

//Node of a Ternary Search Tree
class Node {
public:
    char character;        // Actual data stored in form of character
    int id = -1;           // flag marking end of string
    struct Node* left;     // All character data less than this node
    struct Node* eq;       // All character data equal to this node
    struct Node* right;    // All character data greater than this node

};

// The Ternary Search Tree itself
class TST{
public:
    int size;
    struct Node* root;      // Root node

    /** \brief Default constructor */
    TST();

    /** \brief Inserts the name of the movie in the TST
     * \param str - string to be inserted
     */
    bool insert(string str, int id);

    /** \brief Prints all the titles stored in the TST
     *
     */
    void show();

    /** \brief Prints stats about TST
     *
     */
    void show_info();

    /** \brief Verify if the string exists in the TST
     * \param str - string to be searched
     */
    bool exists(string str);

    /** \brief Search for a title in TST
    * \param pattern - string to be searched for
    * \return a vector of tuples <string, int> with same prefix
    */
    vector<pair<string, int>> search(string pattern);

    int get(string str);
};

#endif