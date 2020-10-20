#include <iostream>
using namespace std;

class Shape {
public:
    Shape() { }
    virtual ~Shape() { }
    virtual double size() = 0;
};

class Rectangle : public Shape {
public:
    Rectangle(int w, int h) : Width(w), Height(h) { }

    virtual double size() {
        return Width * Height;
    }

protected:
    int Width;
    int Height;
};

class Circle : public Shape {
public:
    Circle(int r) : Radius(r) { }

    virtual double size() {
        return Radius * Radius * 3.141592;
    }

protected:
    int Radius;
};

int main(int, char**) {
    Shape* rect = new Rectangle(2, 4);
    Shape* circle = new Circle(4);

    cout << "rect w: 2, h: 4 -> " << rect->size() << endl;
    cout << "circle r: 4 -> " << circle->size() << endl;

    delete rect;
    delete circle;
}
