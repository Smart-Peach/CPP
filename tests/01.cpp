#include "../01/01.hpp"
#include <gmock/gmock.h>
#include <gtest/gtest.h>

// TEST(TreapTest, TestException) {
//     Treap A = Treap();
//     A.insert(5, 1);
//     A.insert(17, 2);
//     A.insert(99, 2);
//     A.insert(2, 3);
//     A.insert(24, 2);
//     A.insert(13, 3);
//     A.insert(42, 3);

//     EXPECT_THROW(A.summa(23, 45), std::out_of_range);
// }

TEST(TreapTest, TestSumma1) {
    Treap A = Treap();
    A.insert(5, 1);
    A.insert(17, 2);
    A.insert(99, 2);
    A.insert(2, 3);
    A.insert(24, 2);
    A.insert(13, 3);
    A.insert(42, 3);

    ASSERT_EQ(A.summa(1, 7), 5 + 24 + 42 + 13 + 99 + 2 + 17);
}

TEST(TreapTest, TestSumma2) {
    Treap A = Treap();
    for (int i = 1; i <= 7; ++i) {
        A.insert(i, i);
    }

    ASSERT_EQ(A.summa(4, 6), 4 + 5 + 6);
}

TEST(TreapTest, TestSumma3) {
    Treap A = Treap();
    for (int i = 7; i >= 0; --i) {
        A.insert(i, 1);
    }

    ASSERT_EQ(A.summa(4, 6), 3 + 4 + 5);
}

TEST(TreapTest, TestSumma4) {
    Treap A = Treap();
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

TEST(TreapTest, TestSumma5) {
    Treap A = Treap();
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

TEST(TreapTest, CopyConstructorSingleNode) {
    Treap treap1 = Treap();
    treap1.insert(5, 0);

    Treap treap2(treap1);

    ASSERT_EQ(Treap::print_numbers(treap1.get_head(), ""), Treap::print_numbers(treap2.get_head(), ""));
}

TEST(TreapTest, AssignmentOperatorEmpty) {
    Treap treap1 = Treap();
    treap1.insert(5, 0);

    Treap treap2 = treap1;

    ASSERT_EQ(Treap::print_numbers(treap1.get_head(), ""), Treap::print_numbers(treap2.get_head(), ""));
}

TEST(TreapTest, CopyConstructorMultipleNodes) {
    Treap treap1 = Treap();
    treap1.insert(5, 0);
    treap1.insert(10, 1);
    treap1.insert(15, 2);

    Treap treap2(treap1);
    // std::cout << Treap::print_numbers(treap2.get_head(), "");
    // std::cout << Treap::print_numbers(treap2.get_head(), "") << std::endl;

    ASSERT_EQ(Treap::print_numbers(treap1.get_head(), ""), Treap::print_numbers(treap2.get_head(), ""));
}

TEST(TreapTest, MoveConstructor) {
    int arr[] = {45, 54, 23, 987, 34, 98, 4};
    int len = sizeof(arr) / sizeof(int);
	Treap t1 = Treap();
	for(int i=0; i < len; i++) {
        t1.insert(arr[i], i+1);
    }
    int summ1 = t1.summa(1, 7); 
	Treap t2 = Treap(std::move(t1));
	ASSERT_TRUE(summ1 == t2.summa(1, 7));
    ASSERT_TRUE(t1.get_head() == nullptr);
}

TEST(TreapTest, MoveAssignmentOperator) {
    int arr[] = {45, 54, 23, 987, 34, 98, 4};
    int len = sizeof(arr) / sizeof(int);
	Treap t1 = Treap();
	for(int i=0; i < len; i++) {
        t1.insert(arr[i], i+1);
    }
    int summ1 = t1.summa(1, 7); 
	Treap t2 = Treap();
    t2 = std::move(t1);
	ASSERT_TRUE(summ1 == t2.summa(1, 7));
    ASSERT_TRUE(t1.get_head() == nullptr);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
