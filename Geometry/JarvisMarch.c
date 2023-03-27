#include <stdio.h>

typedef struct Point {
    double x;
    double y;
} Point;

// A function to find the next point in the convex hull
int nextPoint(Point points[], int n, int i) {
    int next = (i + 1) % n; // Initialize next point as the first point in the array
    for (int j = 0; j < n; j++) {
        // If jth point is more counterclockwise than the current next point, update next
        if ((points[j].y < points[next].y) || (points[j].y == points[next].y && points[j].x > points[next].x)) {
            next = j;
        }
    }
    return next;
}

// A function to find the convex hull of a set of points using the Jarvis march algorithm
void convexHull(Point points[], int n) {
    // Find the leftmost point in the set
    int leftmost = 0;
    for (int i = 1; i < n; i++) {
        if (points[i].x < points[leftmost].x) {
            leftmost = i;
        }
    }

    // Start from the leftmost point and move counterclockwise to find the convex hull
    int p = leftmost, q;
    do {
        // Add the current point to the convex hull
        printf("(%f, %f)\n", points[p].x, points[p].y);

        // Find the next point in the convex hull
        q = nextPoint(points, n, p);
        p = q;
    } while (p != leftmost); // Continue until we've gone all the way around the convex hull
}

int main() {
    // Example usage
    Point points[] = { {0, 3}, {1, 1}, {2, 2}, {4, 4}, {0, 0}, {1, 2}, {3, 1}, {3, 3} };
    int n = sizeof(points) / sizeof(points[0]);
    convexHull(points, n);

    return 0;
}
