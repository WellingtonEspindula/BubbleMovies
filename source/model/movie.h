
#ifndef BUBBLE_MOVIES_MOVIE_H
#define BUBBLE_MOVIES_MOVIE_H

#include <algorithm>
#include <bits/stdc++.h>
#include "rating.h"
#include "user.h"
#include "tag.h"
#include "../interfaces/comparable.h"
#include "../interfaces/hashable.h"
#include "../utils/stringHashable.h"
#include "../utils/intHC.h"
#include "../utils/utils.h"
#include "../utils/sort.h"

using namespace std;

class Movie : Comparable<Movie> {
    public:
        int movieId;
        string title;
        vector<string> genres;
        int ratings_count;
        float ratings_sum;
    
    public:
        Movie();
        Movie(string csv);
        Movie(int movieId, string title, int ratings_count, float ratings_sum);
        void addGenres(string genre);
        void addRating(Rating* rating);
        float globalRating();
        bool hasGenre(string genre);
        void fromCsv(string csv);
        float compare(Movie element) override ;
        friend ostream& operator<<(ostream& os, const Movie& dt);
        bool operator==(const Movie& rhs);
        bool operator>(const Movie& rhs);
        bool operator>=(const Movie& rhs);
        bool operator<(const Movie& rhs);
        bool operator<=(const Movie& rhs);

};

#endif //BUBBLE_MOVIES_MOVIE_H