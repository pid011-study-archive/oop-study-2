#include <iostream>
using namespace std;

template<class T>
void sort(bool asce, T arr[], int start, int end) {
    if (start >= end) {
        return;
    }

    int key = start, i = start + 1, j = end;
    while (i <= j) {
        if (asce) {
            while (i <= end && arr[i] <= arr[key]) {
                i++;
            }

            while (j > start && arr[j] >= arr[key]) {
                j--;
            }
        } else {
            while (i <= end && arr[i] >= arr[key]) {
                i++;
            }
            while (j > start && arr[j] <= arr[key]) {
                j--;
            }
        }

        if (i > j) {
            swap(arr[key], arr[j]);
        } else {
            swap(arr[i], arr[j]);
        }
    }
    sort(asce, arr, start, j - 1);
    sort(asce, arr, j + 1, end);
}

template<class T>
void sort(bool asce, T arr[], size_t len) {
    sort(asce, arr, 0, int(len) - 1);
}

int main() {
    int val[] = { 3, 5, 1, 9, 4 };
    constexpr size_t ValLen { 5 };

    for (size_t i = 0; i < ValLen; i++) {
        cout << val[i];
    }
    cout << endl;

    sort<int>(false, val, ValLen);

    for (size_t i = 0; i < ValLen; i++) {
        cout << val[i];
    }
    cout << endl;

    cout << endl;

    char str[] = "gasgdargc";
    int n = sizeof(str) - 1 / sizeof(char);

    cout << str << endl;
    sort<char>(false, str, n);
    cout << str << endl;
}
