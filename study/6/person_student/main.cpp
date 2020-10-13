#include <cstring>
#include <iostream>

class Person {
private:
    char* _name;

public:
    Person(const char* name) {
        _name = new char[strlen(name) + 1];
        strcpy(_name, name);
    }
    ~Person() {
        delete[] _name;
    }

    const char* get_name() const {
        return _name;
    }
};

class Student : public Person {
private:
    char* _major;

public:
    Student(const char* name, const char* major)
        : Person(name) {
        _major = new char[strlen(major) + 1];
        strcpy(_major, major);
    }
    ~Student() {
        delete[] _major;
    }

    const char* get_major() const {
        return _major;
    }
};

void show_info(Student& s) {
    using std::cout;
    cout << "이름: " << s.get_name() << '\n'
         << "학과: " << s.get_major() << '\n';
}

int main() {
    Student student1("장동건", "수학과");
    Student student2("아이유", "게임학과");
    show_info(student1);
    std::cout << "------------------------\n";
    show_info(student2);
}
