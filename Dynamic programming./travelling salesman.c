// Finds the shortest path between N cities
#include<stdio.h>

#define INF 999999
#define N 4

// Copies one array to another
void copy_array(int n, int src[], int dest[]) {
    for (int i = 0; i < n; i++)
        dest[i] = src[i];
}

// Finds the first unvisited city
int first_unvisited(int n, int visited[]) {
    for (int i = 0; i < n; i++)
        if (!visited[i])
            return i;
    return -1;
}

// Finds shortest path
void tsp(int n, int graph[N][N], int v, int visited[], int nodesVisited, int path[], int pathIndex, int* shortestPathLength, int pathLength, int shortestPath[]) {
    visited[v] = 1;  // Mark the current city as visited
    nodesVisited++;
    path[pathIndex++] = v;  // Add the current city to the path

    // If all cities have been visited
    if (nodesVisited == n) {
        pathLength += graph[v][0];  // Add the distance from the current city to the first city
        // If the current path is shorter than the shortest path found so far
        if (pathLength < *shortestPathLength) {
            *shortestPathLength = pathLength;  // Update the shortest path length
            copy_array(n, path, shortestPath);  // Update the shortest path
        }
    }

    // For each unvisited city
    for (int i = first_unvisited(n, visited); i != -1; i = first_unvisited(n, visited)) {
        pathLength += graph[v][i];  // Add the distance to the next city to the path length
        tsp(n, graph, i, visited, nodesVisited, path, pathIndex, shortestPathLength, pathLength, shortestPath);  // Recurse on the next city
        pathLength -= graph[v][i];  // Remove the distance to the next city from the path length (backtrack)
    }

    visited[v] = 0;  // Mark the current city as unvisited (backtrack)
}

int main() {
    // Define the graph
    int graph[N][N] = { { 0, 10, 15, 20 },
                        { 10, 0, 35, 25 },
                        { 15, 35, 0, 30 },
                        { 20, 25, 30, 0 } };
    int visited[N];
    for (int i = 0; i < N; i++)
        visited[i] = 0;  // Initialize all cities as unvisited
    int path[N];
    int shortestPath[N];
    int shortestPathLength = INF;  // Initialize the shortest path length as infinity
    tsp(N, graph, 0, visited, 0, path, 0, &shortestPathLength, 0, shortestPath);  // Call the tsp function

    // Print the shortest path and its length
    printf("Shortest Path: ");
    for (int i = 0; i < N; i++)
        printf("%d ", shortestPath[i]);
    printf("\nLength: %d\n", shortestPathLength);

    return 0;
}