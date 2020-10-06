#include <iostream>
#include <string>

using std::string;

class Student {
private:
    static int s_count;

    string _name;
    string _student_number;

public:
    Student(string name, string student_number) {
        _name = name;
        _student_number = student_number;

        s_count++;
    }

    ~Student() {
        s_count--;
    }

    static int get_student_count() {
        return s_count;
    }
};

int Student::s_count = 0;

int main(int, char**) {
    using namespace std;

    Student* p1 = new Student("aaa", "123");
    Student p2("bbb", "456");
    cout << Student::get_student_count() << endl; // 2
    delete p1;
    cout << Student::get_student_count() << endl; // 1
}
