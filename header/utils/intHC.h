//
// Created by wellington on 30/11/2019.
//

#ifndef BUBBLE_MOVIES_INTHC_H
#define BUBBLE_MOVIES_INTHC_H

#ifndef LIBS
#define LIBS
#include <algorithm>
#include <bits/stdc++.h>
#endif

#ifndef INTERFACES
#define INTERFACES
#include "../../header/interfaces/comparable.h"
#include "../../header/interfaces/hashable.h"
#endif

using namespace std;

class IntHC : public Hashable, public Comparable<IntHC>{
public:
    int i;

    IntHC();

    IntHC(int i);

    int compare(IntHC element) override ;

    bool operator==(const IntHC& rhs);
    friend ostream& operator<<(ostream& os, const IntHC& dt);

    int hashCode(int table_size) override ;
};

#endif //BUBBLE_MOVIES_INTHC_H
