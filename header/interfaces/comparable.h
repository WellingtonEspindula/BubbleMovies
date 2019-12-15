using namespace std;

/** \brief Interface to compare() method */
template <typename C>
class Comparable{
public:
    virtual float compare(C element) = 0;
};