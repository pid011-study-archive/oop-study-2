#include "account.hpp"
#include <iostream>

using namespace BankSystem;
using namespace std;

void menu_create() {
    cout << "[계좌개설]" << endl;

    char name[50];
    int account_number;
    int money;

    cout << "계좌번호 : ";
    cin >> account_number;
    cin.ignore();
    cout << "이름 : ";
    cin.getline(name, 50);
    cout << "입금액 : ";
    cin >> money;
    cin.ignore();

    Account acnt = Account(name, account_number, money);
    cout << "계좌개설완료" << endl;
}

void menu_deposit() {
    cout << "[입금]" << endl;

    int account_number;
    int money;

    cout << "계좌번호 : ";
    cin >> account_number;
    cin.ignore();
    cout << "입금액 : ";
    cin >> money;
    cin.ignore();

    Account acnt;
    bool result = Account::load_account(&acnt, account_number);

    if (!result) {
        cout << "계좌번호가 다릅니다." << endl;
    }

    bool deposit_result = acnt.deposit(money);

    if (!deposit_result) {
        cout << "입금실패" << endl;
    }
    cout << "입금완료" << endl;
}

void menu_withdraw() {
    cout << "[출금]" << endl;

    int account_number;
    int money;

    cout << "계좌번호 : ";
    cin >> account_number;
    cin.ignore();
    cout << "출금액 : ";
    cin >> money;
    cin.ignore();

    Account acnt;
    bool result = Account::load_account(&acnt, account_number);

    if (!result) {
        cout << "계좌번호가 다릅니다." << endl;
    }

    bool withdraw_result = acnt.deposit(money);

    if (!withdraw_result) {
        cout << "출금실패" << endl;
    }
    cout << "출금완료" << endl;
}

void menu_view() {
    cout << "[잔액조회]" << endl;

    int account_number;

    cout << "계좌번호 : ";
    cin >> account_number;
    cin.ignore();

    Account acnt;
    bool result = Account::load_account(&acnt, account_number);

    if (!result) {
        cout << "계좌번호가 다릅니다." << endl;
    }

    cout << "잔액 : " << acnt.get_money() << endl;
}

int main() {
    int input = 0;

    while (input != 5) {
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
            menu_create();
            break;
        case 2:
            menu_deposit();
            break;
        case 3:
            menu_withdraw();
            break;
        case 4:
            menu_view();
            break;
        case 5:
            break;
        default:
            cout << "다시 선택해주세요." << endl;
            break;
        }
    }
}
