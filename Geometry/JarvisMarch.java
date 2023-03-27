import java.util.ArrayList;
import java.util.List;

public class JarvisMarch {

    // Define a Point class to represent a point with x and y coordinates
    private static class Point {
        double x, y;
        
        public Point(double x, double y) {
            this.x = x;
            this.y = y;
        }
    }

    // A function to find the next point in the convex hull
    private static int nextPoint(List<Point> points, int n, int i) {
        int next = (i + 1) % n; // Initialize next point as the first point in the list
        for (int j = 0; j < n; j++) {
            // If jth point is more counterclockwise than the current next point, update next
            if ((points.get(j).y < points.get(next).y) || (points.get(j).y == points.get(next).y && points.get(j).x > points.get(next).x)) {
                next = j;
            }
        }
        return next;
    }

    // A function to find the convex hull of a set of points using the Jarvis march algorithm
    public static List<Point> convexHull(List<Point> points) {
        int n = points.size();
        // Find the leftmost point in the set
        int leftmost = 0;
        for (int i = 1; i < n; i++) {
            if (points.get(i).x < points.get(leftmost).x) {
                leftmost = i;
            }
        }

        // Start from the leftmost point and move counterclockwise to find the convex hull
        int p = leftmost, q;
        List<Point> hull = new ArrayList<>();
        do {
            // Add the current point to the convex hull
            hull.add(points.get(p));

            // Find the next point in the convex hull
            q = nextPoint(points, n, p);
            p = q;
        } while (p != leftmost); // Continue until we've gone all the way around the convex hull

        return hull;
    }

    public static void main(String[] args) {
        // Example usage
        List<Point> points = new ArrayList<>();
        points.add(new Point(0, 3));
        points.add(new Point(1, 1));
        points.add(new Point(2, 2));
        points.add(new Point(4, 4));
        points.add(new Point(0, 0));
        points.add(new Point(1, 2));
        points.add(new Point(3, 1));
        points.add(new Point(3, 3));
        
        List<Point> hull = convexHull(points);
        // Print the points of the convex hull
        for (Point p : hull) {
            System.out.println("(" + p.x + ", " + p.y + ")");
        }
    }
}
