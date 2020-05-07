//
// Created by wellington on 15/12/2019.
//

#ifndef BUBBLE_MOVIES_API_H
#define BUBBLE_MOVIES_API_H

#include <algorithm>
#include <bits/stdc++.h>
#include "model/rating.h"
#include "model/user.h"
#include "model/movie.h"
#include "model/tag.h"
#include "interfaces/comparable.h"
#include "interfaces/hashable.h"
#include "utils/stringHashable.h"
#include "utils/intHC.h"
#include "utils/utils.h"
#include "utils/sort.h"
#include "datastructures/hash.h"
#include "datastructures/tst.h"

typedef struct {
    HashTable<IntHC, Movie> *movieHT;
    TST *movieTST;
    HashTable<stringHC, vector<Movie*>> *genres;
    HashTable<IntHC, User> *userHT;
    HashTable<stringHC, list<int>> *tagHT;
} structures_handler;

structures_handler load(const string &movie_file, const string &ratings_file, const string &tag_file);
void query(const structures_handler &structures, const string &query);
void log(const string &log_msg);
void alert(const string &msg);

#endif //BUBBLE_MOVIES_API_H
