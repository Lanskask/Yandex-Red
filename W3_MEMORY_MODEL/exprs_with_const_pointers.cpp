#include<iostream>

using namespace std;

void Run1() {
    int x = 5;
    int x_mock = 7;
    int* b = &x;

    // не можем менять значение переменной через этот указатель
    // на которую ссылается этот указатель
    // но можем переставлять тот указатель на другую переменную
    // этот указатель не позволяет менять через себя значение
    const int* c = &x;
//    *c = 6; // not allowed
    cout << "const int* c = &x; x = 6;: " << *c << endl;

    // не можем менять указатель
    // (переставлять указатель на другой адрес)
    // присваиветь указателю адресс другой переменной
    int* const d = &x;
//    d = &x_mock;

    const int* const e = &x;
    int const* const f = &x;
    int const* g = &x; // не можем менять значеия
//    *g = 8;
}

int main(int argc, char *argv[]) {
    Run1();

    return EXIT_SUCCESS;
}