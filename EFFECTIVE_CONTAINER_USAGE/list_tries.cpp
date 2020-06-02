#include<iostream>
#include<vector>
#include<list>
#include<algorithm>
#include "../CODE_OPTIMISATION/profiler.h"

using namespace std;

template<typename T>
struct Node {
    T data;
    Node *leftNode;
    Node *rightNode;
};

template<typename T>
class NumbersOfVector {
public:
    void Add(T x) {
        data.push_back(x);
    }

    template<typename Predicate>
    auto FindLast(Predicate predicate) {
        return find(rbegin(data), rend(data), predicate);
    }

    template<typename Predicate>
    void Remove(Predicate predicate) {
        data.erase(
                remove_if(
                        begin(data),
                        end(data),
                        predicate
                ), end(data)
        );
    }

private:
    vector<T> data;
};

class NumbersOfList {
public:
    void Add(int x) {
        data.push_back(x);
    }

    template<typename Predicate>
    auto FindLast(Predicate predicate) {
        return find_if(rbegin(data), rend(data), predicate);
//        return find_if(begin(data), end(data), predicate);
    }

    template<typename Predicate>
    void Remove(Predicate predicate) {
        data.remove_if(predicate);
    }

private:
    list<int> data;
};

void Run1() {
    Node<int> *node1 = new Node<int>{1, nullptr, nullptr};
    Node<int> *node2 = new Node<int>{2, nullptr, nullptr};
    node1->data = 1;
    node1->data = 1;

    Node<int> *node3 = nullptr;
    node3->leftNode = node1;
    node3->rightNode = node2;
}

//const int SIZE = 1'000'000;
//const int REMOVAL_COUNT = 10;

const int SIZE = 10'000;
const int REMOVAL_COUNT = 1000;

void Run2_LogDuration_Realizations() {
//    {
//        LOG_DURATION("vector");
//        NumbersOfVector<int> numbers;
//        for (int i = 0; i < SIZE; ++i) {
//            numbers.Add(i);
//        }
//        auto it = numbers.FindLast(
//                [](int x) {
//                    return x % REMOVAL_COUNT == 0;
//                }
//        );
//        for (int j = 0; j < REMOVAL_COUNT; ++j) {
////            auto predicate = [j](const int x) { return x % j == 0; };
//            auto predicate = [j](int x) { return x % REMOVAL_COUNT == j; };
//            numbers.Remove(predicate);
//        }
//    }
    {
        LOG_DURATION("list");
        NumbersOfList numbers;
        for (int i = 0; i < SIZE; ++i) {
            numbers.Add(i);
        }
        auto it = numbers.FindLast(
                [](int x) {
                    return x % REMOVAL_COUNT == 0;
                }
        );

//        for (int j = 0; j < REMOVAL_COUNT; ++j) {
        for (int j = 1; j < REMOVAL_COUNT; ++j) {
//            auto predicate = [j](const int x) { return x % j == 0; };
            auto predicate = [j](int x) { return x % REMOVAL_COUNT == j; };
            numbers.Remove(predicate);
        }
        cout << *it << '\n';
//        cout << *(++it) << '\n';
    }
}

void Test3() {
    list<int> numbers;
    for (int i = 0; i < SIZE; ++i) {
        numbers.push_back(i);
    }
    auto it = find_if(rbegin(numbers), rend(numbers), [](int x) {
        return x % REMOVAL_COUNT == 0;
    });
    cout << *it << endl;
}

int main(int argc, char *argv[]) {
    Run2_LogDuration_Realizations();
//    Test3();

    return EXIT_SUCCESS;
}