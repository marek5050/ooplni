// --------------
// Allocators.c++
// --------------

#include <algorithm> // count
#include <cassert>   // assert
#include <iostream>  // cout, endl
#include <memory>    // allocator, ==, !=

template <typename A, typename BI>
BI my_destroy (A& a, BI b, BI e) {
    while (b != e) {
        --e;
        a.destroy(&*e);}
    return b;}

template <typename A, typename II, typename BI>
BI my_uninitialized_copy (A& a, II b, II e, BI x) {
    BI p = x;
    try {
        while (b != e) {
            a.construct(&*x, *b);
            ++b;
            ++x;}}
    catch (...) {
        my_destroy(a, p, x);
        throw;}
    return x;}

template <typename A, typename BI, typename U>
BI my_uninitialized_fill (A& a, BI b, BI e, const U& v) {
    BI p = b;
    try {
        while (b != e) {
            a.construct(&*b, v);
            ++b;}}
    catch (...) {
        my_destroy(a, p, b);
        throw;}
    return e;}

int main () {
    using namespace std;
    cout << "Allocators.c++" << endl;

    typedef allocator<int>                  allocator_type;
    typedef allocator_type::difference_type difference_type;
    typedef allocator_type::size_type       size_type;
    typedef allocator_type::value_type      value_type;
    typedef allocator_type::pointer         pointer;

    {
          allocator_type a;
    const value_type     v = 2;
    const pointer        p = a.allocate(1);
    a.construct(p, v);
    assert(*p == v);
    a.destroy(p);
    a.deallocate(p, 1);
    }

    {
          allocator_type  a;
    const value_type      v = 2;
    const difference_type s = 10;
          pointer         b = a.allocate(s);
          pointer         e = b + s;
    my_uninitialized_fill(a, b, e, v);
    assert(std::count(b, e, v) == s);
    my_destroy(a, b, e);
    a.deallocate(b, s);
    }

    {
    typedef typename allocator_type::template rebind<double>::other allocator_type_2;
    typedef typename allocator_type_2::pointer                      pointer_2;
    typedef typename allocator_type_2::value_type                   value_type_2;
          allocator_type_2 a;
    const value_type_2     w = 2.34;
    const pointer_2        p = a.allocate(1);
    a.construct(p, w);
    assert(*p == w);
    a.destroy(p);
    a.deallocate(p, 1);
    }

    {
    const allocator_type x;
    const allocator_type y;
    assert(x == y);
    assert(!(x != y));
    }

    cout << "Done." << endl;
    return 0;}
