#include <iostream>

class Example
{
public:
    void Print()
    {
        std::cout << "Hello, World!" << std::endl;
    }

    void Print() const
    {
        std::cout << "Hello, World! (const)" << std::endl;
    }
};

int main()
{
    Example e1;
    const Example e2;

    e1.Print();
    e2.Print();
}
