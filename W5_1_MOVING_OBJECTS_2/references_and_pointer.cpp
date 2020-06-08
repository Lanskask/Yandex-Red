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

    UserInfo(const string &name, uint8_t age) : name(name), age(age) {};

    UserInfo &&retRef() {
        return UserInfo{"Karl", 5};
    }
};

//UserInfo &returnRef() {
//    UserInfo u{"Karl", 5};
//    return u;
//}


int main() {
//    UserInfo& usRef = new UserInfo{"Pol", 1};
//    UserInfo &u3 = returnRef();
//    cout << u3.name << endl;

    UserInfo u3;
    UserInfo u4 = u3.retRef();
    cout << u4.name << endl;

    return EXIT_SUCCESS;
}