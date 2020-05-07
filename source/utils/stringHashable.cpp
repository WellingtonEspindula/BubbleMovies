#include "stringHashable.h"

#define P 257

stringHC::stringHC(){
}

stringHC::stringHC(string s){
    this->assign(s);
}

int stringHC::hashCode(int table_size){
//    cout << this->data() << " : " << table_size;
    int hash = 0;
    for (int i = 0; i < length(); i++){
        hash = ((P * hash + at(i)) % table_size);
    }
//    cout << " : " << hash << endl;
    return hash;
}

float stringHC::compare(stringHC element) {
    return strcmp(this->c_str(), element.c_str());
}

bool stringHC::operator==(const stringHC& rhs){
    return this->compare(rhs) == 0;
}
