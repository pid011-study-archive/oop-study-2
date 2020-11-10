#include <iostream>
#include <string>

using std::string;

class Employee {
protected:
    string _id;
    string _name;
    string _address;
    int _salary;

public:
    Employee(string id, string name, string address, int salary) {
        _id = id;
        _name = name;
        _address = address;
        _salary = salary;
    }

    void show_data() const {
        using std::cout;
        using std::endl;

        cout << _id << ". " << _name << ", " << _address << ", " << _salary << "만원" << endl;
    }
};

class Manager : protected Employee {
private:
    string _depart;

public:
    Manager(string id, string name, string address, int salary, string depart)
        : Employee(id, name, address, salary), _depart(depart) { }

    void show_data() const {
        std::cout << _id << ". " << _name << ", " << _address << ", " << _salary << "만원"
                  << ", " << _depart << std::endl;
    }
};

int main(int, char**) {
    Manager m[] = { Manager("1", "강한자", "경기도 부천시", 250, "인사과"),
                    Manager("2", "홍길동", "서울시 종로구", 280, "연구실") };
    std::cout << "사번 이름 주소 봉급\n";
    for (int i = 0; i < 2; i++) {
        m[i].show_data();
    }
}
