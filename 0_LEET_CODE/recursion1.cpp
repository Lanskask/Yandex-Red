#include <iostream>
#include <vector>
#include <string>

using namespace std;

void reverseString(vector<char>& s) {
    size_t size = s.size();

    for(int i = 0; i < size/2; i++) {
        char tmp = s[i]; //s[size - 1 - i];
        s[i] = s[size - 1 - i];
        s[size - 1 - i] = tmp;
    }
}
void Run1() {
    vector<char> v = {'1','2','3','4','5'};
    reverseString(v);
    for(char x : v) {
        cout << x << ", ";
    }
    cout << endl;
}


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* swapPairs(ListNode* head) {

}

int rec_sum(const vector<int>& v, int sum_, int index) {
    if(index >= v.size()) {
        return sum_;
    } else {
        rec_sum(v, sum_ + v[index-1], ++index);
    }
}
void Run2_rec_sum() {
    vector<int> v1 = {1,2,3};
    cout << rec_sum(v1, 0, 0) << endl;
}


pair<int, vector<int>> HeadTail(vector<int>& v) {
    return {v.front(), vector<int>(v.begin() + 1, v.end())};
}

int main() {
//    Run1();
    Run2_rec_sum();

    return 0;
}