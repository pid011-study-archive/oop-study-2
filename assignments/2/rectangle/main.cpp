#include <iostream>
#include <string>

class Point
{
public:
    const int x;
    const int y;

    Point(int x, int y) : x(x), y(y) {}

    std::string to_string() const
    {
        return "(" + std::to_string(this->x) + ", " + std::to_string(this->y) + ")";
    }
};


class Rectangle
{
public:
    const Point p1;
    const Point p2;

    Rectangle(Point p1, Point p2) : p1(p1), p2(p2) {}

    int calculate_area() const
    {
        using std::abs;

        int h = p2.y - p1.y;
        int w = p2.x - p1.x;

        return abs(h * w);
    }
};

int main()
{
    Rectangle rect = Rectangle(Point(1, 2), Point(-4, 5));

    std::cout
        << "point 1: " << rect.p1.to_string() << std::endl
        << "point 2: " << rect.p2.to_string() << std::endl;

    std::cout << std::endl;

    std::cout << "area: " << rect.calculate_area() << std::endl;
}
