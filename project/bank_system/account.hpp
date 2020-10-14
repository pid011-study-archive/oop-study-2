#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <cstring>
#include <fstream>
#include <iostream>

namespace BankSystem {
    class Account {
    public:
        Account()
            : _id(-1), _balance(0) {
            _name = new char[2];
            // _name = "-";
        }
        Account(int id, const char* name, int money)
            : _id(id), _balance(money) {
            _name = new char[strlen(name) + 1];
            // strcpy(_name, name);
            strncpy(_name, name, strlen(name) + 1);
        }

        Account(const Account& copy)
            : _id(copy._id), _balance(copy._balance) {
            _name = new char[strlen(copy._name) + 1];
            // strcpy(_name, copy._name);
            strncpy(_name, copy._name, strlen(copy._name) + 1);
        }

        ~Account() {
            delete[] _name;
        }

        int& get_id() {
            return _id;
        }

        char*& get_name() {
            return _name;
        }

        int& get_balance() {
            return _balance;
        }

        // 입금
        void deposit(int money) {
            if (money <= 0) {
                return;
            }

            _balance += money;
        }

        // 출금
        int withdraw(int money) {
            if (_balance < money) {
                return 0;
            }

            _balance -= money;
            return money;
        }

        void show_info() const {
            using std::cout;
            using std::endl;

            cout << "---------------------------" << endl;
            cout << "계좌번호 : " << _id << endl;
            cout << "이름 : " << _name << endl;
            cout << "현재 잔액 : " << _balance << endl;
            cout << "---------------------------" << endl;
        }

    private:
        int _id;
        char* _name;
        int _balance;
    };
}
