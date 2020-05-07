#ifndef BUBBLE_MOVIES_COMPARABLE_H
#define BUBBLE_MOVIES_COMPARABLE_H

using namespace std;

/** \brief Interface to compare() method */
template <typename C>
class Comparable{
public:
    virtual float compare(C element) = 0;
};

#endif