/*
NI: Quiz #7
*/

/* -----------------------------------------------------------------------
 1. What is the output of the following?

A() A(A) ~A() A() A(A) ~A() A() A(A) ~A()
~A() ~A() ~A()

A() A() A()
*/

#include <iostream> // cout, endl
#include <memory>   // allocator

using namespace std;

struct A {
    A  ()         {cout << "A() ";}    // default constructor
    A  (const A&) {cout << "A(A) ";}   // copy constructor
    ~A ()         {cout << "~A() ";}}; // destructor

int main () {
    {
    allocator<A> x;
    cout << endl;
    A* p = x.allocate(3);
    cout << endl;
    for (int i = 0; i != 3; ++i)
        x.construct(p + i, A());
    cout << endl;
    for (int i = 0; i != 3; ++i)
        x.destroy(p + i);
    cout << endl;
    x.deallocate(p, 3);
    cout << endl;
    }
    cout << endl << endl;

    {
    allocator<A*> x;
    cout << endl;
    A** p = x.allocate(3);
    cout << endl;
    for (int i = 0; i != 3; ++i)
        x.construct(p + i, new A());
    cout << endl;
    for (int i = 0; i != 3; ++i)
        x.destroy(p + i);
    cout << endl;
    x.deallocate(p, 3);
    cout << endl;
    }
    cout << endl << endl;

    return 0;}
