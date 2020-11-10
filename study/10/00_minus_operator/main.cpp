#include <iostream>

class Point {
    int _x;
    int _y;

public:
    Point(int x, int y);
    ~Point();

    Point operator-(const Point& other);
};

Point::Point(int x, int y) {
    _x = x;
    _y = y;
}

Point::~Point() {
}

Point Point::operator-(const Point& other) {
    return Point(_x - other._x, _y - other._y);
}

int main() {
    Point p1(3, 4), p2(1, 2);
    Point p3 = p1 - p2;
}
