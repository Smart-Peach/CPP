#include "../02/02-Plane.cpp"
#include <gmock/gmock.h>
#include <gtest/gtest.h>

TEST(PlaneTest, TestConstructor1) {
    Line line1 = Line(6, 3, -30);
    Line line2 = Line(Point{6, -2}, Point{3, 4});

    ASSERT_TRUE(line1.get_det(line2) == 0);
}

TEST(PlaneTest, TestConstructor2) {
    Line line1 = Line(2, 1, -10);
    Line line2 = Line(Point{6, -2}, Point{3, 4});

    ASSERT_TRUE(line1.get_det(line2) == 0);
}

TEST(PlaneTest, TestConstructor3) {
    Line line1 = Line(-1, 1, 0);
    Line line2 = Line(Point{1, 1}, Point{2, 2});

    ASSERT_TRUE(line1.get_det(line2) == 0);
}

TEST(PlaneTest, TestConstructor4) {
    Line line1 = Line(-1, 1, 0);
    Line line2 = Line(Point{2, 2}, Point{3, 3});

    ASSERT_TRUE(line1.get_det(line2) == 0);
}

TEST(PlaneTest, TestIntersectionDefault) {
    Line line2 = Line(1, -1, 0);
    std::optional<Point> actual = line2.findIntersection(Line{1, 0, 0});
    ASSERT_TRUE(actual);
    Point expected = Point{0, 0};

    ASSERT_EQ(expected.x, actual->x);
    ASSERT_EQ(expected.y, actual->y);
}

TEST(PlaneTest, TestIntersectionParallel) {
    Line line1 = Line(Point{1, 1}, Point{2, 2});
    Line line2 = Line(Point{1, 1}, Point{-2, -2});

    std::optional<Point> actual = line1.findIntersection(line2);
    
    ASSERT_FALSE(actual);
}

TEST(PlaneTest, TestPerpendicular) {
    Line line1 = Line(Point{1, 1}, Point{2, 2});
    Line line2 = Line(Point{1, -1}, Point{-2, 2});

    std::optional<Point> actual = line1.findIntersection(line2);
    
    ASSERT_TRUE(actual);
    Point expected = Point{0, 0};

    ASSERT_EQ(expected.x, actual->x);
    ASSERT_EQ(expected.y, actual->y);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
