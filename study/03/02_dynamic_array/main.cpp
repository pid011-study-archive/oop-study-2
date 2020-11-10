#include <iostream>

int main() {
    int len = 10;
    int* a  = new int[len];
    for (int i = 0; i < len; i++) {
        a[i] = i + 1;
    }

    for (int i = 0; i < len; i++) {
        std::cout << a[i] << (i < len - 1 ? ", " : "\n");
    }

    delete[] a;
}
