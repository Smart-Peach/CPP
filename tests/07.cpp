#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "../07/Operations.cpp"


TEST(ExpressionTest, DefaultTest) {
    // x + 10 * y
    Expression* e = new Add(new Var("x"), new Mult(new Val(10), new Var("y")));

    Expression* res1 = e->diff("x");
    Expression* res2 = e->diff("y");

    ASSERT_EQ(res1->to_string(), "(1.000000 + ((0.000000 * y) + (10.000000 * 0.000000)))");
    ASSERT_EQ(res2->to_string(), "(0.000000 + ((0.000000 * y) + (10.000000 * 1.000000)))");

    delete e;
    delete res1;
    delete res2;
}

TEST(ExpressionTest, SegFaultTest) {
    // x + 10 * y
    Expression* e = new Add(new Var("x"), new Mult(new Val(10), new Var("y")));
    Expression* res1 = e->diff("x");
    delete e;
    ASSERT_EQ(res1->to_string(), "(1.000000 + ((0.000000 * y) + (10.000000 * 0.000000)))");
    delete res1;
}

TEST(ExpressionTest, ExponentTest) {
    // e^(2x)
    Expression* e = new Exponent(new Mult(new Var("x"), new Val(2)));
    Expression* res1 = e->diff("x");
    ASSERT_EQ(res1->to_string(), "(e^(x * 2.000000) * ((1.000000 * 2.000000) + (x * 0.000000)))");
    delete e;
    delete res1;
}

TEST(ExpressionTest, ValTest) {
    // 5
    Expression* e = new Val(5);
    Expression* res1 = e->diff("x");
    ASSERT_EQ(res1->to_string(), "0.000000");
    delete e;
    delete res1;
}

TEST(ExpressionTest, VarTest) {
    // x
    Expression* e = new Var("x");
    Expression* res1 = e->diff("x");
    ASSERT_EQ(res1->to_string(), "1.000000");
    delete e;
    delete res1;
}

TEST(ExpressionTest, AddTest) {
    // x + y
    Expression* e = new Add(new Var("x"), new Var("y"));
    Expression* res1 = e->diff("x");
    Expression* res2 = e->diff("y");
    ASSERT_EQ(res1->to_string(), "(1.000000 + 0.000000)");
    ASSERT_EQ(res2->to_string(), "(0.000000 + 1.000000)");
    delete e;
    delete res1;
    delete res2;
}

TEST(ExpressionTest, SubTest) {
    // x - 6 * y
    Expression* e = new Sub(new Var("x"), new Mult(new Var("y"), new Val(6)));
    Expression* res1 = e->diff("x");
    Expression* res2 = e->diff("y");
    ASSERT_EQ(res1->to_string(), "(1.000000 - ((0.000000 * 6.000000) + (y * 0.000000)))");
    ASSERT_EQ(res2->to_string(), "(0.000000 - ((1.000000 * 6.000000) + (y * 0.000000)))");
    delete e;
    delete res1;
    delete res2;
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}