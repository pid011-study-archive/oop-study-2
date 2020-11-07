#pragma once

#include "account.h"

namespace BankSystem {
    class HighCreditAccount : public Account {
    public:
        HighCreditAccount(int id, const char* name, int money, char credit)
            : Account(id, name, money) {
            int interest_rate = get_interest_rate();
            switch (credit) {
            case 'A':
                set_interest_rate(interest_rate + 7);
                break;
            case 'B':
                set_interest_rate(interest_rate + 4);
                break;
            case 'C':
                set_interest_rate(interest_rate + 2);
                break;
            default:
                break;
            }
        }
    };
}