#include <iostream>
#include <string>

class DepositException {
    int _failedMoney;

public:
    DepositException(int money) : _failedMoney(money) { }

    int GetFailedMoney() const {
        return _failedMoney;
    }
};

class Account {
    char accNum[50];
    int balance;

public:
    Account(const char* acc, int money) : balance(money) {
        strcpy_s(accNum, strlen(acc) + 1, acc);
    }
    void Deposit(int money) {
        if (money < 1) {
            throw DepositException(money);
        }
        balance += money;
    }
    int ShowBalance() { return balance; }
};

int main() {
    using namespace std;

    Account myAcc("1234-1234", 10000);

    try {
        myAcc.Deposit(2000);
        myAcc.Deposit(-100);
    } catch (const DepositException& e) {
        cout << "예외메시지: " << e.GetFailedMoney() << "원은 입금불가" << endl;
    }
    cout << "잔액은 " << myAcc.ShowBalance() << "원 입니다." << endl;
    return 0;
}
