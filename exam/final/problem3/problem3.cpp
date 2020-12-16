#include <iostream>
using namespace std;

class CPoint;
class CCircle {
    int x, y;
    double radius;

public:
    CCircle(int x, int y, double radius) : x(x), y(y), radius(radius) { }
    int get_x() const { return x; }
    int get_y() const { return y; }
};

class CPoint {
    int x, y;

public:
    CPoint() : x(0), y(0) { }
    CPoint(int x, int y) : x(x), y(y) { }
    int get_x() const { return x; }
    int get_y() const { return y; }
    friend ostream& operator<<(ostream&, CPoint&);

    CPoint& operator=(CCircle& c) {
        x = c.get_x();
        y = c.get_y();
        return *this;
    }
};

ostream& operator<<(ostream& os, CPoint& value) {
    os << "(" << value.get_x() << ", " << value.get_y() << ")" << endl;
    return os;
}

int main() {
    CPoint p1(1, 2);
    cout << p1;
    CCircle cl(10, 20, 30);

    CPoint p2;
    p2 = cl;
    cout << p2;
    return 0;
}
