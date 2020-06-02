#include<iostream>
#include<string>
#include<array>
#include<vector>
#include<utility>

#include "../CODE_OPTIMISATION/profiler.h"

using namespace std;

const int SIZE = 10'000;

array<int, SIZE> MakeArray() {
    array<int, SIZE> a;
    a.fill(8);
    return a;
}

// Run Functions
void Run1() {
    {
        LOG_DURATION("with variable");
        vector<array<int, SIZE>> arrays;
        for (int i = 0; i < 20'000; ++i) {
            auto heavy_array = MakeArray();
            arrays.push_back(heavy_array);
        }
    }
    {
        LOG_DURATION("direct to variable");
        vector<array<int, SIZE>> arrays;
        for (int i = 0; i < 20'000; ++i) {
            arrays.push_back(MakeArray());
        }
    }
}

string MakeString() {
    return "C++";
}

void Run2() {
    vector<string> strings;
    const string s = MakeString();
    cout << s << "\n";
    strings.push_back(move(s));
    cout << s << "\n";
}


int main() {
//    Run1();
    Run2();

    return EXIT_SUCCESS;
}