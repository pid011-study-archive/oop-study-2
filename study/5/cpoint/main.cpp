#include <iostream>

using namespace std;

class CPoint {
private:
    int _x;
    int _y;

public:
    CPoint()
        : _x(0), _y(0) { }

    CPoint(int xy)
        : _x(xy), _y(xy) { }

    CPoint(int x, int y)
        : _x(x), _y(y) { }

    CPoint(int sqaure, const CPoint& p)
        : _x(p._x * sqaure), _y(p._y * sqaure) { }

    CPoint(const CPoint& p1, const CPoint& p2)
        : _x(p1._x + p2._x), _y(p1._y + p2._y) { }

    ~CPoint() { }

    void print() const {
        cout << "[" << _x << ", " << _y << "]" << endl;
    }
};

int main(int, char**) {
    CPoint p1;
    CPoint p2(1);
    CPoint p3(2, 3);
    CPoint p4 = p3;
    CPoint p5(2, p3);
    CPoint p6(p4, p5);

    p1.print();
    p2.print();
    p3.print();
    p4.print();
    p5.print();
    p6.print();
}
