
#ifndef BUBBLE_MOVIES_STRINGHC_H
#define BUBBLE_MOVIES_STRINGHC_H

#include <algorithm>
#include <bits/stdc++.h>
#include "../interfaces/comparable.h"
#include "../interfaces/hashable.h"

using namespace std;

class stringHC : public string, public Hashable, public Comparable<stringHC> {
public:
    stringHC();

    stringHC(string s);

    /** \brief Compare this string with an string entered.
     * @param element String to be compared to.
     * @return Returns if this is string has the ASCII code greater than the @element ASCII
     */
    float compare(stringHC element) override;

    bool operator==(const stringHC& rhs);

    /** \brief Returns the Horner method for hashing strings */
    int hashCode(int table_size) override;
};

#endif //BUBBLE_MOVIES_STRINGHC_H