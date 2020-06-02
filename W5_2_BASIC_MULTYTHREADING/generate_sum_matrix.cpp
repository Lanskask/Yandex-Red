#include<iostream>
#include<vector>
#include<future>

#include "../CODE_OPTIMISATION/profiler.h"

using namespace std;
using Matrix = vector<vector<int>>;

// Paginator
template<typename C>
struct Subrange {
    C &collection;
    size_t first_index, last_index;

    auto begin() const { return collection.begin(); }

    auto end() const { return collection.end(); }

    size_t size() const { return last_index - first_index; }
};

template<typename Container>
class Paginator {
private:
    vector<Subrange<Container>> pages;
public:
    Paginator(Container &c, size_t page_size) {
        for (size_t i = 0; i < c.size(); i += page_size) {
            pages.push_back({c, i, min(i + page_size, c.size())});
        }
    }

    auto begin() const {
        return pages.begin();
    }

    auto end() const {
        return pages.end();
    }

    size_t size() const {
        return pages.size();
    }
};

template<typename C>
Paginator<C> Paginate(C &c, size_t page_size) {
    return Paginator<C>(c, page_size);
}
// End of Paginator

// For single Thread
template<typename ContainerOfVectors>
void GenerateSingleThread(
        ContainerOfVectors &result,
        size_t first_row,
        size_t column_size
) {
    cout << "Inside GenerateSingleThread full" << endl;

    for (auto &row : result) {
        row.reserve(column_size);
        for (size_t column = 0; column < column_size; ++column) {
            row.push_back(first_row ^ column);
        }
        ++first_row;
    }
}

Matrix GenerateSingleThread(size_t size) {
    Matrix result(size);
    GenerateSingleThread(result, 0, size);
    return result;
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
// End of For single Thread

// For single Thread
Matrix GenerateMultiThread(
        size_t size,
        size_t page_size
) {
    cout << "Inside GenerateMultiThread" << endl;
    Matrix result(size);
    vector<future<void>> futures;

    size_t first_row = 0;
    for (auto page : Paginate(result, page_size)) {
//        future<void> fut = async([page, first_row, size] {
//            GenerateSingleThread(page, first_row, size);
//        });
//        futures.push_back(move(fut));
        futures.push_back(
            async([page, first_row, size] {
                GenerateSingleThread(page, first_row, size);
            })
        );
        first_row += page_size;
    }
    return result;
}
// End of For multi Thread



void Run1() {
    LOG_DURATION("Total");
    const size_t matrix_size = 7000;

    cout << "For single thread" << endl;
    vector<vector<int>> matrix;
//    {
//        LOG_DURATION("Single thread generation");
//        matrix = GenerateSingleThread(matrix_size);
//    }
    {
        LOG_DURATION("Multi thread generation");
        matrix = GenerateMultiThread(matrix_size, 2000);
    }
//    {
//        LOG_DURATION("Single thread sum");
//        cout << SumSingleThread(matrix);
//    }
}

int main() {
    Run1();

    return EXIT_SUCCESS;
}