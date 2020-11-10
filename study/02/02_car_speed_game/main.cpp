#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

class Car {
public:
    Car(string gamer_id) {
        this->gamer_id      = gamer_id;
        this->fuel_gauge    = 100;
        this->current_speed = 0;
    }

    string get_gamer_id() { return this->gamer_id; }

    int get_fuel_guage() { return this->fuel_gauge; }

    int get_current_speed() { return this->current_speed; }

    void use_accel();
    void use_break();
    void show_status();

private:
    string gamer_id;
    int fuel_gauge;
    int current_speed;
};

void Car::use_accel() {
    this->fuel_gauge -= 10;
    this->current_speed += 10;
}

void Car::use_break() {
    this->fuel_gauge -= 10;
    this->current_speed = 0;
}

void Car::show_status() {
    cout << gamer_id << endl
         << "- current fuel gauge : " << this->fuel_gauge << endl
         << "- current speed : " << this->current_speed << endl;
}

int main() {
    cout << "Enter your id.\n> ";
    string id;
    std::getline(cin, id);

    Car* car_info = new Car(id);

    cout << "Start!" << endl;

    while (car_info->get_fuel_guage() > 0) {
        cout << "> ";

        string input;
        std::getline(cin, input);
        if (input == "a" || input == "accel") {
            car_info->use_accel();
        } else if (input == "b" || input == "break") {
            car_info->use_break();
        } else {
            cout << "Wrong command." << endl;
        }

        car_info->show_status();
    }

    cout << "Fuel is empty." << endl;

    delete car_info;
}
