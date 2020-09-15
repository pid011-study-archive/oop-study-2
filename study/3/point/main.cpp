#include <iostream>
#include <string>

class Point
{
public:
    const int x;
    const int y;

    Point(int x, int y) : x(x), y(y) { }

    std::string to_string() const 
    {
        return "(x:" + std::to_string(x) + ", y:" + std::to_string(y) + ")";
    }
};

int main()
{
    Point* p = new Point(3, 10);
    std::cout << p->to_string() << std::endl;
    delete p;
}