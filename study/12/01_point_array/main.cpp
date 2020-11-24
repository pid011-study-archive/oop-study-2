#include <iostream>
using namespace std;

class Point {
    int xpos, ypos;

public:
    Point(int x = 0, int y = 0) : xpos(x), ypos(y) { }
    friend ostream& operator<<(ostream& os, const Point& pos);
};

ostream& operator<<(ostream& os, const Point& pos) {
    os << "(" << pos.xpos << ", " << pos.ypos << ")";
    return os;
}

class BoundCheckPointArray {
    Point* arr;
    int arrlen;

public:
    BoundCheckPointArray(int len) : arrlen(len) {
        arr = new Point[len];
    }

    Point& operator[](int idx) {
        return arr[idx];
    }

    int getArrLen() const {
        return arrlen;
    }

    ~BoundCheckPointArray() {
        delete[] arr;
    }
};

int main() {
    BoundCheckPointArray arr(3);
    arr[0] = Point(3, 4);
    arr[1] = Point(2, 8);
    arr[2] = Point(7, 5);
    for (int i = 0; i < arr.getArrLen(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
