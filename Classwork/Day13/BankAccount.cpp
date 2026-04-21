#include "BankAccount.h"

BankAccount InitBankAccount(std::string newName, double chBalance, double sBalance);
BankAccount SetName(std::string newName, BankAccount account) {
    account.name = newName;
    return account;
}
void GetName(std::string &customerName, BankAccount account) {customerName = account.name;}
BankAccount SetChecking(double balance, BankAccount account) {
    account.checkingBal = balance;
    return account;
}
double GetChecking(BankAccount account) {return account.checkingBal;}
BankAccount SetSavings(double balance, BankAccount account) {
    account.savingsBal = balance;
    return account;
}
double GetSavings(BankAccount account) {return account.savingsBal;}
BankAccount DepositChecking(double amt, BankAccount account) {
    account.checkingBal += amt > 0 ? amt : 0;
    return account;
}
BankAccount DepositSavings(double amt, BankAccount account) {
    account.checkingBal += amt > 0 ? amt : 0;
    return account;
}
BankAccount WithdrawChecking(double amt, BankAccount account) {
    account.checkingBal -= amt > 0 ? amt : 0;
    return account;
}
BankAccount WithdrawSavings(double amt, BankAccount account) {
    account.savingsBal -= amt > 0 ? amt : 0;
    return account;
}
BankAccount TransferToSavings(double amt, BankAccount account) {
    account.checkingBal -= amt > 0 ? amt : 0;
    account.savingsBal += amt > 0 ? amt : 0;
    return account;
}