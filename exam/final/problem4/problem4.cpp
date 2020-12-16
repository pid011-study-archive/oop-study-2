#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
class Person {
private:
    char* name;
    int age;

public:
    Person(const char* myname, int myage) {
        int len = strlen(myname) + 1;
        name = new char[len];
        strcpy(name, myname);
        age = myage;
    }

    Person(const Person& copy) {
        delete[] name;
        int len = strlen(copy.name) + 1;
        name = new char[len];
        strcpy(name, copy.name);
        age = copy.age;
    }

    Person& operator=(const Person& copy) {
        delete[] name;
        int len = strlen(copy.name) + 1;
        name = new char[len];
        strcpy(name, copy.name);
        age = copy.age;

        return *this;
    }

    void ShowPersonInfo() const {
        cout << "이름 : " << name << endl;
        cout << "나이 : " << age << endl;
    }

    ~Person() {
        delete[] name;
    }
};

int main() {
    Person man1("이동수", 29);
    Person man2("김희준", 23);
    man2 = man1;
    man1.ShowPersonInfo();
    man2.ShowPersonInfo();
    Person man3 = man1;
    man3.ShowPersonInfo();
}
