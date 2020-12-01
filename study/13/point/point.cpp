#include <iostream>
using namespace std;

template<class T>
class CPoint {
    T _x;
    T _y;

public:
    CPoint(T x, T y) : _x(x), _y(y) { }
    CPoint<T> operator+(CPoint<T>& p) {
        return CPoint<T>(_x + p._x, _y + p._y);
    }

    template<class T>
    friend ostream& operator<<(ostream& output, const CPoint<T>& p);
};

template<class T>
ostream& operator<<(ostream& output, const CPoint<T>& p) {
    output << "(" << p._x << ", " << p._y << ")";
    return output;
}

int main() {
    CPoint<int> a(1, 2);
    CPoint<int> b(3, 4);
    CPoint<int> c = a + b;
    cout << a << " + " << b << " = " << c << endl;

    CPoint<double> d(1.2, 3.4);
    CPoint<double> e(5.6, 7.8);
    CPoint<double> f = d + e;
    cout << d << " + " << e << " = " << f << endl;
}
