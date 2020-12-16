#include <iostream>

using namespace std;

class StarLine {
    char type;
    int length;
    bool check;

public:
    StarLine() : type('\0'), length(0), check(false) { }

    friend istream& operator>>(istream& is, StarLine& value);
    friend ostream& operator<<(ostream& os, StarLine& value);
};

istream& operator>>(istream& is, StarLine& value) {
    cout << "출력할 특수문자 한 개를 입력하시오 : ";
    is >> value.type;
    cout << "출력할 개수를 입력하시오 : ";
    is >> value.length;

    value.check = true;

    return is;
}

ostream& operator<<(ostream& os, StarLine& value) {
    if (!value.check) {
        os << "*";
        return os;
    }

    for (int i = 0; i < value.length; i++) {
        os << value.type << ' ';
    }

    return os;
}

int main() {
    StarLine a, b, c;
    cin >> a;
    cout << a << endl;
    cin >> b;
    cout << b << endl;
    cout << c;
    return 0;
}
