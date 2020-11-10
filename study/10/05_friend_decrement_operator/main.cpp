#include <iostream>
using namespace std;

class Int {
private:
    int _n;

public:
    Int(int n)
        : _n(n) { }
    int n() const {
        return _n;
    }

    friend Int& operator--(Int&);
    friend const Int operator--(Int&, int);
};

Int& operator--(Int& n) {
    n._n--;
    return n;
}

const Int operator--(Int& n, int) {
    const Int tmp = n;
    --n;
    return tmp;
}

int main() {
    Int num1(10), num2(10);
    Int num3 = (--num1);
    Int num4 = (num2--);

    cout << num3.n() << endl;
    cout << num4.n() << endl;
}
