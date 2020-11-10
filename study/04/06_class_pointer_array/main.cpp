#include <iostream>

class Person {
public:
    Person(std::string name, int age) {
        _name = name;
        _age = age;
    }

    ~Person() { }

    void show() const {
        std::cout << _name << " : Age - " << _age << std::endl;
    }

private:
    std::string _name;
    int _age;
};



int main() {
    Person* p[3] = { new Person("James", 20), new Person("Allice", 21), new Person("John", 22) };

    for (size_t i = 0; i < 3; i++) {
        p[i]->show();
    }

    for (size_t i = 0; i < 3; i++) {
        delete p[i];
    }
}
