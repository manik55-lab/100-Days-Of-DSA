#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

#define MAX 100

int V;
int graph[MAX][MAX];

// Min distance vertex (used instead of STL priority queue)
int minDistance(int dist[], bool visited[]) {
    int min = INT_MAX, min_index;

    for (int i = 0; i < V; i++) {
        if (!visited[i] && dist[i] <= min) {
            min = dist[i];
            min_index = i;
        }
    }
    return min_index;
}

// Dijkstra Algorithm
void dijkstra(int src) {
    int dist[MAX];
    bool visited[MAX];

    // Initialize
    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
        visited[i] = false;
    }

    dist[src] = 0;

    // Find shortest path for all vertices
    for (int count = 0; count < V - 1; count++) {
        int u = minDistance(dist, visited);
        visited[u] = true;

        // Update neighbors
        for (int v = 0; v < V; v++) {
            if (!visited[v] && graph[u][v] &&
                dist[u] != INT_MAX &&
                dist[u] + graph[u][v] < dist[v]) {

                dist[v] = dist[u] + graph[u][v];
                }
        }
    }

    // Print result
    printf("Vertex \t Distance from Source\n");
    for (int i = 0; i < V; i++) {
        printf("%d \t %d\n", i, dist[i]);
    }
}

// Driver
int main() {
    int E;
    printf("Enter number of vertices and edges: ");
    scanf("%d %d", &V, &E);

    // Initialize graph
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            graph[i][j] = 0;

    printf("Enter edges (u v w):\n");
    for (int i = 0; i < E; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        graph[u][v] = w; // directed
    }

    int src;
    printf("Enter source vertex: ");
    scanf("%d", &src);

    dijkstra(src);

    return 0;
}