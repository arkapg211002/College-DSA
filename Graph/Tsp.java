import java.util.*;

public class TSP {

    public static int tsp(int[][] graph, int start, int[] visited, int n, int[][] memo) {
        if (visited[start] == (1 << n) - 1) {
            return graph[start][0];
        }
        if (visited[start] > 0 && memo[start][visited[start]] != 0) {
            return memo[start][visited[start]];
        }
        visited[start] |= (1 << start);
        int minCost = Integer.MAX_VALUE;
        for (int i = 0; i < n; i++) {
            if (i == start || graph[start][i] == -1 || (visited[start] & (1 << i)) > 0) {
                continue;
            }
            int cost = graph[start][i] + tsp(graph, i, visited, n, memo);
            minCost = Math.min(minCost, cost);
        }
        visited[start] &= ~(1 << start);
        memo[start][visited[start]] = minCost;
        return minCost;
    }

    public static void main(String[] args) {
        int n = 4;
        int[][] graph = {{0, 10, -1, 20}, {-1, 0, 35, -1}, {15, -1, 0, 30}, {20, -1, 30, 0}};
        int[] visited = new int[n];
        int[][] memo = new int[n][(1 << n) - 1];
        System.out.println("Minimum Cost: " + tsp(graph, 0, visited, n, memo));
    }
}
