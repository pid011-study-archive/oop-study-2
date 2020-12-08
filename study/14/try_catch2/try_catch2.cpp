#include <iostream>

int main() {
    using namespace std;

    bool check = false;
    while (!check) {
        try {
            cout << "a: ";
            double a;
            cin >> a;

            if (a < 0) {
                throw a;
            }

            cout << "b: ";
            double b;
            cin >> b;

            if (b == 0) {
                throw "b는 0이 될 수 없습니다.";
            }

            if (b < 0) {
                throw b;
            }

            cout << "a / b = " << (a / b) << endl;
            cout << "a * b = " << (a * b) << endl;
            check = true;

        } catch (const char* e) {
            cout << e << endl;
        } catch (double e) {
            cout << e << "은 허용되지 않는 수입니다." << endl;
        }
    }
}
