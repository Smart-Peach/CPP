#include "../12/12.hpp"
#include <gmock/gmock.h>
#include <gtest/gtest.h>

TEST(TreapTest, Testing) {
    Treap<int> A = Treap<int>();

    A.insert(17, 1);
    std::cout << "\n!!!!!!!!!!!!!!!!!!!!!!!\n";
    A.print_bst(A.get_head());
    std::cout << "\n!!!!!!!!!!!!!!!!!!!!!!!\n";

    A.insert(99, 2);
    std::cout << "\n!!!!!!!!!!!!!!!!!!!!!!!\n";
    A.print_bst(A.get_head());
    std::cout << "\n!!!!!!!!!!!!!!!!!!!!!!!\n";

    A.insert(2, 3);
    std::cout << "\n!!!!!!!!!!!!!!!!!!!!!!!\n";
    A.print_bst(A.get_head());
    std::cout << "\n!!!!!!!!!!!!!!!!!!!!!!!\n";
    // A.insert(24, 4);
    // A.insert(13, 5);
    // A.insert(42, 6);

    A.print_bst(A.get_head());
    std::cout << "\n";
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
