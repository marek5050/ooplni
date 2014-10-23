/*
NI: Quiz #8
*/

/* -----------------------------------------------------------------------
 1. What is the output of the following?

A(int) A(A) A(A) A(A) A(A) A(A) A(A) A(A) A(A) A(A) ~A() ~A() ~A() ~A()
~A() ~A() ~A() ~A() ~A() ~A()
*/

#include <iostream> // cout, endl
#include <memory>   // allocator
#include <vector>   // vector

using namespace std;

struct A {
    A  ()         {cout << "A() ";}    // default constructor
    A  (int)      {cout << "A(int) ";} // int constructor
    A  (const A&) {cout << "A(A) ";}   // copy constructor
    ~A ()         {cout << "~A() ";}}; // destructor

int main () {
    {
    vector< vector<A>> x(2, vector<A>(3, A(4)));
    cout << endl;
    }
    cout << endl;

    return 0;}
