#include <iostream>
using namespace std;

class PhoneNumber {
    char _area_code[4];
    char _exchange[5];
    char _line[5];

    friend istream& operator>>(istream&, PhoneNumber&);
    friend ostream& operator<<(ostream&, PhoneNumber&);
};

istream& operator>>(istream& is, PhoneNumber& t) {
    is >> t._area_code >> t._exchange >> t._line;
    return is;
}

ostream& operator<<(ostream& os, PhoneNumber& t) {
    os << "(" << t._area_code << ")" << t._exchange << "-" << t._line;
    return os;
}

int main() {
    PhoneNumber phone;
    cin >> phone;
    cout << phone;
}
