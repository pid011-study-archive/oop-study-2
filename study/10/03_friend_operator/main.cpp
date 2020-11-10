#include <iostream>
#include <string>

class Point {
    int _x;
    int _y;

public:
    Point(int x, int y)
        : _x(x), _y(y) { }

    std::string to_string() const {
        return "(" + std::to_string(_x) + ", " + std::to_string(_y) + ")";
    }

    friend Point operator-(const Point& p1, const Point& p2);
    friend bool operator==(const Point& p1, const Point& p2);
    friend bool operator!=(const Point& p1, const Point& p2);
};

Point operator-(const Point& p1, const Point& p2) {
    return Point(p1._x - p2._x, p1._y - p2._y);
}

bool operator==(const Point& p1, const Point& p2) {
    return p1._x == p2._x && p1._y == p2._y;
}

bool operator!=(const Point& p1, const Point& p2) {
    return !(p1 == p2);
}

int main() {
    Point p1(1, 2), p2(3, 3);
    std::cout << p1.to_string() << " " << p2.to_string() << std::endl;
    std::cout << std::boolalpha;

    std::cout << (p2 - p1).to_string() << std::endl;
    std::cout << (p1 == p2) << std::endl;
    std::cout << (p1 != p2) << std::endl;
}
