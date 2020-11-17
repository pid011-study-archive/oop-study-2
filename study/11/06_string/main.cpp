#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <iostream>
using namespace std;

class String {
    char* _str{nullptr};
    int _str_len{0};

    void set_str(const char* value) {
        delete[] _str;
        size_t len = strlen(value) + 1;
        _str_len = int(len) - 1;
        _str = new char[len];
        strncpy(_str, value, len);
    }

public:
    String(const char* str) {
        set_str(str);
    }

    ~String() {
        delete[] _str;
    }

    int length() const {
        return _str_len;
    }

    char& operator[](int idx) {
        if (idx < 0 && idx >= _str_len) {
            return _str[_str_len]; // '\n'
        }
        return _str[idx];
    }
};

int main() {
    String obj("Happy Day");
    for (int i = 0; i < obj.length(); i++) {
        cout << obj[i] << endl;
    }
}
