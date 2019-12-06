using namespace std;

/** \brief Interface to hashCode() method */
class Hashable{
public:
    virtual int hashCode(int table_size) = 0;
};