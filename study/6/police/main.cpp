#include <iostream>

using namespace std;

class Gun {
private:
    int _bullet;

public:
    Gun(int bnum)
        : _bullet(bnum) { }
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

class Police : public Gun {
private:
    int _handcuffs;

public:
    Police(int bnum, int bcuff)
        : Gun(bnum), _handcuffs(bcuff) { }
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
};

int main(int, char**) {
    Police pman(5, 3);
    pman.shot();
    pman.put_handcuff();
    pman.show_bullet();
    pman.show_handcuff();
}
