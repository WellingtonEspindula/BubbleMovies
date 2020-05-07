
#ifndef BUBBLE_MOVIES_RATING_H
#define BUBBLE_MOVIES_RATING_H

#include <algorithm>
#include <bits/stdc++.h>
#include "../utils/utils.h"

using namespace std;

class Rating {
public:
        int movieId;
        int userId;
        double rating;
        string timestamp;

        Rating();
        Rating(string csv);
        void fromCsv(string csv);
};

#endif //BUBBLE_MOVIES_RATING_H
