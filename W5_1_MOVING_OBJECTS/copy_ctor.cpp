#include<iostream>
#include<string>
#include<vector>
#include<utility>

#include "../CODE_OPTIMISATION/profiler.h"

using namespace std;


class Logger {
public:
    Logger() { cout << "Default ctor" << endl; }

//    Logger(const Logger &) { cout << "Copy ctor" << endl; }
    Logger(const Logger &) = delete; // { cout << "Copy ctor" << endl; }
    Logger(Logger&&) { cout << "Move ctor" << endl; }

    void operator=(const Logger &) { cout << "Copy aaasignement" << endl; }
};

template<typename T>
ostream &operator<<(ostream &os, const vector<T> &vect) {
    for (auto it = vect.begin(); it != vect.end(); ++it) {
        cout << *it << ", ";
    }
    return os;
}

//void Run1() {
//    Logger source;
//    Logger target = source;
//
//    vector<Logger> loggers;
//    loggers.push_back(source);
//
//    source = target;
//}

void MyTest1() {
    vector<int> a{1,2,3};
    vector<int> b{1,2,3};
    a[1] = 3;
    cout << (a == b) << endl;
    cout << a << endl;
    cout << b << endl;
}

void TestMoveCtor() {
    Logger logger1;
    Logger logger2 = move(logger1);
}

Logger MakeLogger() {
//    // Var 1
//    // copy elision
//    return Logger(); // function input temporal -> returned temporal

    // Var 2
    Logger log;
    // ...
    // named return value optimization
    return log; // returned local variable
}
void CopyElisionTest() {
    // copy elision
    Logger log = MakeLogger(); // temporal -> variable
}

int main() {
//    Run1();
//    MyTest1();
    TestMoveCtor();

    return EXIT_SUCCESS;
}