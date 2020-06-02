#include<iostream>
#include<vector>
#include "../CODE_OPTIMISATION/profiler.h"

using namespace std;

void LogVectorParams(const vector<int>& v) {
    cout
        << "Length: " << v.size()
        << "; Capacity: " << v.capacity()
        << '\n';
    int const* data = v.data();
    cout << "data[0]: " << data[0] << endl;
    for (int i = 0; i < v.capacity(); ++i) {
        cout << data[i] << ", ";
    }
    cout << endl;
}

void Run1() {
    vector<int> v = {1,2,3};
//    LogVectorParams(v);
    v.push_back(4);
    LogVectorParams(v);
    v.shrink_to_fit();
    LogVectorParams(v);
}

void Run2() {
    int size;

    {
        cout << "LG1: Enter size: ";
        cin >> size;
        vector<int> v;
        LOG_DURATION("push_back");
        for (int i = 0; i < size; ++i) {
            v.push_back(i);
        }
    }
    {
        cout << "LG1: Enter size: ";
        cin >> size;
        vector<int> v1;
        v1.reserve(size);
        LOG_DURATION("push_back");
        for (int i = 0; i < size; ++i) {
            v1.push_back(i);
        }
    }
}

void Run3_Ref_Invalidation() {
    vector<int> v = {1,2,3};
    int& first = v[0];
    cout << first << endl;
    v.push_back(4);
    cout << first << endl;
}

int main(int argc, char *argv[]) {
//    Run1();
//    Run2();
    Run3_Ref_Invalidation();

    return EXIT_SUCCESS;
}