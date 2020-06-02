#include<iostream>
#include<cassert>
#include <vector>

using namespace std;

template <typename T>
size_t MaxSeqLengs(vector<T> vect, T numb) {
//    if(vect.empty()) return 0;
    size_t maxSeqLengs = 0;
    size_t curSeqLength = 0;
    for(T x : vect) {
        if (x==numb) {
            curSeqLength++;
//            maxSeqLengs = curSeqLength > maxSeqLengs ? curSeqLength : maxSeqLengs;
            maxSeqLengs = max(curSeqLength, maxSeqLengs);
        } else { //(x!=numb)
            curSeqLength = 0;
        }
    }
    return maxSeqLengs;
}


int main(int argc, char *argv[]) {
    vector<int> v1 = {1,1,0,1,1,1};
    vector<int> v2 = {1,1,0,1,1};
    vector<int> v3 = {1,1,1};
    vector<int> v4 = {1};
    vector<int> v5 = {0};
    vector<int> v6 = {};

    vector<vector<int>> allTestVects = { v1,v2,v3,v4,v5,v6 };
    vector<int> expected = {3,2,3,1,0,0};

//    for (int i = 0; i < allTestVects.size(); ++i) {
//        int maxLen = MaxSeqLengs(allTestVects[i] ,1);
//        cout << "Max len: " << maxLen << endl;
//        assert(maxLen == expected[i]);
//    }

    int maxLen = MaxSeqLengs(v6 ,1);
    cout << "Max len: " << maxLen << endl;

    return EXIT_SUCCESS;
}