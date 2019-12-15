//
// Created by wellington on 30/11/2019.
//

#include "../../header/utils/intHC.h"
#define K 31

IntHC::IntHC(){
}

IntHC::IntHC(int i){
    this->i = i;
}

float IntHC::compare(IntHC element) {
    return this->i - element.i;
}

int IntHC::hashCode(int table_size) {
    return (i * K) % table_size;
}

bool IntHC::operator==(const IntHC &rhs) {
    return this->compare(rhs) == 0;
}

ostream &operator<<(ostream &os, const IntHC &intHc) {
    return os << intHc.i;
}

