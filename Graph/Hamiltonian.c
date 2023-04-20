#include <stdio.h>
#include <stdbool.h>

#define N 5

bool dfs(int graph[N][N], bool visited[N], int start, int current, int count);
bool hasHamiltonianCycle(int graph[N][N]);

int main() {
    // example graph
    int graph[N][N] = {
        {0, 1, 0, 1, 0},
        {1, 0, 1, 1, 1},
        {0, 1, 0, 0, 1},
        {1, 1, 0, 0, 1},
        {0, 1, 1, 1, 0}
    };
    
    if (hasHamiltonianCycle(graph)) {
        printf("Hamiltonian Cycle exists in the graph\n");
    } else {
        printf("Hamiltonian Cycle does not exist in the graph\n");
    }
    
    return 0;
}

bool hasHamiltonianCycle(int graph[N][N]) {
    bool visited[N];

    // try starting DFS from each vertex
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            visited[j] = false;
        }
        if (dfs(graph, visited, i, i, 1)) {
            return true;
        }
    }

    // no Hamiltonian cycle found
    return false;
}

bool dfs(int graph[N][N], bool visited[N], int start, int current, int count) {
    visited[current] = true;

    // check if all vertices have been visited and if the last vertex is adjacent to the starting vertex
    if (count == N && graph[current][start] == 1) {
        return true;
    }

    // recursively explore unvisited neighbors
    for (int neighbor = 0; neighbor < N; neighbor++) {
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
