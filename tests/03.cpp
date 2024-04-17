#include "gtest/gtest.h"
#include "03-Treap_construc.hpp"

check_eq(Treap::Node* node1, Treap::Node* node2) {
    if (node1 || node2) {
        ASSERT_EQ(node1->val, node2->val);
        ASSERT_EQ(node1->sum, node2->sum);
        ASSERT_EQ(node1->size, node2->size);
        check_eq(node1->right, node2->right);
        check_eq(node1->left, node2->left);
    }
}

TEST(TreapTest, CopyConstructorSingleNode) {
    Treap treap1;
    treap1.insert(5, 0);

    Treap treap2(treap1);

    check_eq(treap1.head, treap2.head);
}

TEST(TreapTest, AssignmentOperatorEmpty) {
    Treap treap1;
    treap1.insert(5, 0);

    Treap treap2;

    treap2 = treap1;

    check_eq(treap1.head, treap2.head);
}

TEST(TreapTest, CopyConstructorMultipleNodes) {
    Treap treap1;
    treap1.insert(5, 0);
    treap1.insert(10, 1);
    treap1.insert(15, 2);

    Treap treap2(treap1);

    check_eq(treap1.head, treap2.head);
}

TEST(TreapTest, AssignmentOperatorDifferentSizes) {
    Treap treap1;
    treap1.insert(5, 0);
    treap1.insert(10, 1);

    Treap treap2;
    treap2.insert(3, 0);
    treap2.insert(7, 1);
    treap2.insert(12, 2);

    treap2 = treap1;

    check_eq(treap1.head, treap2.head);
}

TEST(TreapTest, AssignmentOperatorPointersCheck) {
    Treap treap1;
    treap1.insert(5, 0);
    treap1.insert(10, 1);

    Treap treap2;
    treap2.insert(3, 0);
    treap2.insert(7, 1);
    treap2.insert(12, 2);

    Treap check_treap;
    treap1.insert(5, 0);
    treap1.insert(10, 1);

    treap2 = treap1;
    delete treap1;

    check_eq(treap2.head, check_treap.head);
}



int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
