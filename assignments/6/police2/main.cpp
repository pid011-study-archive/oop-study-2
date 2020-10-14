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

public:
    Police(int bnum, int bcuff) : _handcuffs(bcuff) {
        if (bnum > 0) {
            _gun = new Gun(bnum);
        }
    }

    ~Police() {
        if (_gun) {
            delete _gun;
        }
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
    pman1.shot();
    pman1.put_handcuff();
    pman1.show_bullet();
    pman1.show_handcuff();

    cout << endl;

    Police pman2(0, 2);
    pman2.shot();
    pman2.put_handcuff();
    pman2.show_bullet();
    pman2.show_handcuff();
}
