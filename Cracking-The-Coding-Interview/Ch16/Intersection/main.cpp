#include <bits/stdc++.h>

using namespace std;

// For two lines to intersect they have to have different slopes, 
// or if they have the same slope, only if they are the same line.
// So if they have different slopes, by the line equation we can find
// an intersection point, and then we just need to check if that point
// is part of both lines given.
struct Point {
    double x, y;
    Point(double x, double y) : x(x), y(y) { }
};

struct Line {
    double slope, yIntercept;
    Line (Point start, Point end) {
        double deltaY = end.y - start.y;
        double deltaX = end.x - start.x;
        if (deltaX == 0) 
            slope = INFINITY;
        else
            slope = deltaY / deltaX;
        yIntercept = end.y - slope * end.x;
    }
};

void swap(Point& lhs, Point& rhs) {
    swap(lhs.x, rhs.x);
    swap(lhs.y, rhs.y);
}

bool isBetween(double start, double middle, double end) {
    if (start > end)
        return end <= middle && middle <= start;
    else
        return start <= middle && middle <= end;
}

bool isBetween(Point& start, Point& middle, Point& end) {
    return isBetween(start.x, middle.x, end.x) && isBetween(start.y, middle.y, end.y);
}

Point* intersection(Point& start1, Point& end1, Point& start2, Point& end2) {
    // Rearrange them so the lower values are in the start
    if (start1.x > end1.x) swap(start1, end1);
    if (start2.x > end2.x) swap(start2, end2);
    if (start1.x > start2.x) {
        swap(start1, start2);
        swap(end1, end2);
    }

    Line line1(start1, end1);
    Line line2(start2, end2);

    // Check for slope and same yIntercept
    if (line1.slope == line2.slope) {
        if (line1.yIntercept == line2.yIntercept && isBetween(start1, start2, end1))
            return &start2;
        return nullptr;
    }

    // Use line equation to get intersection
    double x = (line2.yIntercept - line1.yIntercept) / (line1.slope - line2.slope);
    double y = x * line1.slope + line1.yIntercept;
    Point* intersection = new Point(x, y);

    if (isBetween(start1, *intersection, end1) && isBetween(start2, *intersection, end2)) 
        return intersection;
    return nullptr;
}

int main() {
    Point start1(15, 10);
    Point end1(49, 25);
    Point start2(29, 5);
    Point end2(32, 32);

    auto answer = intersection(start1, end1, start2, end2);
    cout << "[" << answer->x << ", " << answer->y << "]" << endl;

    return 0;
}
