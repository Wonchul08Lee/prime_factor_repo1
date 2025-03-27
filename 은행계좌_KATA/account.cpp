class Account{
public:
	Account(int money) : balance{ money } {}
	int getBalance() {
		return balance;
	}
	void deposit(int money) {
		balance += money;
	}
	void withdraw(int money) {
		balance -= money;
	}
	
	void interest(int ratio_) {
		calBalance(ratio_);
	}

	void applyinterest() {
		calBalance(ratio);
	}
	void setInterest(int ratio_) {
		ratio = ratio_;
	}
	int getIntereset() {
		return ratio;
	}
	void calNYearBalance(int year) {
		for (int y = 0; y < year; y++) {
			applyinterest();
		}
	}
	
private:
		int balance =0;
		int ratio =0;

		void calBalance(int ratio_)
		{
			balance += (balance * ratio_ / 100);
		}
};

