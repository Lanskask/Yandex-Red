#include<iostream>
#include "profiler.h"

using namespace std;

void Run12() {
//    ios_base::sync_with_stdio(false);
//    cin.tie(nullptr);
    {
        LOG_DURATION("endl");
        for (int i = 0; i < 200'000; ++i) {
            int x;
            cin >> x;
            cout << x << endl;
        }
    }
    {
        LOG_DURATION("\\n");
        for (int i = 0; i < 200'000; ++i) {
            int x;
            cin >> x;
            cout << x << '\n';
        }
    }
}

void Run3() {
    cin.tie(nullptr);
    cout << "Enter two integers: ";
    int x, y;
    cin >> x, y;
    for(;;) {}
}

int main(int argc, char *argv[]) {
    Run12();
//    Run3_Ref_Invalidation();

    return EXIT_SUCCESS;
}