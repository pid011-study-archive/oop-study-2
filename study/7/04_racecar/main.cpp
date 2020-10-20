#include <iostream>
using namespace std;

class Car {
private:
    int _carnumber;
    double _gas;

public:
    Car(int carnumber, double gas) : _carnumber(carnumber), _gas(gas) { }

    virtual void show() const {
        cout << "자동차의 번호: " << _carnumber << '\n';
        cout << "자동차의 가솔린양: " << _gas << endl;
    }

protected:
    int get_carnumber() const {
        return _carnumber;
    }

    double get_gas() const {
        return _gas;
    }
};

class RaceCar : public Car {
private:
    int _course;

public:
    RaceCar(int carnumber, double gas, int course) : Car(carnumber, gas), _course(course) { }

    virtual void show() const {
        cout << "자동차의 번호: " << get_carnumber() << '\n';
        cout << "자동차의 가솔린양: " << get_gas() << '\n';
        cout << "코스 번호: " << _course << endl;
    }
};

int main(int, char**) {
    Car* cars[] = { new Car(4352, 35.5), new RaceCar(4344, 32.1, 3) };
    for (size_t i = 0; i < 2; i++) {
        cout << "----------------------\n";
        cars[i]->show();
        cout << "----------------------\n";
    }

    for (size_t i = 0; i < 2; i++) {
        delete cars[i];
    }
}
