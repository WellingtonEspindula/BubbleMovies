#ifndef LIBS
#define LIBS
#include <algorithm>
#include <bits/stdc++.h>
#endif

#include "../../header/model/movie.h"

Movie::Movie(){
    this->genres = vector<string>();
    this->ratings_count = 0;
    this->ratings_sum = 0;
}

Movie::Movie(string csv){
    this->genres = vector<string>();
    this->ratings_count = 0;
    this->ratings_sum = 0;
    fromCsv(csv);
}

Movie::Movie(int movieId, string title, int ratings_count, float ratings_sum){
    this->movieId = movieId;
    this->title = title;
    this->genres = vector<string>();
    this->ratings_count = 0;
    this->ratings_sum = 0;
}

void Movie::addGenres(string genre){
    this->genres.push_back(genre);
}

void Movie::addRating(Rating* rating){
    ratings_count++;
    ratings_sum += rating->rating;
}

void Movie::fromCsv(string movie_csv) {
    // "movieId","title","genres"
    vector<string> entries = split_csv(movie_csv, ',');
    this->movieId = stoi(entries.at(0));
    this->title = entries.at(1);
    this->genres = split(entries.at(2), "|");
}

ostream& operator<<(ostream& os, const Movie& dt){
    return os << dt.title;
}

float Movie::globalRating() {
    return ratings_sum/ratings_count;
}

bool Movie::hasGenre(string genre){
    for (string movie_genre : genres){
        if (clear_string(movie_genre) == genre){
            return true;
        }
    }
    return false;
}

string Movie::getGenres(){
    string buffer = "";
    for (string genre : this->genres){
        buffer += genre + "|";
    }
    buffer.pop_back();
    return buffer;
}

float Movie::compare(Movie element) {
    // TODO Maybe improve this method later
    return this->globalRating() - element.globalRating();
}

bool Movie::operator==(const Movie &rhs) {
    return this->compare(rhs) == 0;
}

bool Movie::operator>(const Movie &rhs) {
    return this->compare(rhs) > 0;
}

bool Movie::operator>=(const Movie &rhs) {
    return this->compare(rhs) >= 0;
}

bool Movie::operator<(const Movie &rhs) {
    return this->compare(rhs) < 0;
}

bool Movie::operator<=(const Movie &rhs) {
    return this->compare(rhs) <= 0;
}
