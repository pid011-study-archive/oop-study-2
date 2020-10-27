#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

class Vehicle {
protected:
    int _speed;

public:
    Vehicle(int speed) {
        _speed = speed;
    }

    virtual void Show() = 0;
};

class Plane : public Vehicle {
protected:
    char* _flight;

public:
    Plane(const char* flight, int speed) : Vehicle(speed) {
        size_t flight_len = strlen(flight) + 1;
        _flight = new char[flight_len];
        strncpy(_flight, flight, flight_len);
    }

    ~Plane() {
        if (_flight) {
            delete[] _flight;
        }
    }

    virtual void Show() {
        cout << "<비행기>" << endl;
        cout << "편명: " << _flight << endl;
        cout << "속도: " << _speed << endl;
    }
};

class Car : public Vehicle {
protected:
    char* _number;
    double _gasoline;

public:
    Car(const char* number, int speed, double gasoline) : Vehicle(speed) {
        size_t number_len = strlen(number) + 1;
        _number = new char[number_len];
        strncpy(_number, number, number_len);

        _gasoline = gasoline;
    }

    ~Car() {
        if (_number) {
            delete[] _number;
        }
    }

    virtual void Show() {
        cout << "<자동차>" << endl;
        cout << "번호판: " << _number << endl;
        cout << "가솔린양: " << _gasoline << endl;
        cout << "속도: " << _speed << endl;
    }
};

int main() {
    Vehicle* pv[2] = { new Car("14 더 8604", 80, 25.5), new Plane("KE940", 500) };

    for (int i = 0; i < 2; i++)
        pv[i]->Show();
    for (int i = 0; i < 2; i++)
        delete pv[i];
    return 0;
}
