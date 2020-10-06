#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

class Dog {
private:
    char* _name;
    int _age;
    int _weight;

    void init(const char* name, int age, int weight) {
        _name = new char[strlen(name) + 1];
        strcpy(_name, name);

        _age = age;
        _weight = weight;
    }

public:
    Dog(const char* name, int age, int weight) {
        init(name, age, weight);
    }

    Dog(const Dog& copy) {
        init(copy._name, copy._age, copy._weight);
    }

    ~Dog() {
        delete[] _name;
    }

    void show_data() const {
        using std::cout;
        using std::endl;

        cout << "Name: " << _name << endl
             << "Age: " << _age << endl
             << "Weight: " << _weight << endl;
    }
};

int main(int, char**) {
    Dog obj1("happy", 3, 4);
    Dog obj2(obj1);

    std::cout << "----------------" << std::endl;
    obj1.show_data();
    std::cout << "----------------" << std::endl;
    obj2.show_data();
    std::cout << "----------------" << std::endl;
}
