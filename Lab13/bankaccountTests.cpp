// Do zadania 13.4 //
#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
#include "bankaccount.h"

using namespace testing;

struct BATest : Test {
    BankAccount *b;
    BATest () {
        b = new BankAccount("Basak", "13245677", 320.0);
    }
    ~BATest () {
        delete b;
    }
};
TEST_F (BATest, LastNameCheck) {
    EXPECT_EQ("Basak", b->getLastName());
}
TEST_F (BATest, AccountNumberCheck) {
    EXPECT_EQ("13245677", b->getAccountNumber());
}
TEST_F (BATest, MillionaireCheck) {
    b->setBalance(999999);
    EXPECT_EQ(false, b->isMillionaire());
}
TEST_F (BATest, MillionaireCheck2) {
    b->setBalance(1000001);
    EXPECT_EQ(true, b->isMillionaire());
}
struct BalanceState {
    float bInit;
    float bChanged;
};

struct BAParamTest : BATest, WithParamInterface<BalanceState> {
    BAParamTest () {
        b->setBalance(GetParam().bInit);
    }
};

TEST_P (BAParamTest, BTests) {
    BalanceState as = GetParam();
    b->add(100.0);
    float added = b->getBalance();
    EXPECT_EQ(as.bChanged, added);
}


TEST_P (BAParamTest, BTests2) {
    BalanceState as = GetParam();
    b->withdraw(100.0);
    float removed = b->getBalance();
    EXPECT_EQ(as.bChanged, removed);
}

INSTANTIATE_TEST_CASE_P(Default, BAParamTest, Values(BalanceState{100.0, 200.0},
                                                     BalanceState{200.0, 300.0},
                                                     BalanceState{100.0, 0.0},
                                                     BalanceState{50.0, -50.0}));
