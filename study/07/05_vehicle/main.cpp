#include <iostream>
using namespace std;

class Vehicle {
public:
    Vehicle(int speed) : Speed(speed) { }
    virtual void show() = 0;

protected:
    int Speed;
};

class Car : public Vehicle {
public:
    Car(int speed, int num, double gas) : Vehicle(speed), Number(num), Gas(gas) { }

    virtual void show() {
        cout << "번호: " << Number << ", 가솔린양: " << Gas << ", 속도: " << Speed << endl;
    }

protected:
    int Number;
    double Gas;
};

class Plane : public Vehicle {
public:
    Plane(int speed, int flight) : Vehicle(speed), Flight(flight) { }

    virtual void show() {
        cout << "편명: " << Flight << ", 속도: " << Speed << endl;
    }

protected:
    int Flight;
};

int main(int, char**) {
    Vehicle* vehicles[2];
    Car c(8604, 80, 25.5);
    vehicles[0] = &c;
    Plane p(940, 550);
    vehicles[1] = &p;

    cout << "자동차" << endl;
    vehicles[0]->show();
    cout << "비행기" << endl;
    vehicles[1]->show();
}
