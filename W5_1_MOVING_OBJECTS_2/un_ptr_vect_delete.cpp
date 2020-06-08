#include <iostream>
#include <memory>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

class Car {
protected:
    int age;
public:
    virtual void setAge(int age_){};

    virtual int getAge(){};
};

class ConcreteCar : public Car {
public:
    void setAge(int age_) override {
        age = age_;
    }
    int getAge() override {
        return age;
    }
};

int main() {
    const size_t cnt = 5;
    list<unique_ptr<Car>> cars{};

    for (int i = 0; i < cnt; ++i) {
        auto car = make_unique<ConcreteCar>();
        car->setAge(i);
        cars.push_back(move(car));
    }
    cout << cars.size() << endl;

    auto to_found = make_unique<Car>();
    to_found->setAge(4);
    auto found = find(cars.begin(), cars.end(), to_found);
    found->reset(nullptr);
    cars.erase(found);

    cout << cars.size() << endl;
    return EXIT_SUCCESS;
}