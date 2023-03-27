import java.util.*;

class Point {
    double x;
    double y;

    public Point(double x, double y) {
        this.x = x;
        this.y = y;
    }
}

public class GrahamScan {
    // A function to compare two points based on their polar angle
    static class PolarAngleComparator implements Comparator<Point> {
        public int compare(Point p1, Point p2) {
            double angle1 = Math.atan2(p1.y, p1.x);
            double angle2 = Math.atan2(p2.y, p2.x);
            if (angle1 < angle2) return -1;
            else if (angle1 > angle2) return 1;
            else return 0;
        }
    }

    // A function to check if three points make a left turn
    static boolean leftTurn(Point p1, Point p2, Point p3) {
        double crossProduct = (p2.x - p1.x) * (p3.y - p1.y) - (p2.y - p1.y) * (p3.x - p1.x);
        return (crossProduct > 0);
    }

    // A function to compute the convex hull of a set of points using the Graham scan algorithm
    static List<Point> convexHull(Point[] points) {
        // Sort the points based on their polar angle
        Arrays.sort(points, new PolarAngleComparator());

        // Create a stack to hold the points of the convex hull
        Stack<Point> stack = new Stack<Point>();
        stack.push(points[0]);
        stack.push(points[1]);

        // Iterate through the remaining points
        for (int i = 2; i < points.length; i++) {
            // Pop points from the stack while they make a right turn with the next point
            while (stack.size() > 1 && !leftTurn(stack.elementAt(stack.size()-2), stack.peek(), points[i])) {
                stack.pop();
            }
            // Push the next point onto the stack
            stack.push(points[i]);
        }

        // Convert the stack to a list and return it
        List<Point> convexHull = new ArrayList<Point>(stack);
        return convexHull;
    }

    public static void main(String[] args) {
        // Example usage
        Point[] points = { new Point(0, 0), new Point(0, 1), new Point(1, 0), new Point(1, 1), new Point(0.5, 0.5) };
        List<Point> convexHull = convexHull(points);
        System.out.println("Convex Hull:");
        for (Point p : convexHull) {
            System.out.println("(" + p.x + ", " + p.y + ")");
        }
    }
}
