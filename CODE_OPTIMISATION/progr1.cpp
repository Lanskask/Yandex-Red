#include<iostream>
#include<fstream>
#include<vector>
#include<set>

#include "profiler.h"

using namespace std;
using namespace std::chrono;

int main(int argc, char *argv[]) {
    LOG_DURATION("Total");
    ifstream in("input.txt");
    int element_count;
    in >> element_count;

    set<int> ellements;

    {
        LOG_DURATION("Input");

        for (int i = 0; i < element_count; ++i) {
//            LOG_DURATION("Iter " + to_string(i));
            int x;
            in >> x;
            ellements.insert(x);
        }
    }

    int query_count;
    in >> query_count;

    int total_found = 0;
    {
        LOG_DURATION("Queries processing");
        for (int i = 0; i < query_count; ++i) {
            int x;
            in >> x;
            if (ellements.find(x) != ellements.end()) {
                ++total_found;
            }
        }
    }
    cout << total_found;


    return EXIT_SUCCESS;
}