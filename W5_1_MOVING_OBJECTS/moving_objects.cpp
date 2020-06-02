#include<iostream>
#include<string>
#include<vector>
#include<set>
#include<map>

#include "../CODE_OPTIMISATION/profiler.h"

using namespace std;

string MakeString() {
    return string(100'000'000, 'a');
}

vector<int> MakeVector() {
    return vector<int>(100'000'000, 0);
}

void Run1() {
    {
        LOG_DURATION("with variable");
        vector<string> strings;
        string heavy_string = MakeString();
        strings.push_back(heavy_string);
    }
    {
        LOG_DURATION("without variable");
        vector<string> strings;
        strings.push_back(MakeString());
    }
    {
        LOG_DURATION("with string constructor");
        vector<string> strings;
        strings.push_back(string(100'000'000, 'a'));
    }
}

void Run2() {
    {
        LOG_DURATION("assignment, with variable");
        string target_string = "old_vavlue";
        string source_string = MakeString();
        target_string = source_string;
    }
    {
        LOG_DURATION("assignment, with move");
        string target_string = "old_vavlue";
        target_string = MakeString();
    }
    {
        LOG_DURATION("assignment, straight to variable");
        string target_string = "old_vavlue";
        string source_string = MakeString();
        target_string = move(source_string);
    }

    cout << "With set" << endl;
    {
        LOG_DURATION("set::insert, with variable");
        set<string> strings;
        string heavy_string = MakeString();
        strings.insert(heavy_string);
    }
    {
        LOG_DURATION("set::insert, straight");
        set<string> strings;
        strings.insert(MakeString());
    }
    {
        LOG_DURATION("set::insert, with move");
        set<string> strings;
        string heavy_string = MakeString();
        strings.insert(move(heavy_string));
    }

    cout << "-- Map --" << endl;
    {
        LOG_DURATION("map::insert, both variables");
        map<string, string> strings;
        string key = MakeString();
        string value = MakeString();
//        strings.insert({key, value});
        strings[key] = value;
    }
    {
        LOG_DURATION("map::insert, moving both variables");
        map<string, string> strings;
        string key = MakeString();
        string value = MakeString();
        strings.insert({move(key), move(value)});
    }
    {
        LOG_DURATION("map::insert, key - func");
        map<string, string> strings;
        string key = MakeString();
        strings.insert({key, MakeString()});
    }
    {
        LOG_DURATION("map::insert, both funcs");
        map<string, string> strings;
        strings.insert({MakeString(), MakeString()});
    }

    cout << "-- With BIG Vector --" << endl;
    {
        LOG_DURATION("set::insert, vector with variable");
        set<vector<int>> vectors;
        vector<int> heavy_vector = MakeVector();
        vectors.insert(heavy_vector);
    }
    {
        LOG_DURATION("set::insert, func to set");
        set<vector<int>> vectors;
        vectors.insert(MakeVector());
    }
    {
        LOG_DURATION("set::insert, with move");
        set<vector<int>> vectors;
        vector<int> heavy_vector = MakeVector();
        vectors.insert(move(heavy_vector));
    }
    {
        LOG_DURATION("set::insert, move function direcly - any bonuses?");
        set<vector<int>> vectors;
        vectors.insert(move(MakeVector()));
    }

}

int main() {
//    Run1();
    Run2();

    return EXIT_SUCCESS;
}