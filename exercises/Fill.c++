/*
NI: Exercise #3
*/

/* -----------------------------------------------------------------------
Define the function my_fill() such that it behaves as follows:
*/

// http://www.cplusplus.com/reference/algorithm/fill/

#include <algorithm> // all_of, fill
#include <cassert>   // assert
#include <iostream>  // cout, endl
#include <list>      // list

template <typename FI, typename T>
void my_fill (FI b, FI e, const T& v) {
    while (b != e) {
        *b = v;
        ++b;}}

int main () {
    using namespace std;
    cout << "Exercise3.c++" << endl;

    const size_t s = 3;
    const int    v = 5;
    list<int>    x(s);
    fill(x.begin(), x.end(), v);
    assert(all_of(x.begin(), x.end(), [] (int w) -> bool {return v == w;}));

    cout << "Done." << endl;
    return 0;}
