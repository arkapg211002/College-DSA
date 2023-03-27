#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct point {
  double x;
  double y;
} Point;

// A function to compare two points based on their polar angle
int compare(const void* vp1, const void* vp2) {
  Point* p1 = (Point*) vp1;
  Point* p2 = (Point*) vp2;
  double angle1 = atan2(p1->y, p1->x);
  double angle2 = atan2(p2->y, p2->x);
  if (angle1 < angle2) return -1;
  else if (angle1 > angle2) return 1;
  else return 0;
}

// A function to check if three points make a left turn
int left_turn(Point p1, Point p2, Point p3) {
  double cross_product = (p2.x - p1.x) * (p3.y - p1.y) - (p2.y - p1.y) * (p3.x - p1.x);
  return (cross_product > 0);
}

// A function to compute the convex hull of a set of points using the Graham scan algorithm
void convex_hull(Point* points, int num_points) {
  // Sort the points based on their polar angle
  qsort(points, num_points, sizeof(Point), compare);

  // Create a stack to hold the points of the convex hull
  Point* stack = (Point*) malloc(num_points * sizeof(Point));
  int top = 2;
  stack[0] = points[0];
  stack[1] = points[1];

  // Iterate through the remaining points
  for (int i = 2; i < num_points; i++) {
    // Pop points from the stack while they make a right turn with the next point
    while (top > 0 && !left_turn(stack[top-2], stack[top-1], points[i])) {
      top--;
    }
    // Push the next point onto the stack
    stack[top] = points[i];
    top++;
  }

  // Print the points of the convex hull
  printf("Convex Hull:\n");
  for (int i = 0; i < top; i++) {
    printf("(%lf, %lf)\n", stack[i].x, stack[i].y);
  }

  // Free the memory allocated for the stack
  free(stack);
}

int main() {
  // Example usage
  Point points[] = { {0, 0}, {0, 1}, {1, 0}, {1, 1}, {0.5, 0.5} };
  int num_points = sizeof(points) / sizeof(Point);
  convex_hull(points, num_points);

  return 0;
}
