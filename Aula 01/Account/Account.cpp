#include <iostream>

#include "Account.h"

using namespace std;

Account::Account(int acNum, double ba) {
	accountNumber = acNum;
	balance = ba;
}

int Account::getAccountNumber() const {
	return accountNumber;
}

double Account::getBalance() const {
	return balance;
}

void Account::setBalance(double ba) {
	balance = ba;
}

void Account::credit(double amount) {
	balance += amount;
}

bool Account::debit(double amount) {
	if (amount <= balance) {
		balance -= amount;
		return true;
	} else {
		cout << "Amount withdrawn exceeds the current balance!" << endl;
		return false;
	}
	
}