#include "dijkstra.h"

void Dijkstra(int **cost, int x, int start, int* distance, int* pred, int* visited) {//tirar os tart e por apenas 0
    int count, mindistance, i, j;
    int nextnode = 0;

    // Creating cost matrix
    for (i = 0; i < x; i++)
        for (j = 0; j < x; j++)
        if (cost[i][j] == -1)
            cost[i][j] = INT_MAX;//por -1 logo na matriz de adjacencias

    for (i = 0; i < x; i++) {
        distance[i] = cost[start][i];
        pred[i] = start;
        visited[i] = 0;
    }

    distance[start] = 0;
    visited[start] = 1;
    count = 1;

    /* print da matriz de custos
    for (i = 0; i < x; i++){
        for (j = 0; j < x; j++){
            printf("%d ", cost[i][j]);
        }
        printf("\n");
    }*/

    while (count < x - 1) {
        mindistance = INT_MAX;

        for (i = 0; i < x; i++)
        if (( distance[i] < mindistance && !visited[i])&&distance[i] > 0) {//a partir de aqui ter em atenção que temos de verificar todos os -1 em vez de ser só menor
            mindistance = distance[i];
            nextnode = i;
        }

        visited[nextnode] = 1;
        for (i = 0; i < x; i++)
        if (!visited[i]){
            if ((mindistance + cost[nextnode][i] < distance[i])&& mindistance + cost[nextnode][i] > 0){//aqui
            distance[i] = mindistance + cost[nextnode][i];
            pred[i] = nextnode;
            }
        }
        count++;
    }

    // Printing the distance
    for (i = 0; i < x; i++){
        if(distance[i] == INT_MAX || distance[i] < 0) {
            distance[i] = -1;
        }
        if (i != start) {
        //printf("\nDistance from source to %d: %d\n", i, distance[i]);
        }
    }
}