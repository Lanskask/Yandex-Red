#include<iostream>
#include<fstream>
#include<vector>

using namespace std;

void ReadFiles() {
//    for (int i = 0; i < 5; ++i) {
//        ifstream stream("file_" + to_string(i) + ".txt");
//        string line;
//        while(stream >> line) {
//            cout << line;
//        }
//        cout << endl;
//    }

    for (int i = 0; i < 5; ++i) {
        string filename = "file_" + to_string(i) + ".txt";
        ifstream stream(filename.c_str());
        string line;
        while(getline(stream, line)) {
            cout << line << endl;
        }
        cout << "--" << endl;
        cout << endl;
        stream.close();
    }

}

void Run1() {
    vector<ofstream> streams;
//    streams.reserve(5);
    for (int i = 0; i < 5; ++i) {
        ofstream stream("file_" + to_string(i) + ".txt");
        stream << "File N" << i << endl;
//        streams.push_back(stream);
        streams.push_back(move(stream));
    }
    for(auto& stream : streams) {
        stream << "Vector is reADY!" << endl;
    }

    ReadFiles();
}

int main() {
    Run1();

    return EXIT_SUCCESS;
}