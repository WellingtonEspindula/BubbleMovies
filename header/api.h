//
// Created by wellington on 15/12/2019.
//

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


#ifndef BUBBLE_MOVIES_API_H
#define BUBBLE_MOVIES_API_H

typedef struct {
    HashTable<IntHC, Movie> *movieHT;
    TST *movieTST;
    HashTable<StringHashable, vector<int>> *genres;
    HashTable<IntHC, User> *userHT;
    HashTable<StringHashable, list<int>> *tagHT;
} structures_handler;

structures_handler load(string movie_file, string ratings_file, string tag_file);
void query(structures_handler structures, string query);
void log(string log_msg);
void alert(string msg);

#endif //BUBBLE_MOVIES_API_H
