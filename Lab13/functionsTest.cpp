#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
#include "functions.h"
using namespace testing;
// Do zadania 13.1 //
TEST(IsEvenTest, OddTests) {
    ASSERT_EQ(false, isEven(5));
}
TEST(IsEvenTest, EvenTests) {
    ASSERT_NE(false,isEven(6));
}
TEST(SignTest, FirstIfTests) {
    ASSERT_THAT(1,Eq(sign(6)));
}
TEST(DifferenceTest,OkResultTests) {
    vector<int> res;
    vector<int> num {1,2,3,6,5};
    res = difference(num);
    vector<int> resExpeted {1,1,3,-1};
    ASSERT_EQ(res.size(),resExpeted.size());
    for (int i = 0; i < res.size(); i++) {
        EXPECT_EQ(res[i],resExpeted[i])<<" Obrot "<<i<<endl;
    }
}
TEST (ShowTest,EmptyLineTests) {
    EXPECT_THROW(show(""), runtime_error);
}
TEST (IsEvenTest, OddTestsErr) {
    ASSERT_EQ(true, isEven(5));
}
TEST (DifferenceTest,OkResultTestsErr) {
    vector<int> res;
    vector<int> num {1,2,3,6,5};
    res=difference(num);
    vector<int> resExpeted {1,2,3,-1};
    ASSERT_EQ(res.size(),resExpeted.size());
    for(int i = 0; i < res.size(); i++) {
        EXPECT_EQ(res[i],resExpeted[i])<<" Obrot "<<i<<endl;
    }
}
// Do zadania 13.2 //
TEST(IsPrimeTest, PrimeTests) {
    ASSERT_EQ(true, isPrime(5));
}
TEST(IsPrimeTest, PrimeTestsErr) {
    ASSERT_EQ(true, isPrime(8));
}
// Do zadania 13.3 //
TEST (ReciprocalTest, ReciprocalTests) {
    ASSERT_EQ(0.2, reciprocal(3.0));
}
TEST (ReciprocalTest, ReciprocalTests2) {
    ASSERT_EQ(-4.0, reciprocal(-0.25));
}
TEST (ReciprocalTest, ReciprocalTestsErr) {
    EXPECT_THROW(reciprocal(0.0), runtime_error);
}
