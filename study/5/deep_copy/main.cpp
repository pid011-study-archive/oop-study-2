#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

class Student {
private:
    char* _id;
    char* _name;
    int _score_kor;
    int _score_math;

    void init(const char* id, const char* name, int score_kor, int score_math) {
        _id = new char[strlen(id) + 1];
        strcpy(_id, id);

        _name = new char[strlen(name) + 1];
        strcpy(_name, name);

        _score_kor = score_kor;
        _score_math = score_math;
    }

public:
    Student(const char* id, const char* name, int score_kor, int score_math) {
        init(id, name, score_kor, score_math);
    }

    Student(const Student& copy) {
        init(copy._id, copy._name, copy._score_kor, copy._score_math);
    }

    ~Student() {
        delete[] _id;
        delete[] _name;
    }

    void show_data() const {
        using std::cout;
        using std::endl;

        cout << "ID: " << _id << endl
             << "Name: " << _name << endl
             << "Korean score: " << _score_kor << endl
             << "Math score: " << _score_math << endl;
    }
};

int main(int, char**) {
    char mid[10], mname[20];
    int mkor, mmath;

    std::cin >> mid >> mname >> mkor >> mmath;
    Student std1(mid, mname, mkor, mmath);
    Student std2(std1);

    std::cout << "----------------" << std::endl;
    std1.show_data();
    std::cout << "----------------" << std::endl;
    std2.show_data();
    std::cout << "----------------" << std::endl;
}
