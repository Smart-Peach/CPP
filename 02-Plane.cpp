#include <iostream>

class Point {
public:
    double x, y;

    Point(double x = 0, double y = 0) : x(x), y(y) {}
};


class Line {
public:
    // line equation: ax + by + c = 0
    double a, b, c;

    // Constractor for 2 points
    Line(Point p1, Point p2) {
        a = p2.y - p1.y;
        b = p1.x - p2.x;
        c = p1.x * (p1.y - p2.y) + p1.y * (p2.x - p1.x);
    }

    // Constractor for coefficients a, b, c
    Line(double aa, double bb, double cc) : a(aa), b(bb), c(cc) {}
};

Point findIntersection(const Line& l1, const Line& l2) {
    // Returns Point - the intersection of two lines
    double det = l1.a * l2.b - l2.a * l1.b;

    if (det == 0) {  // Parallel lines
        return Point(NAN, NAN);
    }

    double x = (l1.b * l2.c - l2.b * l1.c) / det;
    double y = (l1.c * l2.a - l2.c * l1.a) / det;

    return Point(x, y);
}

Line findPerpendicular(const Line& l, const Point& p) {
    // Returns Line - the perpendicular to the given line in exact point
    double new_a = -l.b;
    double new_b = l.a;
    double new_c = -new_a * p.x - new_b * p.y;

    return Line(new_a, new_b, new_c);
}

