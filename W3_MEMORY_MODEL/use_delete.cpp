#include<iostream>
#include <random>

using namespace std;

struct Widjet {
    Widjet() {
        cout << "constructor" << endl;
    }
    ~Widjet() {
        cout << "destructor" << endl;
    }
};

void Run1() {
    int n;
    cout << "Enter how much random numbers to sum: ";
    cin >> n;

    mt19937_64 random_gen;
    uint64_t sum = 0;
    for(int i = 0; i < n; ++i) {
        auto x = new uint64_t;
        *x = random_gen(); // записываем в место по указателю *x значение из random_gen
        sum += *x;
        delete x;
    }
    cout << sum << endl;
}

void Run2() {
    Widjet* w1 = new Widjet;
    delete w1;
}

int main(int argc, char *argv[]) {
//    Run1();
    Run2();

    return EXIT_SUCCESS;
}