
class Account {
	private: 
		int accountNumber;
		double balance;
	public:
		Account (int accountNumber, double balance = 0.0);
		int getAccountNumber() const;
		double getBalance() const;
		void setBalance(double balance);
		void credit(double amount);
		bool debit(double amount);
};