
#ifndef BUBBLE_MOVIES_USER_H
#define BUBBLE_MOVIES_USER_H

#include <algorithm>
#include <bits/stdc++.h>
#include "rating.h"
#include "movie.h"
#include "tag.h"

using namespace std;

class User {
    public:
        int userId;
        list<Rating*> ratings;

        User(int userId);
        void addRating(Rating* rating);
        friend ostream& operator<<(ostream& os, const User& dt);
};

#endif //BUBBLE_MOVIES_USER_H
