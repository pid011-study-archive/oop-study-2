#include <iostream>
using namespace std;

template<class T>
T sum_array(T arr[], size_t len) {
    T sum {};

    for (size_t i = 0; i < len; i++) {
        sum += arr[i];
    }
    return sum;
}

int main() {
    int arr1[] = { 10, 20, 30 };
    cout << sum_array(arr1, sizeof(arr1) / sizeof(int)) << endl;
    double arr2[] = { 10.2, 20.3, 30.8 };
    cout << sum_array(arr2, sizeof(arr2) / sizeof(double)) << endl;
}
