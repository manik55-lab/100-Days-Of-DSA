#include <stdio.h>
#include <limits.h>

#define MAX 100

int graph[MAX][MAX];
int visited[MAX];
int n, m;

int minKey(int key[], int visited[]) {
    int min = INT_MAX, min_index;

    for (int i = 1; i <= n; i++) {
        if (!visited[i] && key[i] < min) {
            min = key[i];
            min_index = i;
        }
    }
    return min_index;
}

int primMST() {
    int key[MAX];

    // Initialize keys
    for (int i = 1; i <= n; i++) {
        key[i] = INT_MAX;
        visited[i] = 0;
    }

    key[1] = 0;  // Start from node 1
    int totalWeight = 0;

    for (int count = 1; count <= n; count++) {
        int u = minKey(key, visited);
        visited[u] = 1;

        totalWeight += key[u];

        // Update adjacent vertices
        for (int v = 1; v <= n; v++) {
            if (graph[u][v] && !visited[v] && graph[u][v] < key[v]) {
                key[v] = graph[u][v];
            }
        }
    }

    return totalWeight;
}

int main() {
    scanf("%d %d", &n, &m);

    // Initialize graph
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            graph[i][j] = 0;
        }
    }

    int u, v, w;

    // Input edges
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &u, &v, &w);

        // For undirected graph, take minimum weight if multiple edges
        if (graph[u][v] == 0 || graph[u][v] > w) {
            graph[u][v] = w;
            graph[v][u] = w;
        }
    }

    int result = primMST();
    printf("%d\n", result);

    return 0;
}