#include <iostream>
using namespace std;

class Sqaure {
protected:
    double _width;
    double _height;

public:
    Sqaure(double w, double h) : _width(w), _height(h) { }

    double area() const {
        return _width * _height;
    }
};

class Cube : public Sqaure {
private:
    double _depth;

public:
    Cube(double w, double h, double d) : Sqaure(w, h), _depth(d) { }

    double volume() const {
        return _width * _height * _depth;
    }
};

int main(int, char**) {
    Cube cube(2, 2, 3);
    cout << "w: 2, h: 2, d: 3 -> depth = " << cube.volume() << endl;
}
