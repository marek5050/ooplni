/*
NI: Quiz #10
*/

/* -----------------------------------------------------------------------
 1. What is the output of the following program?
*/

#include <iostream> // cout, endl

using namespace std;

struct A {
    A             (int)      {cout << "A(int) ";}
    A             (const A&) {cout << "A(A) ";}
    ~A            ()         {cout << "~A() ";}
    A& operator = (const A&) {cout << "=(A) "; return *this;}
    operator int  ()         {cout << "int(A)"; return 0;}};

void f (A)   {}
void g (int) {}

int main () {
    using namespace std;

    {
    A x = 2;
    cout << endl;

    A y = x;
    cout << endl;

    f(2);
    cout << endl;

    g(y);
    cout << endl;
    }
    cout << endl;

    return 0;}
