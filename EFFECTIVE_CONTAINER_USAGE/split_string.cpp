#include<iostream>
#include <vector>
#include <algorithm>
#include "../CODE_OPTIMISATION/profiler.h"

using namespace std;

vector<string> My_SplitString(const string &str) {
    vector<string> result;
    auto str_begin = begin(str);
    const auto str_end = end(str);

    while (true) {
        auto it = find(str_begin, str_end, ' ');
        result.push_back(string(str_begin, it));

        if (it == str_end) {
//            result.push_back(string(str_begin, str_end));
            return result;
        } else {
            str_begin = ++it;
        }
    }
}

vector<string> Thereis_Simple_SplitString(const string &str) {
    vector<string> result;
    auto str_begin = begin(str);
    const auto str_end = end(str);

    while (true) {
        auto it = find(str_begin, str_end, ' ');
        result.push_back(string(str_begin, it));

        if (it != str_end) {
            str_begin = ++it;
        } else {
//            return result;
            break;
        }
    }
    return result;
}

vector<string_view> Thereis_StringView_SplitString(const string &s) {
    string_view str = s;

    vector<string_view> result;
//    auto str_begin = begin(str);
    size_t pos = 0;
//    const auto str_end = end(str);
    const size_t pos_end = str.npos;

    while (true) {
//        auto it = find(str_begin, str_end, ' ');
        size_t space = str.find(' ', pos);
//        result.push_back(string(str_begin, it));
        result.push_back(
                space == pos_end
                ? str.substr(pos)
                : str.substr(pos, space - pos)
        );

//        if (it != str_end) {
        if (space != pos_end) {
//            str_begin = ++it ;
            pos = ++space;
        } else {
//            return result;
            break;
        }
    }
    return result;
}

vector<string_view> Thereis_StringView_SplitString_Compact(const string &s) {
    string_view str = s;

    vector<string_view> result;

    while (true) {
        size_t space = str.find(' ');
        result.push_back(str.substr(0, space));

//        if (it != str_end) {
        if (space == string_view::npos) {
            break;
        } else {
            str.remove_prefix(space + 1);
        }
    }
    return result;
}

// Part 3
vector<string_view> Thereis_StringView_SplitString_ExptWithAsString(const string_view &str) {
//    string_view str = s;

    vector<string_view> result;
//    auto str_begin = begin(str);
    size_t pos = 0;
//    const auto str_end = end(str);
    const size_t pos_end = str.npos;

    while (true) {
//        auto it = find(str_begin, str_end, ' ');
        size_t space = str.find(' ', pos);
//        result.push_back(string(str_begin, it));
        result.push_back(
                space == pos_end
                ? str.substr(pos)
                : str.substr(pos, space - pos)
        );

//        if (it != str_end) {
        if (space != pos_end) {
//            str_begin = ++it ;
            pos = ++space;
        } else {
//            return result;
            break;
        }
    }
    return result;
}

string GenerateTest() {
    const int SIZE = 1'000'000;
    string text(SIZE, 'a');
    for (int i = 100; i < SIZE; ++i) {
        text[i] = ' ';
    }
    return text;
}

// Run Functions
void Run1() {
    for (string x : My_SplitString("ab bc")) {
        cout << x << ", ";
    }
    cout << endl;
    for (string x : Thereis_Simple_SplitString("ab bc")) {
        cout << x << ", ";
    }
    cout << endl;
    for (string_view x : Thereis_StringView_SplitString("ab bc")) {
        cout << x << ", ";
    }
}

// My_SplitString
// Thereis_Simple_SplitString
// Thereis_StringView_SplitString
void Run2() {
    string str = GenerateTest();
    {
        LOG_DURATION("My_SplitString");
        cout << My_SplitString(str).front() << endl;
    }
    {
        LOG_DURATION("Thereis_Simple_SplitString");
        cout << Thereis_Simple_SplitString(str).front() << endl;
    }
    {
        LOG_DURATION("Thereis_StringView_SplitString");
        cout << Thereis_StringView_SplitString(str).front() << endl;
    }
    {
        LOG_DURATION("Thereis_StringView_SplitString_Compact");
        cout << Thereis_StringView_SplitString_Compact(str).front() << endl;
    }
}

void Run3() {
    string str = "aa bb";
    cout << Thereis_StringView_SplitString_ExptWithAsString(str).front() << endl;
}

int main() {
//    Run1();
//    Run2();
    Run3();

    return EXIT_SUCCESS;
}
