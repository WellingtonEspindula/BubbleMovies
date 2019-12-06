#include "../../header/model/rating.h"


Rating::Rating(){
    this->movieId = -1;
    this->userId = -1;
    this->rating = -1;
    this->timestamp = "";
}

Rating::Rating(string csv){
    fromCsv(csv);
}

void Rating::fromCsv(string csv) {
    // userId,movieId,rating,timestamp
    vector<string> entries = split_csv(csv, ',');
    this->userId = stoi(entries.at(0));
    this->movieId = stoi(entries.at(1));
    this->rating = stod(entries.at(2));
    this->timestamp = entries.at(3);
}
