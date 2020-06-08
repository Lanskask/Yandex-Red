#include <vector>
#include<iostream>
#include <set>
#include <queue>

using namespace std;

template<typename Iterator>
class IteratorRange {
private:
    Iterator first, last;

public:
    IteratorRange(Iterator first_, Iterator last_) :
        first(first_), last(last_) {}

    Iterator begin() const {
        return first;
    }

    Iterator end() const {
        return last;
    }
};


//template<typename Iterator>
//struct IteratorRange {
//    Iterator first, last;
//
//    Iterator begin() const {
//        return first;
//    }
//
//    Iterator end() const {
//        return last;
//    }
//};

template<typename T>
//vector<T> Head(vector<T>& v, size_t top) {
IteratorRange<typename vector<T>::iterator> Head(vector<T> &v, size_t top) {
    return {v.begin(), next(v.begin(), min(top, v.size()))};
}

template<typename Collection>
//vector<T> Head(vector<T>& v, size_t top) {
IteratorRange<typename Collection::iterator> HeadColl(Collection &v, size_t top) {
    return {v.begin(), next(v.begin(), min(top, v.size()))};
}

template<typename Collection>
//vector<T> Head(vector<T>& v, size_t top) {
auto HeadCollAuto(Collection &v, size_t top) {
    return IteratorRange{v.begin(), next(v.begin(), min(top, v.size()))};
}

template<typename Iterator>
IteratorRange<Iterator> MakeRange(
        Iterator begin, Iterator end
) {
    return IteratorRange<Iterator>{begin, end};
}

template <typename Iterator>
void PrintIterator(Iterator it) {
    for(const auto& x : it) {
        cout << x << ", ";
    }
    cout << endl;
}

void Test1() {
    vector<int> v = {1, 2, 3, 4, 5};
    for (int &x : Head(v, 3)) {
        ++x;
    }
//    for(int x : Head(v, 3)) {
//    for (int x : v) {
//        cout << x << ' ';
//    }
}

void Test2() {
    vector<int> v = {1, 2, 3, 4, 5};

//    IteratorRange<vector<int>::iterator> second_half{
//            v.begin() + v.size() / 2, v.end()
//    };
    auto second_half = MakeRange(
            v.begin() + v.size() / 2, v.end()
    );

    for(const auto& x : second_half) {
        cout << x << " ";
    }
}

void Test3_Pair() {
    pair p('a', 5);
    cout << p.second << endl;
}

void Test4_Type_Incestion() {
    vector<int> v = {1, 2, 3, 4, 5};
//    IteratorRange<vector<int>::iterator> second_half{
//            v.begin() + v.size() / 2, v.end()
//    };
    IteratorRange second_half = {
            v.begin() + v.size() / 2, v.end()
    };
    for(const auto& x : second_half) {
        cout << x << ", ";
    }
    cout << endl;
}

void Test5() {
    // Set
    set<int> set1 = {5,7,12,8,10,5,6,1};
    cout << "Set: " << endl;
    PrintIterator(HeadColl(set1,3));

    // Deque
    const deque<int> deque1 = {5,7,12,8,10,5,6,1};
    cout << "Dequeue: " << endl;
    PrintIterator(HeadCollAuto(deque1,3));
}

int main(int argc, char *argv[]) {
//    Test1();
//    Test2();
//    Test3_Pair();
//    Test4_Type_Incestion();
    Test5();

    return EXIT_SUCCESS;
}