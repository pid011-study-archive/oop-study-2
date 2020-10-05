#pragma once

#include <cstdio>
#include <cstring>
#include <fstream>

namespace BankSystem {
    class Account {
    private:
        static const char* _file_extension;

        char* _name;
        char* _file_name;
        int _account_number = 0;
        int _money = 0;

    public:
        Account() {
            _name = new char[30];
            _file_name = new char[50];
        }

        Account(const char* name, int account_number, int money) {
            _name = new char[30];
            _file_name = new char[50];

            // 이름 동적할당
            strcpy_s(_name, 30, name);

            // 저장할 파일의 이름 [계좌번호.dat]
            sprintf_s(_name, 30, "%d", account_number);
            strcpy_s(_file_name, 50, _name);
            strcat_s(_file_name, 50, _file_extension);

            _account_number = account_number;
            _money = money;

            save();
        }

        ~Account() {
            // 동적할당한 메모리를 해제해줘야 하는데 오류 발생함
            if (_name) {
                delete[] _name;
            }

            if (_file_name) {
                delete[] _file_name;
            }
        }

        static bool load_account(Account* load_data, int account_number) {
            using namespace std;

            Account account;

            char tmp[50];
            sprintf_s(tmp, 50, "%d", account_number);

            size_t ext_length = strlen(_file_extension);
            size_t file_name_length = strlen(tmp) + ext_length + 1;
            char* file_name = new char[file_name_length];

            strcpy_s(file_name, file_name_length, tmp);
            strcat_s(file_name, file_name_length, _file_extension);

            ifstream fs(file_name, ios::in | ios::binary);
            if (!fs) {
                return false;
            }

            fs.read((char*)load_data, sizeof(Account));
            fs.close();
            delete[] file_name;

            return true;
        }

        static const char* get_file_extension() {
            return _file_extension;
        }

        const char* get_name() const {
            return _name;
        }

        const int* get_account_number() const {
            return &_account_number;
        }

        const int* get_money() const {
            return &_money;
        }

        // 현재 인스턴스를 파일에 저장
        bool save() {
            using namespace std;

            ofstream fs(_file_name, ios::out | ios::binary);
            fs.write((char*)this, sizeof(Account));
            fs.close();
            return true;
        }

        // 입금
        bool deposit(int money) {
            if (money <= 0) {
                return false;
            }

            _money += money;
            return save();
        }

        // 출금
        bool withdraw(int money) {
            if (_money < money) {
                return false;
            }

            _money -= money;
            return save();
        }
    };

    const char* Account::_file_extension = ".dat";
}
