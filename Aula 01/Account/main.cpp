#include <iostream>

#include "Account.h"

using namespace std;

int main() {
	
	int accountNumber;
	double balance;
	
	cout << "Write your account number: " << endl;
	cin >> accountNumber;
	cout << "Write your balance: " << endl;
	cin >> balance;
	
	Account a1 = Account(accountNumber, balance);
	
	cout << "-- Account information --" << endl;
	cout << "Account Number: " << a1.getAccountNumber() << endl;
	cout << "Balance: " << a1.getBalance() << endl;
	
	cout << endl << "Credit: ";
	cin >> balance;
	a1.credit(balance);
	cout << endl << "Balance after credit: " << a1.getBalance() << endl;
	
	cout << endl << "Debit: ";
	cin >> balance;
	a1.debit(balance);
	cout << endl << "Balance after debit: " << a1.getBalance() << endl;
	
	
	return 0;
	
}