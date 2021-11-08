#include "dijkstra.h"

void Dijkstra(int **Graph, int x, int start) {
    int cost[x][x], distance[x], pred[x];
    int visited[x], count, mindistance, nextnode, i, j;

    // Creating cost matrix
    for (i = 0; i < x; i++)
        for (j = 0; j < x; j++)
        if (Graph[i][j] == 0)
            cost[i][j] = -1;
        else
            cost[i][j] = Graph[i][j];

    for (i = 0; i < x; i++) {
        distance[i] = cost[start][i];
        pred[i] = start;
        visited[i] = 0;
    }

    distance[start] = 0;
    visited[start] = 1;
    count = 1;

    while (count < x - 1) {
        mindistance = -1;

        for (i = 0; i < x; i++)
        if (distance[i] < mindistance && !visited[i]) {//a partir de aqui ter em atenção que temos de verificar todos os -1 em vez de ser só menor
            mindistance = distance[i];
            nextnode = i;
        }

        visited[nextnode] = 1;
        for (i = 0; i < x; i++)
        if (!visited[i])
            if (mindistance + cost[nextnode][i] < distance[i]) {
            distance[i] = mindistance + cost[nextnode][i];
            pred[i] = nextnode;
            }
        count++;
    }

    // Printing the distance
    for (i = 0; i < x; i++)
        if (i != start) {
        printf("\nDistance from source to %d: %d\n", i, distance[i]);
        }
}