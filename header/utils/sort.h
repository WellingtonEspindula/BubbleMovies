#ifndef LIBS
#define LIBS
#include <algorithm>
#include <bits/stdc++.h>
#endif

using namespace std;

/** \brief Default Insertion Sort
 *
 *  \param vector - Input vector to be sorted
 *  \param size - Size of the vector
 */
template <typename T>
void insertion_sort(T* vector[], int size);

/** \brief Default Top Down Merge Sort
 *
 *  \param vector - Input vector to be sorted
 *  \param size - Size of the vector
 */
template <typename T>
void merge_sort(T* vector[], int size);

/** \brief Hybrid Sort is an Top Down Merge sort using, as optimization,
 * Insertion Sort in some sublists
 *
 *  \param vector - Input vector to be sorted
 *  \param size - Size of the vector
 */
template <typename T>
void hybrid_sort(T* vector[], int size);



#include "../../source/utils/sort.ipp"