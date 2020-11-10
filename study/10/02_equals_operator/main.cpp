#include <iostream>
#include <string>

class Point {
    int _x;
    int _y;

public:
    Point(int x, int y)
        : _x(x), _y(y) { }

    bool operator==(const Point& other) {
        return _x == other._x && _y == other._y;
    }

    bool operator!=(const Point& other) {
        return !(*this == other);
    }

    std::string to_string() const {
        return "(" + std::to_string(_x) + ", " + std::to_string(_y) + ")";
    }
};

int main() {
    Point p1(1, 2), p2(3, 3);
    std::cout << p1.to_string() << " " << p2.to_string() << std::endl;
    std::cout << std::boolalpha;

    std::cout << (p1 == p2) << std::endl;
    std::cout << (p1 != p2) << std::endl;
}
