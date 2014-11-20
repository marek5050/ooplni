// ----------------
// BackInserter.c++
// ----------------

#include <algorithm> // copy
#include <cassert>   // assert
#include <iostream>  // cout, endl
#include <iterator>  // back_insert_iterator, back_inserter, iterator, output_iterator_tag
#include <vector>    // vector

/*
namespace std {

template <typename II, typename OI>
OI copy (II b, II e, OI x) {
    while (b != e) {
        *x = *b;
        ++b;
        ++x;}
    return x;}

} // std
*/

template <typename C>
class my_back_insert_iterator {
    public:
        typedef std::output_iterator_tag iterator_category;
        typedef void                     value_type;
        typedef void                     difference_type;
        typedef void                     pointer;
        typedef void                     reference;

    private:
        C& _c;

    public:
        explicit my_back_insert_iterator (C& c) :
              _c (c)
            {}

        // Default copy, destructor, and copy assignment.
        // my_back_insert_iterator (const my_back_insert_iterator&);
        // ~my_back_insert_iterator ();
        // my_back_insert_iterator& operator = (const my_back_insert_iterator&);

        my_back_insert_iterator& operator = (typename C::const_reference v) {
            _c.push_back(v);
            return *this;}

        my_back_insert_iterator& operator * () {
            return *this;}

        my_back_insert_iterator& operator ++ () {
            return *this;}

        my_back_insert_iterator operator ++ (int) {
            return *this;}};

template <typename C>
my_back_insert_iterator<C> my_back_inserter (C& x) {
    return my_back_insert_iterator<C>(x);}

int main () {
    using namespace std;
    cout << "BackInserter.c++" << endl;

    {
    const vector<int> x = {5, 6};
          vector<int> y = {2, 3, 4};
    copy(x.begin(), x.end(), my_back_inserter(y));
    assert(y == vector<int>({2, 3, 4, 5, 6}));
    }

    {
    const vector<int>                            x = {5, 6};
          vector<int>                            y = {2, 3, 4};
          my_back_insert_iterator< vector<int> > z(y);
    copy(x.begin(), x.end(), z);
    assert(y == vector<int>({2, 3, 4, 5, 6}));
    }

    {
    const vector<int> x = {5, 6};
          vector<int> y = {2, 3, 4};
    copy(x.begin(), x.end(), back_inserter(y));
    assert(y == vector<int>({2, 3, 4, 5, 6}));
    }

    {
    const vector<int>                         x = {5, 6};
          vector<int>                         y = {2, 3, 4};
          back_insert_iterator< vector<int> > z(y);
    copy(x.begin(), x.end(), z);
    assert(y == vector<int>({2, 3, 4, 5, 6}));
    }

    cout << "Done." << endl;
    return 0;}
