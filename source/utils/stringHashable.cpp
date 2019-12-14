#include "../../header/utils/stringHashable.h"

#define P 257

StringHashable::StringHashable(){
}

StringHashable::StringHashable(string s){
    this->assign(s);
}

int StringHashable::hashCode(int table_size){
//    cout << this->data() << " : " << table_size;
    int hash = 0;
    for (int i = 0; i < length(); i++){
        hash = ((P * hash + at(i)) % table_size);
    }
//    cout << " : " << hash << endl;
    return hash;
}

int StringHashable::compare(StringHashable element) {
    return strcmp(this->c_str(), element.c_str());
}

bool StringHashable::operator==(const StringHashable& rhs){
    return this->compare(rhs) == 0;
}
