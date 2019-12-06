using namespace std;

/** \brief Interface to compare() method */
template <typename C>
class Comparable{
public:
    virtual int compare(C element) = 0;
};