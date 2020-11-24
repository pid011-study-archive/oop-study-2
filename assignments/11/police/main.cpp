#include <iostream>

using namespace std;

class Gun {
private:
    int _bullet;

public:
    Gun(int bnum) : _bullet(bnum) { }
    void shot() {
        if (_bullet <= 0) {
            cout << "총알이 없음" << endl;
        } else {
            cout << "총을 쏘다" << endl;
            _bullet--;
        }
    }

    int bullet() const {
        return _bullet;
    }

    void show_bullet() {
        cout << "남은 총알의 개수: " << _bullet << endl;
    }
};

class Police {
private:
    int _handcuffs;
    Gun* _gun = nullptr;

    bool check_gun() {
        if (!_gun) {
            cout << "권총을 소유하고 있지 않음" << endl;
            return false;
        }
        return true;
    }

    void set_gun(int bnum) {
        delete _gun;
        _gun = new Gun(bnum);
    }

public:
    Police(int bnum, int bcuff) : _handcuffs(bcuff) {
        if (bnum > 0) {
            set_gun(bnum);
        }
    }

    Police(Police& copy) {
        set_gun(copy._gun->bullet());
        _handcuffs = copy._handcuffs;
    }

    ~Police() {
        delete _gun;
    }

    Police& operator=(const Police& copy) {
        set_gun(copy._gun->bullet());
        _handcuffs = copy._handcuffs;
        return *this;
    }

    void put_handcuff() {
        if (_handcuffs <= 0) {
            cout << "수갑이 없음" << endl;
        } else {
            cout << "수갑을 쓰다" << endl;
            _handcuffs--;
        }
    }

    void show_handcuff() {
        cout << "남은 수갑의 개수: " << _handcuffs << endl;
    }

    void shot() {
        if (check_gun()) {
            _gun->shot();
        }
    }

    void show_bullet() {
        if (check_gun()) {
            _gun->show_bullet();
        }
    }
};

int main(int, char**) {
    Police pman1(5, 3);
    Police pman2 = pman1;
    pman2.put_handcuff();
    pman2.shot();

    Police pman3(2, 4);
    pman3 = pman1;
    pman3.put_handcuff();
    pman3.shot();
}
