//
// Created by wellington on 07/12/2019.
//

#include "../../header/model/tag.h"

Tag::Tag() {
    this->movieId = -1;
}

Tag::Tag(string csv) {
    this->movieId = -1;
    this->tag = "";
    fromCsv(csv);
}

void Tag::fromCsv(string csv) {
//    "userId","movieId","tag","timestamp"
    vector<string> entries = split_csv(csv, ',');
    this->tag = clear_string(entries.at(2));
    this->movieId = stoi(entries.at(1));
}