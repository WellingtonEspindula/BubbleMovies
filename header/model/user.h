#ifndef LIBS
#define LIBS
#include <algorithm>
#include <bits/stdc++.h>
#endif

#ifndef MODELS
#define MODELS
#include "../../header/model/rating.h"
#include "../../header/model/movie.h"
#endif

using namespace std;

class User {
    public:
        int userId;
        list<Rating> ratings;

        User(int userId);
        void addRating(Rating rating);
        friend ostream& operator<<(ostream& os, const User& dt);
};

