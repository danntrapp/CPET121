#ifndef CPET121_BANKACCNT_H
#define CPET121_BANKACCNT_H
#include <iostream>
#include <iomanip>
#include <string>
#include <cmath> // needed for tests

typedef struct BankAccount_struct {
    std::string name;
    double checkingBal, savingsBal;
} BankAccount;

BankAccount InitBankAccount(std::string newName, double chBalance, double sBalance); // set the customer name to parameter newName, set the checking account balance to parameter chBalance and set the savings account balance to parameter sBalance.
BankAccount SetName(std::string newName, BankAccount account); // set the customer name
void GetName(std::string & customerName, BankAccount account); // return the customer name in customerName
BankAccount SetChecking(double balance, BankAccount account); // set the checking account balance to parameter balance
double GetChecking(BankAccount account); // return the checking account balance
BankAccount SetSavings(double balance, BankAccount account); // set the savings account balance to parameter balance
double GetSavings(BankAccount account); // return the savings account balance
BankAccount DepositChecking(double amt, BankAccount account); // add parameter amt to the checking account balance (only if positive)
BankAccount DepositSavings(double amt, BankAccount account); // add parameter amt to the savings account balance (only if positive)
BankAccount WithdrawChecking(double amt, BankAccount account); // subtract parameter amt from the checking account balance (only if positive)
BankAccount WithdrawSavings(double amt, BankAccount account); // subtract parameter amt from the savings account balance (only if positive)
BankAccount TransferToSavings(double amt, BankAccount account);


#endif //CPET121_BANKACCNT_H