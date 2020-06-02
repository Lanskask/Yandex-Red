#include<iostream>
#include<string>
#include<map>
#include<tuple>
#include <cassert>

using namespace std;

template <typename Key, typename Value>
map<Key, Value> StringToMap(const string& str) {
    map<Key, Value> result;
    for(const char& ch : str) {
        if(result.find(ch) != result.end()) {
            result.at(ch)++;
        } else { // if there is this letter in map
            result.insert({ch, 1});
        }
    }
    return result;
}

bool IsAnagramm(string string1, string string2) {
//    map<char, int> letter_to_numb_in_str1;
//    for(const char& ch : string1) {
//        if(letter_to_numb_in_str1.find(ch) != letter_to_numb_in_str1.end()) {
//            letter_to_numb_in_str1.at(ch)++;
//        } else { // if there is this letter in map
//            letter_to_numb_in_str1.at(ch) = 1;
//        }
//    }
//    map<char, int> letter_to_numb_in_str2;
//    for(const char& ch : string1) {
//        if(letter_to_numb_in_str2.find(ch) != letter_to_numb_in_str2.end()) {
//            letter_to_numb_in_str2.at(ch)++;
//        } else { // if there is this letter in map
//            letter_to_numb_in_str2.at(ch) = 1;
//        }
//    }
    map<char, int> res1 = StringToMap<char, int>(string1);
    map<char, int> res2 = StringToMap<char, int>(string2);
    return res1 == res2;
}

int main(int argc, char *argv[]) {
//    map<char, int> map1 = {{'b',3}};
//    map<char, int> map2 = {{'b',3}};
//    map<char, int> map3 = {{'b',4}};
//    bool bool1 = map1.find('a') == map1.end();
//    cout << bool1 << endl;

    // Test2
//    cout << (map1 == map2) << endl;
//    cout << (map1 == map3) << endl;

    // Test3
//    map<char, int> res3 = StringToMap<char, int>("aabcc");
//    for(const auto& [k ,v] : res3) {
//        cout << k << ": " << v << ", ";
//    }
//    cout << endl;

    // End Test
    string w1 = "";
    string w2 = "a";
    string w3 = "a";
    string w4 = "ab";
    string w5 = "abb";
    string w6 = "abba";
    string w7 = "abbca";
    string w8 = "abbac";


    tuple<string, string, bool> t1 = {w1, w1, true};
    tuple<string, string, bool> t2 = {w1, w2, false};
    tuple<string, string, bool> t3 = {w7, w8, true};

    for(const auto& [s1, s2, res] : {t1,t2,t3}) {
        bool end_res = IsAnagramm(s1,s2);
        cout << end_res << endl;
        assert(end_res == res);
    }

    return EXIT_SUCCESS;
}