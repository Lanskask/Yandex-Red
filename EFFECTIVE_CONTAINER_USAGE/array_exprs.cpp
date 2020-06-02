#include<iostream>
#include<vector>
#include<tuple>
#include<array>
#include<algorithm>

#include "../CODE_OPTIMISATION/profiler.h"

using namespace std;

vector<int> BuildVector(int i) {
    return {i, i+1, i+2, i+3, i+4};
}

tuple<int, int, int, int, int> BuildTuple(int i) {
    return make_tuple(i, i+1, i+2, i+3, i+4);
}

array<int, 5> BuildArray(int i) {
    return {i, i+1, i+2, i+3, i+4};
}

const int COUNT = 1'000'000;

void Run1() {
    {
        LOG_DURATION("vector");
        for(int i = 0; i < COUNT; ++i) {
            auto numbers = BuildVector(i);
        }
    }
    {
        LOG_DURATION("tuple");
        for(int i = 0; i < COUNT; ++i) {
            auto numbers = BuildTuple(i);
        }
    }
    {
        LOG_DURATION("array");
        for(int i = 0; i < COUNT; ++i) {
            auto numbers = BuildArray(i);
            sort(begin(numbers), end(numbers));
        }
    }
}

void Run2() {
    int x = 111111;
    array<int, 10> numbers;
    numbers.fill(8);
    const auto numbers_copy = numbers;
    int y = 222222;

    for(int* p = &y; p <= &x; ++p) {
        cout << *p << " ";
    }
    for(const auto& d : numbers) {
        cout << d << ", ";
    }
    cout << endl;
}

int main() {
//    Run1();
    Run2();

    return EXIT_SUCCESS;
}