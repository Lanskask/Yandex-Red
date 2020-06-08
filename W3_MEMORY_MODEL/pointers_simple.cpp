#include<iostream>
#include<string>
#include<memory>
#include <vector>
#include <algorithm>

using namespace std;

struct Struct11 {
    int int1;
    string str1;
};

void Run2() {
    string* s = new string;
    *s = "Hello";
    cout << *s << " " << s->size() << endl;

    shared_ptr<string> s2 = make_shared<string>("string2");
    cout << *s2 << ' ' << s2->size() << endl;

    cout << "-- string s3 = *s; --" << endl;
    string s3 = *s;
    // get ref to pointer
    cout << "s3: " << s3 << "; s: " << *s << endl;
    s3 += " addition";
    cout << "s3 after addition: " << s3 << "; s: " << *s << endl;

    cout << "-- string& ref_to_s = *s; --" << endl;
    string& ref_to_s = *s;
    ref_to_s += " adition";
    cout << "ref_to_s: " << ref_to_s << "; s: " << *s << endl;
}

void Run3() {
    Struct11* struct1 = new Struct11{1, "init"};
    Struct11& ref_to_struct1 = *struct1;
    cout << "Now we changing struct1 by ref_to_struct1" << endl;
    ++ref_to_struct1.int1;
    ref_to_struct1.str1 += " changed";
    cout << "struct1 changed: "
        << "{" << struct1->int1 << ": " << struct1->str1 << "}" << endl;
}

// Runs 2
void Run4() {
    vector<int> v1 = {1,2,3,4,5};
    vector<int>::iterator it = find(begin(v1), end(v1), 5);
    cout << "*it: " << *it << endl;
    cout << "*it: " << *++it << endl;
    cout << "*it: " << *++it << endl;
    cout << "*it: " << *++it << endl;
    cout << "*it: " << *++it << endl;
}

int main(int argc, char *argv[]) {
//    Run2();
//    Run3_Ref_Invalidation();
    Run4();
//    int * pInt = new int;


    return EXIT_SUCCESS;
}