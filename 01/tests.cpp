#include "01-Treap.hpp"
#include "gtest/gtest.h"

TEST(PresentationTest, TestSumma) {
    Treap A;
    A.insert(5, 1);
    A.insert(17, 2);
    A.insert(99, 2);
    A.insert(2, 3);
    A.insert(24, 2);
    A.insert(13, 3);
    A.insert(42, 3);

    ASSERT_EQ(A.summa(1, 7), 5 + 24 + 42 + 13 + 99 + 2 + 17);
}

TEST(ExceptionTest, TestException) {
    Treap A;
    A.insert(5, 1);
    A.insert(17, 2);
    A.insert(99, 2);
    A.insert(2, 3);
    A.insert(24, 2);
    A.insert(13, 3);
    A.insert(42, 3);

    EXPECT_THROW(A.summa(23, 45), std::out_of_range);
}

TEST(FirstTest, TestSumma) {
    Treap A;
    for (int i = 1; i <= 7; ++i) {
        A.insert(i, i);
    }

    ASSERT_EQ(A.summa(4, 6), 4 + 5 + 6);
}

TEST(SecondTest, TestSumma) {
    Treap A;
    for (int i = 7; i >= 0; --i) {
        A.insert(i, 1);
    }

    ASSERT_EQ(A.summa(4, 6), 3 + 4 + 5);
}

TEST(ThirdTest, TestSumma) {
    Treap A;
    A.insert(18, 1);
    A.insert(12, 1);
    A.insert(14, 2);
    A.insert(8, 1);
    A.insert(23, 5);
    A.insert(15, 4);
    A.insert(25, 7);
    A.insert(24, 7);

    ASSERT_EQ(A.summa(2, 6), 12 + 14 + 15 + 18 + 23);
}

TEST(FourthTest, TestSumma) {
    Treap A;
    A.insert(654, 1);
    A.insert(54, 2);
    A.insert(10, 1);
    A.insert(8, 2);
    A.insert(8, 4);
    A.insert(61, 6);
    A.insert(9, 5);
    A.insert(5, 6);
    A.insert(12, 9);
    A.insert(5, 9);
    A.insert(65, 11);

    ASSERT_EQ(A.summa(3, 8), 654 + 8 + 9 + 5 + 54 + 61);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
