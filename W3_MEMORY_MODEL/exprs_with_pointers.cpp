#include<iostream>

using namespace std;

void Run3() {
    int x = 5;
    int *y = &x;
    int **z = &y;
    cout << "x y z: " << x << " " << y << " " << z << endl;
    cout << "x *y *z: " << x << " " << *y << " " << *z << endl;
    *y = 7;
    int *b = *z;
    cout << "x y z: " << x << " " << y << " " << z << endl;
    cout << "x *y *z: " << x << " " << *y << " " << *z << endl;
}

void Run4() {
    int a = 43;
    int b = 71;
    int c = 100;
//    cout << b << endl;
//    cout << &b << endl;
//    cout << (&b - 1) << " " << endl;
//    cout << *(&b - 1) << endl;
    cout
            << "*(&b - 1): " << *(&b - 1)
            << "; *(&b + 3): " << *(&b + 3)
            << endl;
    cout
            << "; *(&b): " << *(&b)
            << "; *(&b + 1): " << *(&b + 1)
            << "; *(&b + 2): " << *(&b + 2)
            << endl;
}

void f() {
    int a = 435;
    int b = 711;
    int c = 712;
}

void Run5() {
    int c = 89;
    for (int i = 0; i < 20; ++i) {
        f();
        int x = *(&c - i);
        cout << i << ' ' << x << endl;
    }
}

template <typename T>
void PrintTypePointers(T a) {
    T* c = &a;
    T* d = c + 1;
    cout << c << endl << d << endl;
    cout << sizeof(d - c) << endl;
    cout << "------" << endl;
}

void Run6() {
//    int c = 89;
//    int* d = &c;
//    int* e = d + 1;
//    cout << d << endl << e << endl;
//    cout << (e - d) << endl;
    PrintTypePointers(89);

//    char a1 = 'a';
//    char* b1 = &a1;
//    char* c1 = b1 + 1;
//    cout << b1 << endl << c1 << endl;
//    cout << (c1 - b1) << endl;
    PrintTypePointers('a');

    uint64_t u64 = 5;
    PrintTypePointers(u64);
}

void Run7() {
    int* data = new int[5];
    for (int i = 0; i < 5; ++i) {
        data[i] = 5 + i;
    }
    for (int i = 0; i < 5; ++i) {
        cout << data[i] << ", ";
    }
    cout << endl;
    cout << *data << endl;
    cout << *(data + 5 - 1) << endl;

}

int main(int argc, char *argv[]) {
//    Run3();
//    Run4();
//    Run5();
//    Run6();
    Run7();

    return EXIT_SUCCESS;
}