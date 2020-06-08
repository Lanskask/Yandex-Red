#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <memory>

using namespace std;

struct UserInfo {
    string name;
    uint8_t age{};

    UserInfo() {}

    UserInfo(const string &name, uint8_t age) : name(name), age(age) {}

    friend ostream &operator<<(ostream &os, const UserInfo &info) {
        os << "name: " << info.name << " age: " << std::to_string(info.age);
        return os;
    }
    friend ostream &operator<<(ostream &os, const UserInfo *info) {
        os << "name: " << info->name << " age: " << std::to_string(info->age);
        return os;
    }

    UserInfo &setName(const string &name) {
        UserInfo::name = name;
        return *this;
    }

    UserInfo &setAge(uint8_t age) {
        UserInfo::age = age;
        return *this;
    }
};

using InfoPtr = unique_ptr<UserInfo>;

InfoPtr BuildUserInfo(int i) {
    InfoPtr res = make_unique<UserInfo>();
    res->setName("Pol" + std::to_string(i)).setAge(i);
    return res;
}

void UniquePtrListEx_Vector() {
    cout << "UniquePtrListEx_Vector" << endl;
    std::vector<InfoPtr> list1;
    size_t cnt = 5;

    for (int i = 0; i < cnt; ++i) {
        InfoPtr res = BuildUserInfo(i);
        list1.push_back(move(res));
    }
    for (const auto &userPtr : list1) {
        cout << std::to_string(userPtr->age) << "; ";
    }
    cout << endl;
}

void UniquePtrListEx_List() {
    cout << "UniquePtrListEx_List" << endl;
    std::list<InfoPtr> list1;
    size_t cnt = 5;

    for (int i = 0; i < cnt; ++i) {
        InfoPtr res = BuildUserInfo(i);
        list1.push_back(move(res));
    }
    for (const auto &userPtr : list1) {
        cout << std::to_string(userPtr->age) << "; ";
    }
    cout << endl;
}

void PushBackList() {
    std::list<UserInfo> list1;
    for (int i = 0; i < 10; ++i) {
        list1.push_back(UserInfo("Pol", i));
    }
    for (const auto &item : list1) {
        cout << item << "; ";
    }
}

void PushBackListUPtr() {
    std::list<unique_ptr<UserInfo>> list1;
    for (int i = 0; i < 10; ++i) {
        list1.push_back(make_unique<UserInfo>("Pol", i));
    }
    for (const auto &item : list1) {
        cout << item.get() << "; ";
    }
}


int main() {
    UniquePtrListEx_Vector();
    UniquePtrListEx_List();
//    PushBackList();
//    PushBackListUPtr();

    return EXIT_SUCCESS;
}