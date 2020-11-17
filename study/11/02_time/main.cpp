#include <iostream>
using namespace std;

class Time {
    int _hour{0};
    int _minute{0};
    bool _check{false};

public:
    Time(int hour, int minute) : _hour(hour), _minute(minute) { }

    void display() const {
        if (_minute == 0) {
            cout << _hour << "시 정각" << endl;
            return;
        }

        if (_check) {
            cout << _hour + 1 << "시 " << 60 - _minute << "분 전" << endl;
        } else {
            cout << _hour << "시 " << _minute << "분" << endl;
        }
    }

    const Time& operator++() {
        if (++_minute == 60) {
            _hour++;
            _minute = 0;
        }
        _check = true;
        return *this;
    }

    const Time operator++(int) {
        Time copy(*this);
        ++(*this);
        _check = false;
        return copy;
    }
};

int main() {
    Time t1(9, 58), t2(5, 30), t3(2, 59);
    ++t1;
    t1.display();

    t2++;
    t2.display();

    t3++;
    t3.display();
}
