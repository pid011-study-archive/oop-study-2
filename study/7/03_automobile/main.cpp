#include <iostream>
using namespace std;

class Car {
protected:
    string CarNumber;
    string Factory;

public:
    Car(string carnumber, string factory) : CarNumber(carnumber), Factory(factory) { }

    virtual void show() const {
        cout << "차량번호: " << CarNumber << '\n';
        cout << "제조사: " << Factory << endl;
    }
};

class Automobile : public Car {
protected:
    string Model;

public:
    Automobile(string carnumber, string factory, string model) : Car(carnumber, factory), Model(model) { }

    virtual void show() const {
        cout << "차량번호: " << CarNumber << '\n';
        cout << "제조사: " << Factory << '\n';
        cout << "모델명: " << Model << endl;
    }
};

int main(int, char**) {
    Automobile* am[3] {
        new Automobile("14다 4399", "기아", "K5"),
        new Automobile("10가 1234", "기아", "K7"),
        new Automobile("13가 5555", "기아", "K9"),
    };

    for (size_t i = 0; i < 3; i++) {
        cout << "---------------------\n";
        am[i]->show();
        cout << "---------------------\n";
    }

    for (size_t i = 0; i < 3; i++) {
        delete am[i];
    }
}
