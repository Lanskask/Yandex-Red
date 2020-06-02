#include<iostream>
#include<map>
#include<string>

using namespace std;

class Person {
public:
    // call for temporary: move -> move
    // else: copy -> move
    void ChangeFirstName(int year, string first_name) {
        first_names[year] = move(first_name);
    }
    void ChangeLastName(int year, string last_name) {
        last_names[year] = move(last_name);
    }
    string GetFullName(int year) {
        string first_name = FindNameByYear(first_names, year);
        string last_name = FindNameByYear(last_names, year);
        if(first_name.empty() && last_name.empty()) {
            return "Incognito";
        } else if (first_name.empty()) {
            return last_name + " with unknown first name";
        } else if (last_name.empty()) {
            return first_name + " with unknown first name";
        } else {

        }
    }
    string FindNameByYear(map<int, string> names, int year) {

    }
private:
    map<int, string> first_names;
    map<int, string> last_names;
};


int main(int argc, char *argv[]) {

    return EXIT_SUCCESS;
}