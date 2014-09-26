/*
NI: Quiz #1
*/

/* -----------------------------------------------------------------------
 1. Show the cycle for 3.
    What is the cycle length?

3, 10, 5, 16, 8, 4, 2, 1
8
*/

/* -----------------------------------------------------------------------
 2. What is the output of the following?
 	In the context of Collatz, what is f() computing?

5
11

For odd n it's computing (3n + 1) / 2.
(3n + 1) / 2
3n/2 + 1/2
n + n/2 + 1/2
n + n/2 + 1, because n is odd
n + (n >> 1) + 1
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

True

Consider b = 10, e = 100.
Then m = (100 / 2) + 1 = 51.
max_cycle_length(10, 100) = max_cycle_length(51, 100)
All the numbers in the range [10, 50] can be mapped to numbers in the
range [51, 100] by one or more doublings, so none of the numbers in the
range [10, 50] could have a larger cycle length than the numbers in the
range [51, 100].
*/
