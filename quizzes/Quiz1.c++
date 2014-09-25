/*
NI: Quiz #1
*/

/* -----------------------------------------------------------------------
 1. Show the cycle for 3.
    What is the cycle length?
*/

/* -----------------------------------------------------------------------
 2. What is the output of the following?
 	In the context of Collatz, what is f() computing?
*/

#include <iostream> // cout, endl

using namespace std;

int f (int n) {
    return n + (n >> 1) + 1;}

int main () {
    cout << f(3) << endl;
    cout << f(7) << endl;
    return 0;}

/* -----------------------------------------------------------------------
 3. Given positive integers, b and e, let m = (e / 2) + 1.
    If b < m, then max_cycle_length(b, e) = max_cycle_length(m, e).
    True or False?
*/
