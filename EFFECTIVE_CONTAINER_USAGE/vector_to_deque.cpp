#include<iostream>
#include<algorithm>
#include<deque>
#include<vector>
#include "../CODE_OPTIMISATION/profiler.h"

using namespace std;

void Run1() {
    const int SIZE = 10'000'000;

    vector<int> v;
    {
        LOG_DURATION("vector");
        for (int i = 0; i < SIZE; ++i) {
            v.push_back(i);
        }
    }

    deque<int> d;
    {
        LOG_DURATION("deque");
        for (int i = 0; i < SIZE; ++i) {
            d.push_back(i);
        }
    }
    {
        LOG_DURATION("sort_vector");
        sort(rbegin(v), rend(v));
    }
    {
        LOG_DURATION("sort_deque");
        sort(rbegin(d), rend(d));
    }
}

int main(int argc, char *argv[]) {
    Run1();

    return EXIT_SUCCESS;
}