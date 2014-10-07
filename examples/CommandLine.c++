// ---------------
// CommandLine.c++
// ---------------

// http://www.cplusplus.com/articles/DEN36Up4/

/*
% g++-4.7 -pedantic -std=c++11 -Wall CommandLine.c++ -o CommandLine
% CommandLine Nothing to be done.
*/

#include <algorithm> // equal
#include <cassert>   // assert
#include <iostream>  // cout, endl
#include <string>    // string

int main (int argc, char* argv[]) {
    using namespace std;
    cout << "CommandLine.c++" << endl;

    assert(argc == 5);

    const string a[] = {"CommandLine", "Nothing", "to", "be", "done."};
//  assert(argv == a);
    assert(equal(argv, argv + argc, a));

    cout << "Done." << endl;
    return 0;}
