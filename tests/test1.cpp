#include <string>
#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include "Transaction.h"
#include "Account.h"
//using ::testing::_;


//class MockTransaction : public Transaction {
////class MockTransaction {
//public:
//	//MockTransaction() : Transaction() {};
//	//MOCK_METHOD(bool, Make, (Account& from, Account& to, int sum), ());
//	//MOCK_METHOD(void, Credit, (Account& accout, int sum), ());
//	//MOCK_METHOD(bool, Debit, (Account& accout, int sum), ());
//	//MOCK_METHOD(int, fee, (), (const));
//	//MOCK_METHOD(void, set_fee, (int fee));
//	MOCK_METHOD(void, SaveToDataBase, (Account& from, Account& to, int sum), (override));
//};

class MockAccount : public Account {
public:
	MockAccount(int id, int balance) : Account(id, balance) {};
	MOCK_METHOD(int, GetBalance, (), (const, override));
	MOCK_METHOD(void, ChangeBalance, (int diff), (override));
	MOCK_METHOD(void, Lock, (), (override));
	MOCK_METHOD(void, Unlock, (), (override));
	MOCK_METHOD(int, id, (), (const));
};

TEST(Transaction_test, test_SaveToDataBase) {

	Account acc1(1, 200);
	Account acc2(2, 873);
	Transaction trans;
	bool succes = trans.Make(acc1, acc2, 150);
	EXPECT_TRUE(acc1.GetBalance() == (200-150 - trans.fee()));
	EXPECT_TRUE(acc2.GetBalance() == (150+873));
	EXPECT_TRUE(succes);
}

TEST(Transaction_test, test_set_fee) {
	Transaction trans;
	trans.set_fee(5);
	EXPECT_TRUE(5 == trans.fee());
}

TEST(Transaction_test, test_fee) {
	Transaction trans;
	EXPECT_TRUE(1 == trans.fee());
}

TEST(MockAccount_test, test_ChangeBalance) {
	MockAccount acc1(1, 200);
	MockAccount acc2(2, 873);
	Transaction trans;

	ON_CALL(acc1, GetBalance()).WillByDefault(::testing::Return(200));
	EXPECT_CALL(acc1, ChangeBalance(::testing::_)).Times(::testing::AtLeast(1));

	EXPECT_CALL(acc2, ChangeBalance(150)).Times(::testing::AtLeast(1));
	 
	trans.Make(acc1, acc2, 150);
}

TEST(MockAccount_test, test_GetbBalance) {
	MockAccount acc1(1, 200);
	MockAccount acc2(2, 873);
	Transaction trans;

	EXPECT_CALL(acc1, GetBalance()).Times(2);
	EXPECT_CALL(acc2, GetBalance()).Times(1);

	trans.Make(acc1, acc2, 150);
}

TEST(MockAccount_test, test_lock) {
	MockAccount acc1(1, 200);
	MockAccount acc2(2, 873);
	Transaction trans;

	EXPECT_CALL(acc1, Lock()).Times(::testing::AtLeast(1));
	EXPECT_CALL(acc2, Lock()).Times(::testing::AtLeast(1));

	trans.Make(acc1, acc2, 150);
}

TEST(MockAccount_test, test_unlock) {
	MockAccount acc1(1, 200);
	MockAccount acc2(2, 873);
	Transaction trans;

	EXPECT_CALL(acc1, Unlock()).Times(::testing::AtLeast(1));
	EXPECT_CALL(acc2, Unlock()).Times(::testing::AtLeast(1));

	trans.Make(acc1, acc2, 150);
}


TEST(Account_test, test_GetBalance1) {
	Account acc(101, 1337);

	int balance = acc.GetBalance();

	EXPECT_EQ(balance, 1337);
}

TEST(Account_test, test_GetBalance2) {
	Account acc(99, 0);// Arrange

	int balance = acc.GetBalance();//Act

	EXPECT_EQ(balance, 0);//Assert
}

TEST(Account_test, test_ChangeBalance) {
	Account acc(99, 1);

	acc.Lock();
	acc.ChangeBalance(87556);
	acc.Unlock();
	int balance = acc.GetBalance();

	EXPECT_EQ(balance, 87557);
}

TEST(Account_test, test_Lock) {
	Account acc(99, 0);

	ASSERT_ANY_THROW(acc.ChangeBalance(87556));
}

TEST(Account_test, test_Lock2) {
	Account acc(99, 0);

	acc.Lock();
	
	ASSERT_ANY_THROW(acc.Lock(););
}

TEST(Account_test, test_UnLock) {
	Account acc(99, 0);

	acc.Lock();
	acc.Unlock();
	ASSERT_NO_THROW(acc.Lock());
}

int main(int argc, char** argv) {
	::testing::FLAGS_gmock_verbose = "error";
	::testing::InitGoogleTest(&argc, argv);
	::testing::InitGoogleMock(&argc, argv);
	return RUN_ALL_TESTS();
}