#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include "Val.cpp"
#include "Var.cpp"
#include "BinOp/Add.cpp"
#include "BinOp/Sub.cpp"
#include "BinOp/Mult.cpp"
#include "BinOp/Div.cpp"
#include "UnOp/Exponent.cpp"


TEST(ExpressionTest, DefaultTest) {
    Expression* e = new Add(new Var("x"), new Mult(new Val(10), new Var("y")));

    Expression* res1 = e->diff("x");
    Expression* res2 = e->diff("y");

    std::cout << res1->to_string() << "\n" << res2->to_string() << std::endl;
    // ASSERT_EQ(A.summa(4, 6), 3 + 4 + 5);
}


int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}