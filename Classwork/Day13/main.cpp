//
// Created by danie on 4/7/2026.
//

#include "BankAccount.h"

int main() {
    BankAccount account = InitBankAccount("Mickey", 500.00, 1000.00);
    std::string name;

    std::cout << std::fixed << std::setprecision(2);

    account = SetChecking(500, account);
    account = SetSavings(500, account);
    account = WithdrawSavings(100, account);
    account = WithdrawChecking(100, account);
    account = TransferToSavings(300, account);

    GetName(name, account);
    std::cout << name << std::endl;
    std::cout << GetChecking(account) << std::endl;
    std::cout << GetSavings(account) << std::endl;

    return 0;
}