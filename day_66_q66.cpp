#include <stdio.h>
#include <stdbool.h>

#define MAX 100

// Function to perform DFS and detect cycle
bool isCycleUtil(int v, int V, int adj[MAX][MAX], bool visited[], bool recStack[]) {
    visited[v] = true;
    recStack[v] = true;

    for (int i = 0; i < V; i++) {
        if (adj[v][i]) {
            if (!visited[i]) {
                if (isCycleUtil(i, V, adj, visited, recStack))
                    return true;
            }
            else if (recStack[i]) {
                return true;
            }
        }
    }

    recStack[v] = false;
    return false;
}

// Main function to check cycle
bool isCycle(int V, int adj[MAX][MAX]) {
    bool visited[MAX] = {false};
    bool recStack[MAX] = {false};

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            if (isCycleUtil(i, V, adj, visited, recStack))
                return true;
        }
    }
    return false;
}

int main() {
    int V, E;
    int adj[MAX][MAX] = {0};

    printf("Enter number of vertices: ");
    scanf("%d", &V);

    printf("Enter number of edges: ");
    scanf("%d", &E);

    printf("Enter edges (u v):\n");
    for (int i = 0; i < E; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;  // directed edge
    }

    if (isCycle(V, adj))
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}