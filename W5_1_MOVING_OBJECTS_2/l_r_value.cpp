#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <memory>

using namespace std;

class Dog {
    int data{0};
public:
    string name;

    // 1. default constructor
    Dog() {
        cout << __PRETTY_FUNCTION__ << endl;
    }
    Dog(int data) : data(data) {
        cout << __PRETTY_FUNCTION__ << endl;
    }
    // 2. destructor
    virtual ~Dog() {
        cout << __PRETTY_FUNCTION__ << endl;
    }
    // 3. Copy constructor
    Dog(const Dog& rhs) {
        cout << __PRETTY_FUNCTION__ << endl;
       data = rhs.data;
    }
    //4. Copy assinent operator
    Dog& operator=(const Dog& rhs) {
        cout << __PRETTY_FUNCTION__ << endl;
        if(this == &rhs)
            return *this;
        data = rhs.data;
        return *this;
    }

    //5. Copy assignent operator
    Dog(Dog&& rhs) {
        cout << __PRETTY_FUNCTION__ << endl;
        data = std::move(rhs.data);
        rhs.data = 0;
    }
    //6. Move assignment operator
    Dog& operator=(Dog&& rhs) {
        cout << __PRETTY_FUNCTION__ << endl;
        data = std::move(rhs.data);
        return *this;
    }

    friend ostream &operator<<(ostream &os, const Dog &dog) {
        os << "data: " << dog.data;
        return os;
    }
};

int fun() {
   return 2;
}

void call_copy(Dog& var, vector<Dog>& v) {
    cout << "\n----------------\n";
    cout << "I copy " << var << "\n";
    v.push_back(var);
}

void call_move(Dog&& var, vector<Dog>& v) {
    cout << "\n----------------\n";
    cout << "I move " << var << "\n";
    v.push_back(move(var));
}

void l_r_value() {
    int a; // lvalue
    Dog rex; // lvalue

    fun();
    Dog{};

    // lvalue ref -> lvalue
    int& b = a;
    // const lvalue ref -> rvalue
    const int& c = fun();

    //rvalue ref -> rvalue only!
    int&& d = fun();
//    int&& d = a; // error: a - is lvalue
}

void move_copy_expr() {
    vector<Dog> v;
    v.reserve(2);

    cout << "\n----------------\n";

    Dog rex{10};

    call_copy(rex, v);
    call_move(move(rex), v);

    cout << "\n----------------\n";
    cout << "Init object: " << rex;

    cout << "\n----------------\n";
    cout << "Vector: \n";
    for(const auto& item : v) {
        cout << item << "\n";
    }
    cout << "\n----------------\n";
}

int main() {
//    l_r_value();
    move_copy_expr();

    return EXIT_SUCCESS;
}