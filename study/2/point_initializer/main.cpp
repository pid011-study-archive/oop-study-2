#include <iostream>
#include <string>

class Point
{
public:
    Point()
    {
        this->x = 0;
        this->y = 0;
    }

    int get_x()
    {
        return this->x;
    }

    int get_y()
    {
        return this->y;
    }

    std::string to_string()
    {
        return "(" + std::to_string(this->x) + ", " + std::to_string(this->y) + ")";
    }

private:
    int x;
    int y;
};

int main()
{
    Point p;
    std::cout << p.to_string() << std::endl;
}
