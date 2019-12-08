//
// Created by wellington on 07/12/2019.
//

#ifndef LIBS
#define LIBS
#include <algorithm>
#include <bits/stdc++.h>
#endif

#ifndef UTILS
#define UTILS
#include "../../header/utils/stringHashable.h"
#include "../../header/utils/utils.h"
#endif

#ifndef MODELS
#define MODELS
#include "../../header/model/rating.h"
#include "../../header/model/user.h"
#include "../../header/model/movie.h"
#include "../../header/model/tag.h"
#endif


#ifndef BUBBLE_MOVIES_TAG_H
#define BUBBLE_MOVIES_TAG_H

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
