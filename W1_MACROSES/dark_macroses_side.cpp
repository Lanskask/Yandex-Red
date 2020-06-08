#include<iostream>

using namespace std;

//#define MAX(a, b) a > b ? a : b
#define MAX(a, b) (a > b ? a : b)

//#define SQR(x) (x*x)
#define SQR(x) ((x)*(x))

int LogAndReturn(int x) {
    cout << "x = " << x << endl;
    return x;
}

void TestMax() {
    int x = 4;
    int y = 2;
    int z = MAX(x,y) + 5;
    cout << z << endl;
}

void TestSqr() {
    int x = 3;
//    int z = SQR(x + 1);
    int y = LogAndReturn(x + 1);
    int z = SQR(y);
    cout << z << endl;
}

int main() {
//    TestMax();
    TestSqr();

    return EXIT_SUCCESS;
}