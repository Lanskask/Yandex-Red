#include "test_runner.h"
#include "rational.h"
//#include "rational.cpp"

#include <algorithm>
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

void TestDefaultConstructor() {
    const string file = __FILE__;
    const int line = __LINE__;

    const Rational defaultConstructed;
    ASSERT_EQUAL(
            defaultConstructed.Numerator(),
            0);
    ASSERT_EQUAL(
            defaultConstructed.Denominator(),
            1);
}

void TestConstructor() {
    const Rational r(3, 12);
    ASSERT_EQUAL(r.Numerator(), 1);
    ASSERT_EQUAL(r.Denominator(), 4);
}

int main() {
    TestRunner tr;
//    tr.RunTest(TestDefaultConstructor, "TestDefaultConstructor");
    RUN_TEST(tr, TestDefaultConstructor);
    tr.RunTest(TestConstructor, "TestConstructor");
};
