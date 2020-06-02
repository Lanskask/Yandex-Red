#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
#include<future>

using namespace std;

int SumToVectors(const vector<int>& one, const vector<int>& two) {
//    return accumulate(begin(one), end(one), 0)
//        + accumulate(begin(two), end(two), 0);
    future<int> f = async([&] {
        return accumulate(begin(one), end(one), 0);
    });
    int result = accumulate(begin(two), end(two), 0);
    return result + f.get();
}

void Run1() {
    cout << SumToVectors({1,1,1,1}, {3,3,3}) << endl;
}

int main() {
    Run1();

    return EXIT_SUCCESS;
}