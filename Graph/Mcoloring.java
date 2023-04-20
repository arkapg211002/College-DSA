public class MColoringProblem {

    public static boolean mColoring(int[][] graph, int m) {
        int[] colors = new int[graph.length];
        return mColoringUtil(graph, colors, 0, m);
    }

    private static boolean mColoringUtil(int[][] graph, int[] colors, int v, int m) {
        if (v == graph.length) {
            return true;
        }
        for (int c = 1; c <= m; c++) {
            if (isValidColor(graph, colors, v, c)) {
                colors[v] = c;
                if (mColoringUtil(graph, colors, v + 1, m)) {
                    return true;
                }
                colors[v] = 0;
            }
        }
        return false;
    }

    private static boolean isValidColor(int[][] graph, int[] colors, int v, int c) {
        for (int i = 0; i < graph.length; i++) {
            if (graph[v][i] == 1 && c == colors[i]) {
                return false;
            }
        }
        return true;
    }

    public static void main(String[] args) {
        int[][] graph = {{0, 1, 1, 1},
                         {1, 0, 1, 0},
                         {1, 1, 0, 1},
                         {1, 0, 1, 0}};
        int m = 3;
        if (mColoring(graph, m)) {
            System.out.println("Graph can be colored with " + m + " colors.");
        } else {
            System.out.println("Graph cannot be colored with " + m + " colors.");
        }
    }
}
