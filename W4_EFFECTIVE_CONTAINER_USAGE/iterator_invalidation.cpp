#include<iostream>
#include<vector>
#include<deque>
//#include "../W2_CODE_OPTIMISATION/profiler.h"

using namespace std;

void Run1() {
//    vector<int> numbers = {1};
    deque<int> numbers = {1};
    auto it = numbers.begin();

    cout << *it << endl;
    for (int i = 0; i < 2000; ++i) {
        numbers.push_back(i);
    }
    cout << *it << " | " << *(it + numbers.size() - 1)<< endl;
}

int main(int argc, char *argv[]) {
    Run1();

    return EXIT_SUCCESS;
}