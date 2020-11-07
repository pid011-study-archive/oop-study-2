#include "account.h"
#include <cstring>
#include <iostream>
#include <memory>

using BankSystem::Account;

Account::Account(int id, const char* name, int money, int interest_rate)
    : _id(id), _balance(money), _interest_rate(interest_rate) {
    size_t name_len = strlen(name) + 1;
    _name = new char[name_len];
    // strcpy(_name, name);
    strncpy(_name, name, name_len);
}

Account::Account(const Account& other) {
    delete[] _name;
    size_t name_len = strlen(other._name) + 1;
    _name = new char[name_len];
    strncpy(_name, other._name, name_len);

    _id = other._id;
    _balance = other._balance;
    _interest_rate = other._interest_rate;
}

Account& Account::operator=(const Account& other) {
    if (&other == this) {
        return *this;
    }

    delete[] _name;
    size_t name_len = strlen(other._name) + 1;
    _name = new char[name_len];
    strncpy(_name, other._name, name_len);

    _id = other._id;
    _balance = other._balance;
    _interest_rate = other._interest_rate;

    return *this;
}

void Account::deposit(int money, bool deposit_interest) {
    if (money <= 0) {
        return;
    }

    _balance += money;
    if (deposit_interest) {
        int interest = int(money * ((double)_interest_rate / 100));
        _balance += interest;
    }
}

int Account::withdraw(int money) {
    if (_balance < money) {
        return 0;
    }

    _balance -= money;
    return money;
}

void Account::show_info() const {
    using std::cout;
    using std::endl;

    if (!_name) {
        cout << "인스턴스가 할당되지 않음" << endl;
        return;
    }

    cout << "---------------------------" << endl;
    cout << "계좌번호 : " << _id << endl;
    cout << "이름 : " << _name << endl;
    cout << "현재 잔액 : " << _balance << endl;
    cout << "이율 : " << _interest_rate << "%" << endl;
    cout << "---------------------------" << endl;
}

void Account::set_interest_rate(int value) {
    _interest_rate = value;
}
