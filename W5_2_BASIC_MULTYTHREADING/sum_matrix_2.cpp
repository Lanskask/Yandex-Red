#include <iostream>
#include <algorithm>
#include <vector>
#include <execution>
#include "../CODE_OPTIMISATION/profiler.h"

using namespace std;

template<typename ContainerOfVectors>
void GenerateSingleThread(
        ContainerOfVectors &result,
        size_t first_row,
        size_t column_size
) {
    for_each(
            execution::par,
            begin(result),
            end(result),
            [&first_row, column_size](vector<int> &row) {
                row.reserve(column_size);
                for (size_t column = 0; column < column_size; ++column) {
                    row.push_back(first_row ^ column);
                }
                ++first_row;
            }
    );
}

template<typename ContainerOfVectors>
int64_t SumSingleThread(const ContainerOfVectors &matrix) {
    int64_t sum = 0;
    for (const auto &row : matrix) {
        for (auto item : row) {
            sum += item;
        }
    }
    return sum;
}

void Run1() {
    LOG_DURATION("Total");
    const size_t matrix_size = 7000;

    cout << "For single thread" << endl;
    vector<vector<int>> matrix;
    {
        LOG_DURATION("Single thread generation");
//        matrix = GenerateSingleThread(matrix_size);
        GenerateSingleThread(matrix, 0, 10);
    }
    {
        LOG_DURATION("Single thread sum");
        cout << SumSingleThread(matrix);
    }
}

struct Str1 {
    bool b;
    int i;
};

void Run2() {
    Str1 str1{true, 1};
    cout << sizeof(str1) << endl;
}

int main() {
//    Run1();
    Run2();

    return 0;
}