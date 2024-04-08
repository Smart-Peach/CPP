#include <iostream>
#include <optional>

struct Point {
    const double x, y;
};


class Line {
private:
    // line equation: ax + by + c = 0
    double a, b, c;

public:
    // Constractor for 2 points
    Line(Point p1, Point p2) {
        a = p2.y - p1.y;
        b = p1.x - p2.x;
        c = p1.x * (p1.y - p2.y) + p1.y * (p2.x - p1.x);
    }

    // Constractor for coefficients a, b, c
    Line(double aa, double bb, double cc) : a(aa), b(bb), c(cc) {}

    // Returns Point - the intersection of two lines
    std::optional<Point*> findIntersection(const Line& l2) {
        double det = this->a * l2.b - l2.a * this->b;

        if (det == 0) {  // Parallel lines
            return std::nullopt;
        }

        double x = (this->b * l2.c - l2.b * this->c) / det;
        double y = (this->c * l2.a - l2.c * this->a) / det;

        return new Point{x, y};
    }

    // Returns Line - the perpendicular to the given line in exact point
    Line findPerpendicular(const Point& p) {
        double new_a = -this->b;
        double new_b = this->a;
        double new_c = -new_a * p.x - new_b * p.y;

        return Line(new_a, new_b, new_c);
    }
};

int main() {}


