#ifndef LIBS
#define LIBS
#include <algorithm>
#include <bits/stdc++.h>
#endif

#ifndef MODELS
#define MODELS
#include "../../header/model/rating.h"
#include "../../header/model/user.h"
#include "../../header/model/tag.h"
#endif

#ifndef UTILS
#define UTILS
#include "../../header/utils/stringHashable.h"
#include "../../header/utils/intHC.h"
#include "../../header/utils/utils.h"
#endif


using namespace std;

class Movie {
    public:
        int movieId;
        string title;
        vector<string> genres;
        int ratings_count;
        float ratings_sum;
    
    public:
        Movie();
        Movie(string csv);
        Movie(int movieId, string title, int ratings_count, unsigned long long int ratings_sum);
        void addGenres(string genre);
        void addRating(Rating* rating);
        void fromCsv(string csv);
        friend ostream& operator<<(ostream& os, const Movie& dt);
};
