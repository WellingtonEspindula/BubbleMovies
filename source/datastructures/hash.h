#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

#ifndef BUBBLE_MOVIES_HASH_H
#define BUBBLE_MOVIES_HASH_H

template<class K, class V>
class Pair{
public:
    K first;
    V *second;

    Pair();
    Pair(K first, V *second);
    bool operator==(const Pair& rhs);
};

template<class K, class V>
class HashTable {
public:
    int size;
    int elements_count;
    int collision_count;
    list<Pair<K, V>*> *entries;

    /**
     * \brief Create a new hash table
     * \param size - HashTable's size
     * */
    HashTable(int size);

    /**
    * \brief Destroy the HashTable
    * */
    ~HashTable();

    /**
     * \brief Insert an element into the HashTable
     * \param element - The element to be inserted
     * \return Returns if the insertion was sucessfull
     * */
    bool insert(K key, V *value);

    /**
     * \brief Search an element by its key on the HashTable
     * \param key - The element's key' to be searched
     * \return Returns the value associated with its key
     * */
    V* get(K key);

    /**
     * \brief Remove an element from the HashTable
     * \param key - The element's key to be removed
     * \return Returns if the deletation was sucessfull
     * */
    bool remove(K key);

    /**
     * \brief Calculate the occupation rate on a HashTable 
     * \param table - HashTable to be analyesed
     * \return Returns a number between 0 and 1 that says how much occupied is the HashTable
     * */
    float occupancy_rate();

    /**
     * \brief Show a table and its properties
     * */
    void show();

    /**
     * \brief Show a table's properties
     * */
    void show_info();
};

/* C++ IS SO DUMB... I CAN'T BELIEVE I HAVE TO DO THIS :/ */
#include "hash.ipp"

#endif //BUBBLE_MOVIES_HASH_H