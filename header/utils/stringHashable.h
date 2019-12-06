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

class StringHashable : public string, public Hashable, public Comparable<StringHashable> {
public:
    StringHashable(string s);

    /** \brief Compare this string with an string entered.
     * @param element String to be compared to.
     * @return Returns if this is string has the ASCII code greater than the @element ASCII
     */
    int compare(StringHashable element) override;

    bool operator==(const StringHashable& rhs);

    /** \brief Returns the Horner method for hashing strings */
    int hashCode(int table_size) override;
};