#include<iostream>
#include<vector>
#include <algorithm>

using namespace std;

void Run1() {
    vector<int> v1 = {1,2,3,4,5,6,7,8,9,10};
    vector<int>::iterator lower_it = lower_bound(v1.begin(), v1.end(), 4);
    cout << *lower_it << endl;
    cout << *next(lower_it) << endl;

    auto upper_it = upper_bound(v1.begin(), v1.end(), 5);
    cout << *upper_it << endl;
    cout << *--upper_it << endl;
}

//void Run2_rbegin_rend() {
//    vector<int> v1 = {1,2,3,4,5,6,7,8,9,10};
//    vector<int>::iterator lower_it = lower_bound(v1.rbegin(), v1.rend(), 4);
//    cout << *lower_it << endl;
//    cout << *next(lower_it) << endl;
//
//    auto upper_it = upper_bound(v1.begin(), v1.end(), 5);
//    cout << *upper_it << endl;
//    cout << *--upper_it << endl;
//}

int main(int argc, char *argv[]) {
    Run1();

    return EXIT_SUCCESS;
}