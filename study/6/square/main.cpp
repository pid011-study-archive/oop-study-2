#include <iostream>

class Rectangle {
private:
    int _width;
    int _height;

public:
    Rectangle(int w, int h)
        : _width(w), _height(h) { }

    int area() const {
        return _width * _height;
    }
};

class Sqaure : public Rectangle {
public:
    Sqaure(int w)
        : Rectangle(w, w) { }
};

int main(int, char**) {
    using namespace std;

    Rectangle r(4, 3);
    cout << r.area() << endl;

    Sqaure s(7);
    cout << s.area() << endl;
}
