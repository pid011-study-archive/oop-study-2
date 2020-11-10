#include <iostream>
using namespace std;

class Number {
    int _num;

public:
    Number() : _num(0) { }
    Number(int n) : _num(n) { }

    int num() const { return _num; }

    Number operator+(Number);
    void show() const;
};

Number Number::operator+(Number other) {
    return Number(_num + other._num);
}

void Number::show() const {
    cout << _num << endl;
}

int main() {
    Number a(5), b(3), c;
    c = a + b;
    c.show();
}
