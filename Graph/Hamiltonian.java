import java.util.Arrays;

public class HamiltonianCycle {
    
    public static boolean hasHamiltonianCycle(int[][] graph) {
        int n = graph.length;
        boolean[] visited = new boolean[n];

        // try starting DFS from each vertex
        for (int i = 0; i < n; i++) {
            Arrays.fill(visited, false);
            if (dfs(graph, visited, i, i, 1)) {
                return true;
            }
        }

        // no Hamiltonian cycle found
        return false;
    }

    private static boolean dfs(int[][] graph, boolean[] visited, int start, int current, int count) {
        visited[current] = true;

        // check if all vertices have been visited and if the last vertex is adjacent to the starting vertex
        if (count == graph.length && graph[current][start] == 1) {
            return true;
        }

        // recursively explore unvisited neighbors
        for (int neighbor = 0; neighbor < graph.length; neighbor++) {
            if (graph[current][neighbor] == 1 && !visited[neighbor]) {
                if (dfs(graph, visited, start, neighbor, count+1)) {
                    return true;
                }
            }
        }

        // backtrack
        visited[current] = false;
        return false;
    }

    public static void main(String[] args) {
        // example graph
        int[][] graph = {
            {0, 1, 0, 1, 0},
            {1, 0, 1, 1, 1},
            {0, 1, 0, 0, 1},
            {1, 1, 0, 0, 1},
            {0, 1, 1, 1, 0}
        };
        
        if (hasHamiltonianCycle(graph)) {
            System.out.println("Hamiltonian Cycle exists in the graph");
        } else {
            System.out.println("Hamiltonian Cycle does not exist in the graph");
        }
    }
}
