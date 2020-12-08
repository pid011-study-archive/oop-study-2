#include <iostream>

int multiply() {
    using namespace std;
    cout << "a: ";
    int a;
    cin >> a;
    if (a < 0) {
        throw a;
    }

    cout << "b: ";
    int b;
    cin >> b;

    return a * b;
}

int main() {
    using namespace std;

    try {
        int r = multiply();
        cout << "result: " << r << endl;
    } catch (int e) {
        cout << "잘못된 값: " << e << endl;
    }
}
