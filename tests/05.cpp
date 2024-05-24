#include "../05/05-ScopedPoint.hpp"
#include <gmock/gmock.h>
#include <gtest/gtest.h>

TEST(DeepCopy, copyctor) {
    ScopedPointerCopying sp{ new Triple{13, 42, 1}};
    ScopedPointerCopying sp2 = sp;
    ASSERT_TRUE(sp.get() != std::nullopt);
}

TEST(DeepCopy, movector) {
    ScopedPointerCopying sp{ new Triple{13, 42, 1}};
    ScopedPointerCopying sp2 {std::move(sp)};
    ASSERT_TRUE(sp.get() == std::nullopt);
}

TEST(DeepCopy, copyoper) {
    ScopedPointerCopying sp1{ new Triple{13, 42, 1}};
    ScopedPointerCopying sp2{ new Triple{1, 1, 1}};
    sp2 = sp1;
    ASSERT_TRUE(sp1.get() != std::nullopt);
}

TEST(DeepCopy, moveoper) {
    ScopedPointerCopying sp1{ new Triple{13, 42, 1}};
    ScopedPointerCopying sp2{ new Triple{1, 1, 1}};
    sp2 = std::move(sp1);
    ASSERT_TRUE(sp1.get() == std::nullopt);
}

TEST(Transfering, copyctor) {
    ScopedPointerTransfering sp{ new Triple{13, 42, 1}};
    // ScopedPointerTransfering sp2 = sp1;
    ScopedPointerTransfering sp2  = std::move(sp);
    ASSERT_TRUE(sp.get() == std::nullopt);
}

TEST(Transfering, movector) {
    ScopedPointerTransfering sp{ new Triple{13, 42, 1}};
    ScopedPointerTransfering sp2 {std::move(sp)};
    ASSERT_TRUE(sp.get() == std::nullopt);
}

TEST(Transfering, copyoper) {
    ScopedPointerTransfering sp1{ new Triple{13, 42, 1}};
    ScopedPointerTransfering sp2{ new Triple{1, 1, 1}};
    // sp2 = sp1;
    sp2 = std::move(sp1);
    ASSERT_TRUE(sp1.get() == std::nullopt);
}

TEST(Transfering, moveoper) {
    ScopedPointerTransfering sp1{ new Triple{13, 42, 1}};
    ScopedPointerTransfering sp2{ new Triple{1, 1, 1}};
    sp2 = std::move(sp1);
    ASSERT_TRUE(sp1.get() == std::nullopt);
}


int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}