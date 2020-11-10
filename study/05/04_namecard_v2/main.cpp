#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

enum class Position {
    Junior,
    Senior,
    Manager
};

std::string position_to_string(Position pos) {
    switch (pos) {
    case Position::Junior:
        return "Junior";
    case Position::Senior:
        return "Senior";
    case Position::Manager:
        return "Manager";
    default:
        return "--";
    }
}

class NameCard {
public:
    NameCard(const char* name, const char* company, const char* phone_number, Position position) {
        init(name, company, phone_number, position);
    }

    NameCard(const NameCard& copy) {
        init(copy._name, copy._company, copy._phone_number, copy._position);
    }

    ~NameCard() {
        delete[] _name;
        delete[] _company;
        delete[] _phone_number;
    }

    const char* get_name() const {
        return _name;
    }

    const char* get_company() const {
        return _company;
    }

    const char* get_phone_number() const {
        return _phone_number;
    }

    Position get_position() const {
        return _position;
    }

    void show_namecard() const {
        cout << "Name: " << get_name() << endl
             << "Company: " << get_company() << endl
             << "Phone number: " << get_phone_number() << endl
             << "Position: " << position_to_string(get_position()) << endl;
    }

private:
    char* _name;
    char* _company;
    char* _phone_number;
    Position _position;

    void init(const char* name, const char* company, const char* phone_number, Position position) {
        size_t name_len = strlen(name);
        _name = new char[name_len + 1];
        strcpy(_name, name);

        size_t company_len = strlen(company);
        _company = new char[company_len + 1];
        strcpy(_company, company);

        size_t phone_number_len = strlen(phone_number);
        _phone_number = new char[phone_number_len + 1];
        strcpy(_phone_number, phone_number);

        _position = position;
    }
};

int main() {
    NameCard man1("aaa", "b company", "123456789", Position::Junior);
    NameCard copy1(man1);
    NameCard man2("bbb", "e company", "345346", Position::Senior);
    NameCard copy2(man2);
    NameCard man3("ccc", "r company", "45625454", Position::Manager);
    NameCard copy3(man3);

    cout << "-------------------------------" << endl;
    man1.show_namecard();
    cout << "-------------------------------" << endl;
    man2.show_namecard();
    cout << "-------------------------------" << endl;
    man3.show_namecard();
    cout << "-------------------------------" << endl;
}
