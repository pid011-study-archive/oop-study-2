#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

class Score {
    char* _name = nullptr;
    int _korean{0};
    int _english{0};

    void set_name(const char* name) {
        delete[] _name;
        _name = new char[strlen(name) + 1];
        strncpy(_name, name, strlen(name) + 1);
    }

    friend istream& operator>>(istream&, Score&);
    friend ostream& operator<<(ostream&, Score&);

public:
    ~Score() {
        delete[] _name;
    }

    const char* name() const {
        return _name;
    }

    int korean() const {
        return _korean;
    }

    int english() const {
        return _english;
    }
};

istream& operator>>(istream& is, Score& score) {
    cout << "이름: ";
    char name[100];
    cin >> name;
    score.set_name(name);

    cout << "국어: ";
    cin >> score._korean;
    cout << "영어: ";
    cin >> score._english;

    return is;
}

ostream& operator<<(ostream& os, Score& score) {
    os << score.name() << ": " << score.korean() << ", " << score.english();
    return os;
}

int main() {
    Score score;
    cin >> score;
    cout << score;
}
