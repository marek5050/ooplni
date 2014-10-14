// -----------
// Arrays2.c++
// -----------

#include <cassert>  // assert
#include <iostream> // cout, endl

void f1 (int p[]) {
    assert(sizeof(p) == 8);}

void f2 (int* p) {
    assert(sizeof(p) == 8);}

void g1 (int p[][20]) {
    assert(sizeof(p) == 8);}

void g2 (int (*p)[20]) {
    assert(sizeof(p) == 8);}

void h1 (int* p[]) {
    assert(sizeof(p) == 8);}

void h2 (int** p) {
    assert(sizeof(p) == 8);}

int main () {
    using namespace std;
    cout << "Arrays2.c++" << endl;

    int  a[10];
    assert(sizeof(a) == 10 * sizeof(int));
    assert(sizeof(a) == 40);

    int  b[10][20];
    assert(sizeof(b) == 10 * 20 * sizeof(int));
    assert(sizeof(b) == 800);

    int* c[10];
    assert(sizeof(c) == 10 * sizeof(int*));
    assert(sizeof(c) == 80);

    f1(a);
//  f1(b); // error: cannot convert 'int (*)[20]' to 'int*' for argument '1' to 'std::string f1(int*)'
//  f1(c); // error: cannot convert 'int**' to 'int*' for argument '1' to 'std::string f1(int*)'

    f2(a);
//  f2(b); // error: cannot convert 'int (*)[20]' to 'int*' for argument '1' to 'std::string f1(int*)'
//  f2(c); // error: cannot convert 'int**' to 'int*' for argument '1' to 'std::string f1(int*)'

//  g1(a); // error: cannot convert 'int*' to 'int (*)[20]' for argument '1' to 'std::string g1(int (*)[20])'
    g1(b);
//  g1(c); // error: cannot convert 'int**' to 'int (*)[20]' for argument '1' to 'std::string g1(int (*)[20])'

//  g2(a); // error: cannot convert 'int*' to 'int (*)[20]' for argument '1' to 'std::string g1(int (*)[20])'
    g2(b);
//  g2(c); // error: cannot convert 'int**' to 'int (*)[20]' for argument '1' to 'std::string g1(int (*)[20])'

//  h1(a); // error: cannot convert 'int*' to 'int**' for argument '1' to 'std::string h(int**)'
//  h1(b); // error: cannot convert 'int (*)[20]' to 'int**' for argument '1' to 'std::string h(int**)'
    h1(c);

//  h2(a); // error: cannot convert 'int*' to 'int**' for argument '1' to 'std::string h(int**)'
//  h2(b); // error: cannot convert 'int (*)[20]' to 'int**' for argument '1' to 'std::string h(int**)'
    h2(c);

    cout << "Done." << endl;
    return 0;}
