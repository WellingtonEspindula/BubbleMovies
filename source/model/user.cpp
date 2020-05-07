#include <bits/stdc++.h>
#include "user.h"

using namespace std;

User::User(int userId) {
    this->userId = userId;
    this->ratings = list<Rating*>();
}

void User::addRating(Rating* rating) {
    this->ratings.push_back(rating);
}

ostream& operator<<(ostream& os, const User& dt){
    string ratings_to_string;
    for (Rating* rating : dt.ratings){
        ratings_to_string += std::to_string(rating->userId);
        ratings_to_string += ":";
        ratings_to_string += std::to_string(rating->movieId);
        ratings_to_string += ":";
        ratings_to_string += std::to_string(rating->rating);
        ratings_to_string += ":";
        ratings_to_string += rating->timestamp;
        ratings_to_string += ";";
    }

    return os << dt.userId << "[" << ratings_to_string << "]" << endl;
}