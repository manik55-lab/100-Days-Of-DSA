#include <stdio.h>
#include <stdbool.h>

#define MAX 100

int graph[MAX][MAX];
int V;

// Stack
int stack[MAX], top = -1;

void push(int node) {
    stack[++top] = node;
}

// DFS function
void dfs(int node, bool visited[]) {
    visited[node] = true;

    for (int i = 0; i < V; i++) {
        if (graph[node][i] && !visited[i]) {
            dfs(i, visited);
        }
    }

    // Push after visiting all neighbors
    push(node);
}

// Topological Sort function
void topoSort() {
    bool visited[MAX] = {false};

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            dfs(i, visited);
        }
    }

    // Print stack (reverse order)
    printf("Topological Order:\n");
    while (top != -1) {
        printf("%d ", stack[top--]);
    }
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

    printf("Enter edges (u v):\n");
    for (int i = 0; i < E; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        graph[u][v] = 1; // directed edge
    }

    topoSort();

    return 0;
}