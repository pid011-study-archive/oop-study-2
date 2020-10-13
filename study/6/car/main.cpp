#include <iostream>

class Car {
private:
    int _gasoline_gauge;

public:
    Car(int gasoline_gauge) {
        _gasoline_gauge = gasoline_gauge;
    }

    int get_gasoline_gauge() const {
        return _gasoline_gauge;
    }
};

class HybridCar : public Car {
private:
    int _electric_gauge;

public:
    HybridCar(int gasoline_gauge, int electric_gauge)
        : Car(gasoline_gauge) {
        _electric_gauge = electric_gauge;
    }

    int get_electric_gauge() const {
        return _electric_gauge;
    }
};

class HybridWaterCar : public HybridCar {
private:
    int _water_gauge;

public:
    HybridWaterCar(int gasoline_gauge, int electric_gauge, int water_gauge)
        : HybridCar(gasoline_gauge, electric_gauge) {
        _water_gauge = water_gauge;
    }

    void show_current_gauge() const {
        using std::cout;
        using std::endl;

        cout << "잔여가솔린: " << get_gasoline_gauge() << endl;
        cout << "잔여전기량: " << get_electric_gauge() << endl;
        cout << "잔여워터량: " << _water_gauge << endl;
    }
};

int main(int, char**) {
    HybridWaterCar hbcar(79, 65, 34);
    hbcar.show_current_gauge();
}
