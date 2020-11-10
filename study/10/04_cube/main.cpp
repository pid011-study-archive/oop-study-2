#include <iostream>
using namespace std;

class Cube {
    double _x;
    double _y;
    double _z;

public:
    Cube(double x, double y, double z)
        : _x(x), _y(y), _z(z) { }

    Cube operator+(const Cube& other) {
        double x = _x > other._x ? _x : other._x;
        double y = _y > other._y ? _y : other._y;
        double z = _z + other._z;
        return Cube(x, y, z);
    }

    void list(const char* msg) {
        cout << msg << " " << _x << ", " << _y << ", " << _z << endl;
    }
};

int main() {
    Cube c(12.2, 89.4, 5.0);
    Cube d(67.3, 53.2, 1.3);
    Cube e = c + d;
    c.list("Welcome");
    d.list("Vision");
    e.list("Passion");
}
