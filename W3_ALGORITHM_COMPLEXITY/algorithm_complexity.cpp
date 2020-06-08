#include<iostream>
#include<deque>
#include<vector>
#include<set>
#include<algorithm>
#include "../CODE_OPTIMISATION/profiler.h"

using namespace std;

void Run1() {
    set<int> numbers;
    for (int i = 0; i < 3000000; ++i) {
        numbers.insert(i);
    }
    const int x = 1000000;

    {
        LOG_DURATION("global lower_bound");
        cout << *lower_bound(begin(numbers), end(numbers), x);
    }
    {
        LOG_DURATION("set lower_bound");
        cout << *numbers.lower_bound(x);
    }
}

const int NUMBER_COUNT =   1'000'000;
const int NUMBER = 7'654'321;
const int QUERY_COUNT = 10;

void Run3() {
    vector<int> v;
    for (int i = 0; i < NUMBER_COUNT; ++i) {
        v.push_back(i * 10);
    }

    {
        LOG_DURATION("lower_bound");
        for (int i = 0; i < QUERY_COUNT; ++i) {
            lower_bound(v.begin(), v.end(), NUMBER);
        }
    }
    {
        LOG_DURATION("find_if");
        for (int i = 0; i < QUERY_COUNT; ++i) {
            find_if(v.begin(), v.end(), [](const int& x) {
                return x >= NUMBER;
            });
        }
    }
}

int main(int argc, char *argv[]) {
//    Run1();
    Run3();

    return EXIT_SUCCESS;
}