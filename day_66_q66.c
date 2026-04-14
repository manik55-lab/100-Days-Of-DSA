#include <stdio.h>
#include <stdbool.h>

#define MAX 100

// Adjacency list
int graph[MAX][MAX];
int V;

// DFS function to detect cycle
bool dfs(int node, bool visited[], bool recStack[]) {
    visited[node] = true;
    recStack[node] = true;

    for (int i = 0; i < V; i++) {
        if (graph[node][i]) {  // edge exists
            // If not visited, recurse
            if (!visited[i] && dfs(i, visited, recStack))
                return true;

            // If node is in recursion stack → cycle
            else if (recStack[i])
                return true;
        }
    }

    recStack[node] = false; // remove from recursion stack
    return false;
}

// Function to check cycle in graph
bool isCycle() {
    bool visited[MAX] = {false};
    bool recStack[MAX] = {false};

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            if (dfs(i, visited, recStack))
                return true;
        }
    }
    return false;
}

// Driver code
int main() {
    int E;
    printf("Enter number of vertices and edges: ");
    scanf("%d %d", &V, &E);

    // Initialize graph
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            graph[i][j] = 0;

    printf("Enter edges (u v) for directed graph:\n");
    for (int i = 0; i < E; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        graph[u][v] = 1; // directed edge
    }

    if (isCycle())
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}