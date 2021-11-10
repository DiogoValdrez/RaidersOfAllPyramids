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










void swap(int *a, int *b) {
  int temp = *b;
  *b = *a;
  *a = temp;
}

// Function to heapify the tree
void heapify(int array[], int size, int i) {
  if (size == 1) {
    printf("Single element in the heap");
  } else {
    // Find the largest among root, left child and right child
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < size && array[l] > array[largest])
      largest = l;
    if (r < size && array[r] > array[largest])
      largest = r;

    // Swap and continue heapifying if root is not largest
    if (largest != i) {
      swap(&array[i], &array[largest]);
      heapify(array, size, largest);
    }
  }
}

// Function to insert an element into the tree
void insert(int array[], int newNum, int size) {
  if (size == 0) {
    array[0] = newNum;
    size += 1;
  } else {
    array[size] = newNum;
    size += 1;
    for (int i = size / 2 - 1; i >= 0; i--) {
      heapify(array, size, i);
    }
  }
}

// Function to delete an element from the tree
void deleteRoot(int array[], int num, int size) {
  int i;
  for (i = 0; i < size; i++) {
    if (num == array[i])
      break;
  }

  swap(&array[i], &array[size - 1]);
  size -= 1;
  for (int i = size / 2 - 1; i >= 0; i--) {
    heapify(array, size, i);
  }
}

// Print the array
void printArray(int array[], int size) {
  for (int i = 0; i < size; ++i)
    printf("%d ", array[i]);
  printf("\n");
}