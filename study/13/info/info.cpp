#include <iostream>
using namespace std;

template<class T>
class Info {
    T data;

public:
    void getData();
    void showData();
};

template<class T>
void Info<T>::getData() {
    cin >> data;
}

template<class T>
void Info<T>::showData() {
    cout << "값: " << data << endl;
}

int main() {
    Info<int> i {};
    Info<double> d {};
    Info<char> ch {};

    cout << "정수입력: ";
    i.getData();
    cout << "실수입력: ";
    d.getData();
    cout << "문자입력: ";
    ch.getData();

    i.showData();
    d.showData();
    ch.showData();
}
