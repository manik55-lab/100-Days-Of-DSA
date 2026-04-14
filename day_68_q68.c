#include <stdio.h>

#define MAX 100

int graph[MAX][MAX];
int indegree[MAX];
int V;

// Queue
int queue[MAX], front = 0, rear = -1;

void enqueue(int x) {
    queue[++rear] = x;
}

int dequeue() {
    return queue[front++];
}

int isEmpty() {
    return front > rear;
}

void kahnTopoSort() {
    // Step 1: Calculate in-degree
    for (int i = 0; i < V; i++) {
        indegree[i] = 0;
    }

    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (graph[i][j]) {
                indegree[j]++;
            }
        }
    }

    // Step 2: Add nodes with in-degree 0
    for (int i = 0; i < V; i++) {
        if (indegree[i] == 0) {
            enqueue(i);
        }
    }

    int count = 0;

    printf("Topological Order:\n");

    // Step 3: Process queue
    while (!isEmpty()) {
        int node = dequeue();
        printf("%d ", node);
        count++;

        for (int i = 0; i < V; i++) {
            if (graph[node][i]) {
                indegree[i]--;
                if (indegree[i] == 0) {
                    enqueue(i);
                }
            }
        }
    }

    // Step 4: Check for cycle
    if (count != V) {
        printf("\nCycle detected! Topological sort not possible.\n");
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

    kahnTopoSort();

    return 0;
}