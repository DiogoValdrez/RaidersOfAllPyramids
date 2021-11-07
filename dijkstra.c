#include "dijkstra.h"

int minDistance(int *dist, bool *sptSet, int x)
{
    // Initialize min value
    int min = INT_MAX;
    int min_index;
    int v;
 
    for (v = 0; v < x; v++)
        if (sptSet[v] == false && dist[v] <= min){
            min = dist[v];
            min_index = v;
        }
 
    return min_index;
}
 
// A utility function to print the constructed distance array
void printSolution(int *dist, int x)
{
    int i;
    printf("Vertex \t\t Distance from Source\n");
    for (i = 0; i < x; i++)
        printf("%d \t\t %d\n", i, dist[i]);
}
 
// Function that implements Dijkstra's single source shortest path algorithm
// for a graph represented using adjacency matrix representation
void dijkstra(int **adj_matrix, int src, int x)
{
    int i, j, u, v;
    x = (-1)*x - 1; 
    int *dist; // The output array.  dist[i] will hold the shortest
    // distance from src to i
    if((dist = (int *)malloc(sizeof(int)*x)) == NULL){
        exit(0);
    }
 
    bool *sptSet; // sptSet[i] will be true if vertex i is included in shortest
    // path tree or shortest distance from src to i is finalized
    if((sptSet = (bool *)malloc(sizeof(bool)*x)) == NULL){
        exit(0);
    }
 
    // Initialize all distances as INFINITE and stpSet[] as false
    for (i = 0; i < x; i++){
        dist[i] = INT_MAX;
        sptSet[i] = false;
    }
    
 
    // Distance of source vertex from itself is always 0
    dist[src] = 0;
    // Find shortest path for all vertices
    for (j = 0; j < (x - 1); j++) {
        // Pick the minimum distance vertex from the set of vertices not
        // yet processed. u is always equal to src in the first iteration.
        u = minDistance(dist, sptSet, x);
        for (i = 0; i < x; i++)
            printf("%d \t\t %d \t\t %d\n", i, dist[i], sptSet[i]);
        // Mark the picked vertex as processed
        sptSet[u] = true;
 
        // Update dist value of the adjacent vertices of the picked vertex.
        for (v = 0; v < x; v++){
 
            // Update dist[v] only if is not in sptSet, there is an edge from
            // u to v, and total weight of path from src to  v through u is
            // smaller than current value of dist[v]
            if (!sptSet[v] && adj_matrix[u][v] && dist[u] != INT_MAX && dist[u] + adj_matrix[u][v] < dist[v]){
                dist[v] = dist[u] + adj_matrix[u][v];
            }
        }
    }
 
    // print the constructed distance array
    printf("\n\n");
    printSolution(dist, x);
    printf("\n\n");
    for (i = 0; i < x; i++){
        printf("%d: %d\t", i +1, sptSet[i]);
    }

}