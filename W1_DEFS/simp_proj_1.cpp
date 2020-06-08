#define MY_MAIN int main()
#define FINISH return 0

#include<iostream>
#include<string>
#include<iomanip>
#include<queue>

#include "header1.h"

using namespace std;

#define AS_KV(x) #x << " = " << x << endl

//void PrintQueue(queue<int> que) {
//    for(const auto& x : que) {
//        cout << x << ", ";
//    }
//    cout << endl;
//}

void QueueTest() {
    queue<int> que1;
    que1.push(1);
    que1.push(2);
    que1.push(3);
    cout << "que1.back() 1: " << que1.back() << endl;


    cout << "que1.front() 1: " << que1.front() << endl;
    que1.pop();

    cout << "que1.front() 2: " << que1.front() << endl;
}

void Main1() {
    int x = 4;
    string t = "hello";
    bool isTrue = true;

    cerr << boolalpha;
    cerr
            << AS_KV(x)
            << AS_KV(t)
            << AS_KV(isTrue) << endl;
}

void Main2() {
    header1::Struct1 s1{1, {1,2,3}};
    cout << s1.val1 << endl;
    for(const int& x : s1.vect1) {
        cout << x << ", ";
    }
    cout << endl;
}

MY_MAIN {
//    QueueTest();
    Main2();

    FINISH;
}