// -----------
// Complex.c++
// -----------

#include <cassert>  // assert
#include <iostream> // cout, endl
#include <utility>  // !=

/*
namespace std     {
namespace rel_ops {

template <typename T>
inline bool operator != (const T& lhs, const T& rhs) {
    return !(lhs == rhs);}

} // rel_ops
} // std;
*/

template <typename T>
class My_Complex {
    friend bool operator == (const My_Complex& lhs, const My_Complex& rhs) {
        return (lhs._r == rhs._r) && (lhs._i == rhs._i);}

    friend T real (const My_Complex& v) {
        return v._r;}

    friend T imag (const My_Complex& v) {
        return v._i;}

    private:
        T _r;
        T _i;

    public:
        My_Complex (const T& r = T(), const T& i = T()) :
                _r (r),
                _i (i)
            {}
/*
        My_Complex (const My_Complex& rhs) :
                _r (rhs._r),
                _i (rhs._i)
            {}

        My_Complex& operator = (const My_Complex& rhs) {
            _r = rhs._r;
            _i = rhs._i;
            return *this;}

        ~My_Complex ()
            {}
*/
        My_Complex& operator += (const My_Complex& rhs) {
            _r += rhs._r;
            _i += rhs._i;
            return *this;}

        My_Complex& conj () {
            _i = -_i;
            return *this;}};

template <typename T>
My_Complex<T> operator + (My_Complex<T> lhs, const My_Complex<T>& rhs) {
    return lhs += rhs;}

template <typename T>
My_Complex<T> conj (My_Complex<T> v) {
    return v.conj();}

int main () {
    using namespace std;
    using namespace std::rel_ops;
    cout << "Complex.c++" << endl;

    My_Complex<int> x;
    My_Complex<int> y(2);
    My_Complex<int> z(2, 3);

    assert(real(z) == 2);
    assert(imag(z) == 3);

    My_Complex<int> t(y);
    assert(t == y);

    My_Complex<int>& u = (t = z);
    assert( t ==  z);
    assert(&u == &t);

    My_Complex<int>& v = (x += y);
    assert(x == My_Complex<int>(2,  0));
    assert(&v == &x);

    v = (x + y);
    assert(v == My_Complex<int>(4,  0));

    My_Complex<int> w = conj(z);
    assert(z == My_Complex<int>(2,  3));
    assert(w == My_Complex<int>(2, -3));

    cout << "Done." << endl;
    return 0;}
