#include <iostream>

class Dog {
public:
    Dog(char* name, unsigned int age, unsigned int weight) {
        strcpy_s(this->name, 20, name);
        this->age = age;
        this->weight = weight;
    }

    Dog& set_data(char* name, unsigned int age, unsigned int weight) {
        strcpy_s(this->name, 20, name);
        this->age = age;
        this->weight = weight;

        return *this;
    }

    char* get_name() {
        return name;
    }

private:
    char name[20];
    unsigned int age;
    unsigned int weight;
};

int main() {
    Dog dog = Dog("강아지", 2, 4);

    Dog& dog2 = dog.set_data("강아지2", 1, 3);

    std::cout << dog.get_name() << std::endl;
    std::cout << dog2.get_name() << std::endl;

    dog2.set_data("강아지3", 3, 3);

    std::cout << dog.get_name() << std::endl;
    std::cout << dog2.get_name() << std::endl;
}
