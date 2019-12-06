#ifndef LIBS
#define LIBS
#include <algorithm>
#include <bits/stdc++.h>
#endif

#ifndef UTILS
#define UTILS
#include "../../header/utils/stringHashable.h"
#include "../../header/utils/intHC.h"
#include "../../header/utils/utils.h"
#endif


using namespace std;

class Rating {
public:
        int movieId;
        int userId;
        double rating;
        string timestamp;

        Rating();
        Rating(string csv);
        void fromCsv(string csv);
};
