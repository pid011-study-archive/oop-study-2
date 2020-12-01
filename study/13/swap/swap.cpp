#include <iostream>
using namespace std;

template<class T>
void custom_swap(T& a, T& b) {
    T temp = a;
    a = b;
    b = temp;
}

int main() {
    int x = 3, y = 10;
    float fx = 10.3f, fy = 21.3f;
    char cx = 'A', cy = 'Z';
    custom_swap<int>(x, y);
    cout << x << ", " << y << endl;

    custom_swap<float>(fx, fy);
    cout << fx << ", " << fy << endl;

    custom_swap<char>(cx, cy);
    cout << cx << ", " << cy << endl;
}
