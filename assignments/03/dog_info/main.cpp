#include <iostream>

using namespace std;

class Dog {
public:
    Dog(const char* name, int age, int weight) {
        size_t len = strlen(name) + 1; // 마지막에 '\0' 포함
        this->name = new char[len];
        strcpy_s(this->name, len, name);
        this->age    = new int(age);
        this->weight = new int(weight);
    }

    ~Dog() {
        delete[] name;
        delete age;
        delete weight;
    }

    void show_info() const {
        cout << name << "\n\t"
             << "Age: " << *age << "\n\t"
             << "Weight: " << *weight << endl;
    }

private:
    char* name;
    int* age;
    int* weight;
};

int main() {
    Dog* happy    = new Dog("해피", 3, 4);
    Dog* zzong_ee = new Dog("쫑이", 4, 5);
    Dog* ddol_ee  = new Dog("똘이", 2, 7);

    happy->show_info();
    zzong_ee->show_info();
    ddol_ee->show_info();

    delete happy;
    delete zzong_ee;
    delete ddol_ee;
}
