#include <stdio.h>
#define INF 99999  // A large value representing infinity

void floydWarshall(int graph[][4], int V) {
    int dist[V][V], i, j, k;

    // Initialize the solution matrix as the input graph matrix
    for (i = 0; i < V; i++) {
        for (j = 0; j < V; j++) {
            dist[i][j] = graph[i][j];
        }
    }

    // Floyd-Warshall algorithm
    for (k = 0; k < V; k++) {
        for (i = 0; i < V; i++) {
            for (j = 0; j < V; j++) {
                if (dist[i][j] > dist[i][k] + dist[k][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    // Print the shortest distance matrix
    printf("Shortest distances between every pair of vertices:\n");
    for (i = 0; i < V; i++) {
        for (j = 0; j < V; j++) {
            if (dist[i][j] == INF) {
                printf("%7s", "INF");
            } else {
                printf("%7d", dist[i][j]);
            }
        }
        printf("\n");
    }
}

int main() {
    // Example graph (4 vertices, adjacency matrix representation)
    int graph[4][4] = {
        {0, INF, 3, INF},
        {2, 0, INF, INF},
        {INF, 7, 0, 1},
        {6, INF, INF, 0}
    };

    int V = 4; // Number of vertices

    floydWarshall(graph, V);

    return 0;
}