#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Point {
    int x, y;
};

// Returns the orientation of the triplet (p, q, r)
int orientation(Point p, Point q, Point r) {
    int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
    if (val == 0) return 0; // colinear
    return (val > 0) ? 1 : 2; // clockwise or counterclockwise
}

// Returns a vector of points that form the convex hull
vector<Point> convexHull(vector<Point> points) {
    int n = points.size();
    if (n < 3) return {}; // Convex hull not possible

    vector<Point> hull;
    int leftmost = 0;
    for (int i = 1; i < n; i++) {
        if (points[i].x < points[leftmost].x) {
            leftmost = i;
        }
    }
    int p = leftmost, q;
    do {
        hull.push_back(points[p]);
        q = (p + 1) % n;
        for (int i = 0; i < n; i++) {
            if (orientation(points[p], points[i], points[q]) == 2) {
                q = i;
            }
        }
        p = q;
    } while (p != leftmost);

    return hull;
}

// Test the convexHull function
int main() {
    vector<Point> points = { {0, 3}, {2, 2}, {1, 1}, {2, 1},
                            {3, 0}, {0, 0}, {3, 3} };
    vector<Point> hull = convexHull(points);
    cout << "Convex Hull points:\n";
    for (auto p : hull) {
        cout << "(" << p.x << "," << p.y << ")\n";
    }
    return 0;
}
