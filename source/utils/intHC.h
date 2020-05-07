//
// Created by wellington on 30/11/2019.
//

#ifndef BUBBLE_MOVIES_INTHC_H
#define BUBBLE_MOVIES_INTHC_H

#include <algorithm>
#include <bits/stdc++.h>
#include "../interfaces/comparable.h"
#include "../interfaces/hashable.h"

using namespace std;

class IntHC : public Hashable, public Comparable<IntHC>{
public:
    int i;

    IntHC();

    IntHC(int i);

    float compare(IntHC element) override ;

    bool operator==(const IntHC& rhs);
    friend ostream& operator<<(ostream& os, const IntHC& dt);

    int hashCode(int table_size) override ;
};

#endif //BUBBLE_MOVIES_INTHC_H
