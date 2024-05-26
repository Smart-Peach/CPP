#include "../12/12.hpp"
#include <gmock/gmock.h>
#include <gtest/gtest.h>

TEST(TreapTest, BiggerTree) {
    Treap<int> A = Treap<int>();

    A.insert(17, 1);
    A.insert(99, 2);
    A.insert(2, 3);
    A.insert(24, 4);
    A.insert(13, 5);
    A.insert(42, 6);

    std::vector<int> expected = { 17, 99, 2, 24, 13, 42};
    std::vector<int> actual;

    for (auto node : A) {
        actual.push_back(node.val);
    }

    EXPECT_THAT(expected, actual);
}

TEST(TreapTest, Tree) {
    Treap<int> A = Treap<int>();

    A.insert(17, 1);
    A.insert(99, 2);
    A.insert(2, 3);
    A.insert(24, 4);

    std::vector<int> expected = { 17, 99, 2, 24};
    std::vector<int> actual;

    for (auto node : A) {
        actual.push_back(node.val);
    }

    EXPECT_THAT(expected, actual);
}



int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
