#include "../01/01.hpp"
#include <gmock/gmock.h>
#include <gtest/gtest.h>

TEST(TreapTest, TestException) {
    Treap A = Treap();
    A.insert(5, 1);
    A.insert(17, 2);
    A.insert(99, 2);
    A.insert(2, 3);
    A.insert(24, 2);
    A.insert(13, 3);
    A.insert(42, 3);

    EXPECT_THROW(A.summa(23, 45), std::out_of_range);
}

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

void check_eq(Treap::Node* node1, Treap::Node* node2) {
    // if (node1 || node2) {
    //     ASSERT_EQ(node1->val, node2->val);
    //     ASSERT_EQ(Treap::Node::get_sum(node1), Treap::Node::get_sum(node2));
    //     ASSERT_EQ(Treap::Node::get_size(node1), Treap::Node::get_size(node2));
    //     check_eq(node1->right, node2->right);
    //     check_eq(node1->left, node2->left);
    // }
}

TEST(TreapTest, CopyConstructorSingleNode) {
    Treap treap1 = Treap();
    treap1.insert(5, 0);

    Treap treap2(treap1);

    check_eq(treap1.get_head(), treap2.get_head());
}

TEST(TreapTest, AssignmentOperatorEmpty) {
    Treap treap1 = Treap();
    treap1.insert(5, 0);

    Treap treap2 = treap1;

    check_eq(treap1.get_head(), treap2.get_head());
}

TEST(TreapTest, CopyConstructorMultipleNodes) {
    Treap treap1 = Treap();
    treap1.insert(5, 0);
    treap1.insert(10, 1);
    treap1.insert(15, 2);

    Treap treap2(treap1);

    check_eq(treap1.get_head(), treap2.get_head());
}

// TEST(TreapTest, AssignmentOperatorPointersCheck) {
//     Treap treap1 = Treap();
//     treap1.insert(5, 0);
//     treap1.insert(10, 1);

//     Treap treap2 = Treap();
//     treap2.insert(3, 0);
//     treap2.insert(7, 1);
//     treap2.insert(12, 2);

//     Treap check_treap = Treap();
//     treap1.insert(5, 0);
//     treap1.insert(10, 1);

//     treap2 = treap1;
//     ~treap1;

//     check_eq(treap2.get_head(), check_treap.get_head());
// }

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
