//
// Created by wellington on 07/12/2019.
//

#ifndef BUBBLE_MOVIES_TAG_H
#define BUBBLE_MOVIES_TAG_H

#include <algorithm>
#include <bits/stdc++.h>
#include "../utils/stringHashable.h"
#include "../utils/intHC.h"
#include "../utils/utils.h"
#include "../utils/sort.h"
#include "rating.h"
#include "user.h"
#include "movie.h"
#include "tag.h"


class Tag {
public:
    string tag;
    int movieId;

    // TODO DOC THIS
    Tag();
    Tag(string csv);
    void fromCsv(string csv);
};

#endif //BUBBLE_MOVIES_TAG_H
