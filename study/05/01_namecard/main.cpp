#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

enum class Position {
    Junior,
    Senior,
    Manager
};

class NameCard {
public:
    NameCard(const char* name,
             const char* company,
             const char* phone_number,
             Position position) {
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

private:
    char* _name;
    char* _company;
    char* _phone_number;
    Position _position;
};

std::string position_to_string(Position pos) {
    switch (pos) {
    case Position::Junior:
        return "Junior";
    case Position::Senior:
        return "Senior";
    case Position::Manager:
        return "Manager";
    }
}

int main() {
    NameCard people[] = {
        NameCard("aaa", "b company", "123456789", Position::Junior),
        NameCard("bbb", "e company", "345346", Position::Senior),
        NameCard("ccc", "r company", "45625454", Position::Manager),
    };

    for (size_t i = 0; i < 3; i++) {
        cout << people[i].get_name() << " "
             << people[i].get_company() << " "
             << people[i].get_phone_number() << " "
             << position_to_string(people[i].get_position()) << " "
             << endl;
    }
}
