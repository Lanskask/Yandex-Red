#include<iostream>
using namespace std;

void second() {
//    int s_a = 1;
//    double s_d = 2.0;
    int s_a;
    double s_d;
    cout << "s_a: " << s_a << "; s_d: " << s_d << endl;
}

void first() {
    int f_a = 2;
    char f_c = 'a';
    second();
}


int main(int argc, char *argv[]) {
    int a = 1;
    char c = 'z';
    first();
    second();
    a = 2;
    c = 'q';

    return EXIT_SUCCESS;
}