#include <stdio.h>
#include <stdlib.h>

#define N 6

void findTopoSort(int node, int vis[], int adj[][N], int* index, int topo[]) {
    vis[node] = 1;
    for (int i = 0; i < N; i++) {
        if (adj[node][i] && !vis[i]) {
            findTopoSort(i, vis, adj, index, topo);
        }
    }
    topo[(*index)++] = node;
}

void topoSort(int adj[][N]) {
    int vis[N] = {0};
    int topo[N];
    int index = 0;

    for (int i = 0; i < N; i++) {
        if (!vis[i]) {
            findTopoSort(i, vis, adj, &index, topo);
        }
    }

    printf("Toposort of the given graph is: ");
    for (int i = N - 1; i >= 0; i--) {
        printf("%d ", topo[i]);
    }
}

int main() {
    int adj[N][N] = {0};

    adj[5][2] = 1;
    adj[5][0] = 1;
    adj[4][0] = 1;
    adj[4][1] = 1;
    adj[2][3] = 1;
    adj[3][1] = 1;

    topoSort(adj);
    return 0;
}
