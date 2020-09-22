#include <iostream>

class Point {
public:
    Point(int x, int y) {
        _x = x;
        _y = y;
    }
    void show() const {
        std::cout << "(" << _x << ", " << _y << ")" << std::endl;
    }

private:
    int _x;
    int _y;
};

int main() {
    Point points[3] = { Point(10, 10), Point(20, 20), Point(30, 30) };

    for (size_t i = 0; i < 3; i++) {
        std::cout << i + 1 << ": ";

        (points + i)->show();
    }
}
