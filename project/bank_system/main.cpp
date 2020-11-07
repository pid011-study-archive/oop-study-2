#include "account.h"
#include "high_credit_account.h"
#include "normal_account.h"
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iostream>

using namespace BankSystem;
using namespace std;

const char* FileName = "accounts.dat";

void write_data(int len, Account** accounts);
int read_data(Account** accounts);
int menu_create(int len, Account** accounts);
int menu_create_normal_account(int len, Account** accounts);
int menu_create_high_credit_account(int len, Account** accounts);
void menu_deposit(int len, Account** accounts);
void menu_withdraw(int len, Account** accounts);
void menu_view(int len, Account** accounts);

int main() {
    while (true) {
        int input = 0;

        Account* acc_arr[100];
        std::fill(acc_arr, acc_arr + 100, nullptr);

        int accounts_len = read_data(acc_arr);

        cout << "--- Menu ---" << endl;
        cout << "1. 계좌개설" << endl;
        cout << "2. 입금" << endl;
        cout << "3. 출금" << endl;
        cout << "4. 잔액조회" << endl;
        cout << "5. 프로그램 종료" << endl;

        cout << "선택: ";
        cin >> input;
        cin.ignore();

        switch (input) {
        case 1:
            accounts_len = menu_create(accounts_len, acc_arr);
            break;
        case 2:
            menu_deposit(accounts_len, acc_arr);
            break;
        case 3:
            menu_withdraw(accounts_len, acc_arr);
            break;
        case 4:
            menu_view(accounts_len, acc_arr);
            break;
        case 5:
            return 0;
        default:
            break;
        }

        write_data(accounts_len, acc_arr);

        for (auto& i : acc_arr) {
            delete i;
        }
    }
}

void write_data(int len, Account** accounts) {
    ofstream fs(FileName, ios::out);
    fs << len << '\n';
    for (size_t i = 0; i < len; i++) {
        fs << accounts[i]->get_id() << '\n';
        fs << accounts[i]->get_name() << '\n';
        fs << accounts[i]->get_balance() << '\n';
        fs << accounts[i]->get_interest_rate() << '\n';
    }
    fs.close();
}

int read_data(Account** accounts) {
    int count;

    ifstream fs(FileName);
    if (!fs) {
        ofstream fout(FileName, ios::out);
        fout.close();
        fs.close();
        return 0;
    }

    constexpr int MAX = 100;
    char data_len[100];
    fs.getline(data_len, MAX);
    if (strlen(data_len) == 0) {
        fs.close();
        return 0;
    }

    char* end_ptr;
    count = int(strtol(data_len, &end_ptr, 10));

    for (int i = 0; i < count; i++) {
        char* data = new char[MAX];
        fs.getline(data, MAX);
        char* id = new char[strlen(data) + 1];
        // strcpy(id, data);
        strncpy(id, data, strlen(data) + 1);

        fs.getline(data, MAX);
        char* name = new char[strlen(data) + 1];
        // strcpy(name, data);
        strncpy(name, data, strlen(data) + 1);

        fs.getline(data, MAX);
        char* balance = new char[strlen(data) + 1];
        // strcpy(balance, data);
        strncpy(balance, data, strlen(data) + 1);

        fs.getline(data, MAX);
        char* rate_interest = new char[strlen(data) + 1];
        strncpy(rate_interest, data, strlen(data) + 1);

        accounts[i] = new Account(
            int(strtol(id, &end_ptr, 10)),
            name,
            int(strtol(balance, &end_ptr, 10)),
            int(strtol(rate_interest, &end_ptr, 10)));

        delete[] data;
        delete[] id;
        delete[] name;
        delete[] balance;
        delete[] rate_interest;
    }

    fs.close();
    return count;
}

int menu_create(int len, Account** accounts) {
    cout << "[계좌개설]" << endl;

    while (true) {
        cout << "1. 보통예금계좌 2. 신용계좌 [선택]: ";

        int choose;
        cin >> choose;

        switch (choose) {
        case 1:
            return menu_create_normal_account(len, accounts);
        case 2:
            return menu_create_high_credit_account(len, accounts);
        default:
            break;
        }
    }
}

int menu_create_normal_account(int len, Account** accounts) {
    char name[50];
    int account_number;
    int money;
    cin.ignore(1000, '\n');
    cout << "[보통예금계좌]" << endl;
    cout << "이름 : ";
    cin.getline(name, 200);
    cout << "입금액 : ";
    cin >> money;
    cin.ignore(1000, '\n');
    len += 1;
    account_number = len;

    accounts[len - 1] = new NormalAccount(account_number, name, money);

    cout << "계좌번호 : " << account_number << endl;
    cout << "계좌개설완료" << endl;
    accounts[len - 1]->show_info();

    return len;
}

int menu_create_high_credit_account(int len, Account** accounts) {
    char name[50];
    int account_number;
    int money;
    char credit;
    cin.ignore(1000, '\n');
    cout << "[신용예금계좌]" << endl;
    cout << "이름 : ";
    cin.getline(name, 200);
    cout << "입금액 : ";
    cin >> money;
    len += 1;
    account_number = len;
    cout << "신용등급(A, B, C): ";
    cin >> credit;
    cin.ignore(1000, '\n');

    accounts[len - 1] = new HighCreditAccount(account_number, name, money, credit);

    cout << "계좌번호 : " << account_number << endl;
    cout << "계좌개설완료" << endl;
    accounts[len - 1]->show_info();

    return len;
}

void menu_deposit(int len, Account** accounts) {
    cout << "[입금]" << endl;

    int account_number;
    int money;

    cout << "계좌번호 : ";
    cin >> account_number;
    cin.ignore(1000, '\n');

    int pos = -1;
    for (int i = 0; i < len; i++) {
        if (accounts[i]->get_id() == account_number) {
            pos = i;
            break;
        }
    }
    if (pos == -1) {
        cout << "일치하는 계좌가 없습니다." << endl;
        return;
    }

    cout << "입금액 : ";
    cin >> money;
    cin.ignore(1000, '\n');
    accounts[pos]->deposit(money);
    cout << "입금되었습니다." << endl;
    accounts[pos]->show_info();
}

void menu_withdraw(int len, Account** accounts) {
    cout << "[출금]" << endl;

    int account_number;
    int money;

    cout << "계좌번호 : ";
    cin >> account_number;
    cin.ignore(1000, '\n');

    int pos = -1;
    for (int i = 0; i < len; i++) {
        if (accounts[i]->get_id() == account_number) {
            pos = i;
            break;
        }
    }
    if (pos == -1) {
        cout << "일치하는 계좌가 없습니다." << endl;
        return;
    }

    accounts[pos]->show_info();
    cout << "출금액 : ";
    cin >> money;
    cin.ignore(1000, '\n');

    int result = accounts[pos]->withdraw(money);
    cout << result << "원이 인출되었습니다." << endl;
    accounts[pos]->show_info();
}

void menu_view(int len, Account** accounts) {
    cout << "[전체 계좌 조회]" << endl;
    if (len < 1) {
        cout << "존재하는 계좌가 없습니다." << endl;
        return;
    }
    for (int i = 0; i < len; i++) {
        accounts[i]->show_info();
    }
}
