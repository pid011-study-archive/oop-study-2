#pragma once
#include "account.h"

namespace BankSystem {
    class NormalAccount : public Account {
    public:
        NormalAccount(int id, const char* name, int money) : Account(id, name, money) { }
    };
} // namespace BankSystem
