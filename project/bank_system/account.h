#pragma once

namespace BankSystem {
    class Account {
        int _id;
        int _balance;
        char* _name;
        int _interest_rate;

    public:

        Account() : _id(-1), _balance(0), _name(nullptr), _interest_rate(0) { }
        Account(int id, const char* name, int money, int interest_rate = 3);
        Account(const Account& other);
        Account& operator=(const Account& other);

        ~Account() {
            delete[] _name;
        }

        int get_id() const {
            return _id;
        }

        const char* get_name() const {
            return _name;
        }

        int get_balance() const {
            return _balance;
        }

        int get_interest_rate() const {
            return _interest_rate;
        }

        // 입금
        void deposit(int money, bool deposit_interest = true);
        // 출금
        int withdraw(int money);
        void show_info() const;

    protected:
        void set_interest_rate(int value);
    };
}
