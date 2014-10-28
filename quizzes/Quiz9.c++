/*
NI: Quiz #9
*/

/* -----------------------------------------------------------------------
 1. What is the output of the following?
    Alternatively, the line might not compile.
    If a line doesn't compile, which line is illegal.
*/

#include <iostream> // cout, endl

using namespace std;

void f (int&) {
    cout << "f(int&)" << endl;}

void f (const int&) {
    cout << "f(const int&)" << endl;}

template <typename T>
void g (T) {
    cout << "g(T)" << endl;}

template <typename T>
void g (T*) {
    cout << "g(T*)" << endl;}

int main () {
          int i  = 2;
    const int ci = 3;

    f(i);
    f(ci);
    f(4);
    cout << endl;

    g(i);
    g(&i);
    cout << endl;

    g<int>(i);
    g<int>(&i);
    g<int*>(i);
    g<int*>(&i);

    return 0;}
