#include "gmock/gmock.h"
#include "account.cpp"


using namespace testing;
int main() {
	::testing::InitGoogleMock();
	return RUN_ALL_TESTS();
}

class AccountFixture : public Test {
public:
	Account account{ 10000 };

};

TEST_F(AccountFixture, CreateAccountInit10000won) {
	
	EXPECT_EQ(account.getBalance(), 10000);
}

TEST_F(AccountFixture, Deposit) {	
	account.deposit(500);	
	EXPECT_EQ(account.getBalance(), 10500);
}

TEST_F(AccountFixture, Withdraw) {	
	account.withdraw(600);	
	EXPECT_EQ(account.getBalance(), 9400);
}

TEST_F(AccountFixture, Interest) {
	account.interest(5);
	EXPECT_EQ(account.getBalance(), 10500);
}

TEST_F(AccountFixture, setInterest) {
	account.setInterest(5);
	EXPECT_EQ(account.getIntereset(), 5);
}

TEST_F(AccountFixture, setBalanceInterest) {
	account.setInterest(5);
	account.applyinterest();
	EXPECT_EQ(account.getBalance(), 10500);
}

TEST_F(AccountFixture, getBalanceAfterNYear) {
	account.setInterest(5);	

	account.calNYearBalance(3);
	int expected = 10000 + 10000 * 0.05 +
		(10000 + 10000 * 0.05) * 0.05 +
		(10000 + 10000 * 0.05 +
			(10000 + 10000 * 0.05) * 0.05) * 0.05;
		
	EXPECT_EQ(account.getBalance(), expected);

}

