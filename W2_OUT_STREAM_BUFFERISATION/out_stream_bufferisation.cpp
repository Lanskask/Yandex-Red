#include<iostream>
#include<vector>
#include<fstream>
#include "profiler.h"


using namespace std;

int main(int argc, char *argv[]) {
    ofstream out("output1.txt");
    {
        LOG_DURATION("With \\n");
        for (int i = 0; i < 25000; ++i) {
            out << "London is a capital of Great Britain. "
                << "I'm traveling down the river"
                << "\n";
//            << endl;
        }
    }
    ofstream out2("output2.txt");
    {
        LOG_DURATION("With endl");
        for (int i = 0; i < 25000; ++i) {
            out << "London is a capital of Great Britain. "
                << "I'm traveling down the river"
//                << "\n";
            << endl;
        }
    }
    return EXIT_SUCCESS;
}