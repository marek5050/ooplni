// ---------
// Enums.c++
// ---------

#include <cassert>  // assert
#include <iostream> // cout, endl

namespace Color1 {
    enum Color {
        red,
        green,
        blue,
        yellow = blue,
        purple};}

namespace Color2 {
    enum Color {
        red,
        green,
        blue,
        yellow = blue,
        purple};}

void f (Color1::Color c) {
    assert(c == Color1::blue);}

int main () {
    using namespace std;
    cout << "Enums.c++" << endl;

    assert(Color1::red    == 0);
    assert(Color1::green  == 1);
    assert(Color1::blue   == 2);
    assert(Color1::yellow == 2);
    assert(Color1::purple == 3);

    assert(Color1::red   == Color1::red);
    assert(Color1::green != Color1::blue);
    assert(Color1::red   <  Color1::blue);

//  assert(Color1::red == Color2::red); // warning: comparison of two values with different enumeration types ('Color1::Color' and 'Color2::Color')

    {
    int i = Color1::blue;
    assert(i == 2);
    }

    {
//  Color1::Color c = 2;                             // error: cannot initialize a variable of type 'Color1::Color' with an rvalue of type 'int'
    Color1::Color c = static_cast<Color1::Color>(2);
    assert(c == 2);
    assert(c == Color1::blue);
    }

    {
//  Color1::Color c = Color2::blue;                             // error: cannot initialize a variable of type 'Color1::Color' with an rvalue of type 'Color2::Color'
    Color1::Color c = static_cast<Color1::Color>(Color2::blue);
    assert(c == 2);
    assert(c == Color1::blue);
    }

    f(Color1::blue);
//  f(Color2::blue);                             // error: no matching function for call to 'f'
    f(static_cast<Color1::Color>(Color2::blue));
//  f(2);                                        // error: no matching function for call to 'f'
    f(static_cast<Color1::Color>(2));

    cout << "Done." << endl;
    return 0;}
