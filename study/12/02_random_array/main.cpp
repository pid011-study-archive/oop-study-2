#include <iostream>
#include <random>
using namespace std;

class CArray {
    int* _array;
    size_t _len;

public:
    CArray(size_t len) : _len(len) {
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<int> dis(0, 9);
        _array = new int[len];
        for (size_t i = 0; i < len; i++) {
            _array[i] = dis(gen);
        }
    }

    friend ostream& operator<<(ostream& os, const CArray& array);

    int operator[](size_t idx) {
        if (idx > _len) {
            return _array[0];
        }
        return _array[idx];
    }

    ~CArray() {
        delete[] _array;
    }
};

ostream& operator<<(ostream& os, const CArray& array) {
    for (size_t i = 0; i < array._len; i++) {
        os << array._array[i];
        if (i < array._len - 1) {
            os << " ";
        }
    }
    return os;
}

int main() {
    CArray array(5);
    cout << array << endl;

    cout << array[10] << endl;
}
