#include<iostream>
#include<string>
#include<vector>
#include<utility>

#include "../CODE_OPTIMISATION/profiler.h"

using namespace std;

struct Struct {
    Struct() {}
    Struct(int int_vaL_, vector<int> vect_)
        : int_val(int_vaL_), vector_int(vect_) {}
    int int_val;
    vector<int> vector_int;
};

template <typename T>
ostream& operator<<(ostream& os, vector<T> vector) {
    os << "{ ";
    for(const T& x : vector) {
        os << x << ", ";
    }
    os << "}" << endl;
}

ostream& operator<<(ostream& os, const Struct& strct) {
    os << "{ ";
    os << strct.int_val << " : ";
    for(const int& x : strct.vector_int) {
        os << x << ", ";
    }
    os << "}" << endl;
    return os;
}

void Run1() {
    Struct str1{1, {1, 2}};
    Struct str2 = str1;
//    cout << str2.int_val << ": " << str1.vector_int << endl;
    cout << "str1: " << str1 << endl;

    cout << "----" << endl;

    Struct& str2_ref = str1;
    Struct& str3_ref = str2_ref;
    cout << "str1: " << str1 << endl;
    cout << "str2_ref: " << str2_ref << endl;
    cout << "str3_ref: " << str3_ref << endl;
    str3_ref.int_val = 5;
    cout << "str1: " << str1 << endl;
    cout << "str2_ref: " << str2_ref << endl;
    cout << "str3_ref: " << str3_ref << endl;
}


int main() {
    Run1();

    return EXIT_SUCCESS;
}