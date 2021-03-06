// -----------------------
// FunctionOverloading.c++
// -----------------------

// http://www.cplusplus.com/doc/tutorial/functions2/

// ad-hoc compile-time polymorphism

#include <cassert>  // assert
#include <cstring>  // strcmp
#include <iostream> // cout, endl
#include <string>   // string

struct A {
    int _n;

    A (int n) :
            _n (n)
        {}};

bool operator < (const A& lhs, const A& rhs) {
    return lhs._n < rhs._n;}

struct B : A {
    B (int n) :
            A (n)
        {}};

int my_max (int x, int y) {
    if (x < y)
        return y;
    return x;}

const int* my_max (const int* x, const int* y) {
    if (*x < *y)
        return y;
    return x;}

const char* my_max (const char* x, const char* y) {
    if (std::strcmp(x, y) < 0)
        return y;
    return x;}

const A& my_max (const A& x, const A& y) {
    if (x < y)
        return y;
    return x;}

std::string f (int) {
    return "f(int)";}

//std::string f (const int) { // error: redefinition of "std::string f(int)"
//    return "f(const int)";}

std::string g (int&) {
    return "g(int&)";}

std::string g (const int&) { // g (int)
    return "g(const int&)";}

std::string h (int*) {
    return "h(int*)";}

std::string h (const int*) {
    return "h(const int*)";}

std::string ff (int) {
    return "ff(int)";}

std::string ff (long) {
    return "ff(long)";}

std::string ff (A) {
    return "ff(A)";}

std::string ff (B) {
    return "ff(B)";}

std::string gg (A&) {
    return "gg(A&)";}

std::string hh (const A&) {
    return "hh(const A&)";}

int main () {
    using namespace std;
    cout << "FunctionOverloading.c++" << endl;

    assert(my_max(2,   3)   == 3);
    assert(my_max(2,   3.4) == 3); // warning: implicit conversion from 'double' to 'int' changes value from 3.4 to 3
    assert(my_max(2.3, 4)   == 4); // warning: implicit conversion from 'double' to 'int' changes value from 2.3 to 2
    assert(my_max(2.3, 4.5) == 4); // warning: implicit conversion from 'double' to 'int' changes value from 2.3 to 2
                                   // warning: implicit conversion from 'double' to 'int' changes value from 4.5 to 4

    {
    int i = 2;
    int j = 3;
    assert(my_max(&i, &j) == &j);
    }

    assert(strcmp(my_max("abc", "def"), "def") == 0);

    {
    A x = 2;
    A y = 3;
    assert(&my_max(x, y) == &y);
    }

    {
    B x = 2;
    B y = 3;
    assert(&my_max(x, y) == &y);
    }

    {
          int i  = 2;
    const int ci = 3;

    assert(f(i)  == "f(int)");
    assert(f(ci) == "f(int)");
    assert(f(4)  == "f(int)");

    assert(g(i)  == "g(int&)");
    assert(g(ci) == "g(const int&)");
    assert(g(4)  == "g(const int&)");

    assert(h(&i)  == "h(int*)");
    assert(h(&ci) == "h(const int*)");
    }

//  h(0);                                                     // error: call of overloaded "h(int)" is ambiguous
    assert(h(static_cast<int*>(0))       == "h(int*)");
    assert(h(static_cast<const int*>(0)) == "h(const int*)");

    assert(ff(2)  == "ff(int)");
    assert(ff(3L) == "ff(long)");

    assert(ff(A(2)) == "ff(A)");
    assert(ff(B(3)) == "ff(B)");

//  assert(gg(A(2)) == "gg(A&)");       // error: invalid initialization of non-const reference of type ‘A&’ from a temporary of type ‘A’
    assert(hh(A(2)) == "hh(const A&)");

    cout << "Done." << endl;
    return 0;}
