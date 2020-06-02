#include<iostream>
#include<string>
#include<vector>
#include<set>
#include<map>
#include<utility>
#include<sstream>

#include "../CODE_OPTIMISATION/profiler.h"

using namespace std;

vector<string> ReadStrings(istream &stream, bool use_move) {
    vector<string> strings;
    string s;
    while (stream >> s) {
        if (s == "Z") return strings;
//        cout << "s = " << s << endl;
        if (use_move) {
            strings.push_back(move(s));
        } else {
            strings.push_back(s);
        }
//        cout << "s = " << s << endl
//             << "strings.back() = " << strings.back() << endl;
    }
    return strings;
}


string GenerateText() {
    const int SIZE = 1'000'000'000;
    const int WORD_LENGTH = 10'000'000;
    string text(SIZE, 'a');
    for (int i = WORD_LENGTH; i < SIZE; i += WORD_LENGTH) {
        text[i] = ' ';
    }
    return text;
}

vector<string> SplitIntoWords(const string &text) {
    vector<string> words;
    string current_word;
    for (const char c : text) {
        if (c == ' ') {
            words.push_back(move(current_word));
            current_word.clear();
        } else {
            current_word.push_back(c);
        }
    }
    words.push_back(move(current_word));
    return words;
}

// Run Functions
void Run1() {
    for (const string &s : ReadStrings(cin, true)) {
        cout << s << ", ";
    }
    cout << endl;
}

void Run2() {
    const string text = GenerateText();
    {
        LOG_DURATION("without move");
        istringstream stream(text);
        ReadStrings(stream, false);
    }
    {
        LOG_DURATION("with move");
        istringstream stream(text);
        ReadStrings(stream, true);
    }
}

void Run3() {
//    const string text = GenerateText();
//    SplitIntoWords(text);
    for(string x : SplitIntoWords("Red BElt C++")) {
        cout << x << ", ";
    }
    cout << endl;
}

int main() {
//    Run1();
//    Run2();
    Run3();

    return EXIT_SUCCESS;
}