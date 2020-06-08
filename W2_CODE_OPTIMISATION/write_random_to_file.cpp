#include<iostream>
#include <random>
#include <fstream>

using namespace std;

int rumdomInt(int count) {
    std::mt19937 rng;
    rng.seed(std::random_device()());
    std::uniform_int_distribution<std::mt19937::result_type> dist6(1,count); // distribution in range [1, 6]

    return dist6(rng);
}

void populateFile(int count,
                  std::string const &file) {
    std::ofstream myfile(file);
    if (!myfile) {
        cout << "!myfile" << endl;
        return;
    }

    int random_integer;
    for (int index = 0; index < count; index++) {
//        random_integer = (rand() % 1000) + 1;
        random_integer = rumdomInt(count);
        myfile << random_integer << " ";
    }
    cout << "Success!" << endl;
}

void Run1() {
    string file_name1 = "input1.txt";
    string file_name2 = "input2.txt";

    populateFile(25000, file_name1);
    populateFile(25000, file_name2);
}


int main(int argc, char *argv[]) {
    string file_name1 = "200k_nums.txt";

    populateFile(200'000, file_name1);

    return EXIT_SUCCESS;
}