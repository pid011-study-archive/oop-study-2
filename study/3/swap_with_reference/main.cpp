#include <iostream>

void swap(int& a, int& b)
{
    int tmp = a;
    a = b;
    b = tmp;
}

int main()
{
    using std::cout;

    int a = 10, b = 20;
    cout << "Before: " << a << ", " << b << '\n';
    swap(a, b);
    cout << "After: " << a << ", " << b << '\n';
}