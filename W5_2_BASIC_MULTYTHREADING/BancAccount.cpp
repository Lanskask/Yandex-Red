#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <future>
#include <mutex>

using namespace std;

struct Account {
    int balance = 0;
    vector<int> history;
    mutex m;

    bool Spend(int value) {
        lock_guard<mutex> g(m);
        if (value <= balance) {
            balance -= value;
            history.push_back(value);
            return true;
        }
    }
};

int SpendMoney(Account &account) {
    int total_spent = 0;
    for (int i = 0; i < 10000; ++i) {
        if (account.Spend(1)) {
            ++total_spent;
        }
    }
    return total_spent;
}

void Run1() {
    const int FAMILY_BUDGET = 100'000;
//    Account my_account{10000};
//
//    cout << "Total spent: " << SpendMoney(my_account)
//    << "; Balance: " << my_account.balance << endl;
    Account family_account{FAMILY_BUDGET};

    auto husband = async(SpendMoney, ref(family_account));
    auto wife = async(SpendMoney, ref(family_account));
    auto son = async(SpendMoney, ref(family_account));
    auto daughter = async(SpendMoney, ref(family_account));

    int spent = husband.get() + wife.get() + son.get() + daughter.get();
    cout << "Total spent: " << spent
         << "; Balance: " << family_account.balance << endl;

}

int main() {
    Run1();

    return 0;
}