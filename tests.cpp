#include <string>
#include "gtest/gtest.h"
#include "reversePolishNotationLib.h"

using namespace std;

TEST(trueResult, expectedTrueResult1) {
    string equation = "4+2-2*4/2^2";
    vector<string> postfix = parse(equation);
    int result = evaluate(postfix);
    ASSERT_EQ(result, 4);
}

TEST(trueResult, expectedTrueResult2) {
    string equation = "(12-3)+(5*(16/(16-32/16)-14)-(11*2)^2)-(11*3)";
    vector<string> postfix = parse(equation);
    int result = evaluate(postfix);
    ASSERT_EQ(result, -573);
}

TEST(trueRPN, expectedRPN1) {
    string equation = "1+2";
    vector<string> postfix = parse(equation);
    vector<string> expectedPostfix = {"1", "2", "+"};
    ASSERT_EQ(postfix, expectedPostfix);
}

TEST(trueRPN, expectedRPN2) {
    string equation = "1+2^2-14+22/2";
    vector<string> postfix = parse(equation);
    vector<string> expectedPostfix = {"1", "2", "2", "^", "+", "14", "-", "22", "2", "/", "+"};
    ASSERT_EQ(postfix, expectedPostfix);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}