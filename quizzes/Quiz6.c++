/*
NI: Quiz #6
*/

/* -----------------------------------------------------------------------
 1. What is the output of the following?
    (6 pts)
*/

#include <iostream> // cout, endl
#include <vector>   // vector

using namespace std;

struct A {
    A  ()         {cout << "A() ";}    // default constructor
    A  (const A&) {cout << "A(A) ";}   // copy constructor
    ~A ()         {cout << "~A() ";}}; // destructor

struct B : A {
    B  ()         {cout << "B() ";}    // default constructor
    B  (const B&) {cout << "B(B) ";}   // copy constructor
    ~B ()         {cout << "~B() ";}}; // destructor

int main () {
    {
    vector<A> x(3, B());
    cout << endl;
    }
    cout << endl << endl;

    {
    vector<A*> x(3, new B());
    cout << endl;
    }

    return 0;}
