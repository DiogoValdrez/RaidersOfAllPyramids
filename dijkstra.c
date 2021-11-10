#include "dijkstra.h"

void Dijkstra(int **cost, int x, int start, int* distance, int* pred, int* visited) {//tirar os tart e por apenas 0
    int count, mindistance, i, j;//count n é necessario provavekmente
    heap** array = malloc(sizeof(heap*)*x);
    int size = 0;
    int u;
    heap* h;

    // Creating cost matrix
    for (i = 0; i < x; i++)//apagar tralha a mais
        for (j = 0; j < x; j++)
        if (cost[i][j] == -1)
            cost[i][j] = INT_MAX;//por -1 logo na matriz de adjacencias

    for (i = 0; i < x; i++) {
        distance[i] = INT_MAX;//aqui pode dar problemas pq esta diferente do codigo antigo
        pred[i] = start;
        visited[i] = 0;
        h = (heap*)malloc(sizeof(heap));
        h->V = i;
        h->value = distance[i];
        insert(array,h,&size);

        
    }   
    distance[start] = 0;
    visited[start] = 1;
    count = 1;

    //print da matriz de custos
    /* for (i = 0; i < x; i++){
        for (j = 0; j < x; j++){
            printf("%d ", cost[i][j]);
        }
        printf("\n");
    } */


    printArray(array,&size);
    printf("\n");
    while(size > 0){
      //mindistance = INT_MAX;
      
      u = deleteRoot(array, 0, &size);
      //mindistance = distance[u];

      visited[u]=1;
      printf("%d|", distance[u]);

      for(i = 0; i < x; i++){//vizinhos de u????
        if(!visited[i]){
          if((distance[u] + cost[u][i] < distance[i])&& distance[u] + cost[u][i] > 0){
            distance[i] = distance[u] + cost[u][i];
            pred[i] = u;
          }
        }      
      }     
      count++;
    }













    /* while(size > 0){
      mindistance = INT_MAX;
      u = deleteRoot(array, 0, &size);
      if(distance[u]!=INT_MAX){
        for(i = 0; i < x; i++){//vizinhos de u????
          if(cost[u][i]!=INT_MAX && cost[u][i]!=0){//necessario
            mindistance = distance[u] + cost[u][i];
            if(mindistance < distance[i]){//tirar min > o
              distance[i] = mindistance;
              pred[i] = u;
            }//talvez aqui um else
          }       
        }
      }     
      count++;
    } */

    // Printing the distance
    for (i = 0; i < x; i++){
        if(distance[i] == INT_MAX || distance[i] < 0) {
            distance[i] = -1;
        }
        if (i != start) {
        //printf("\nDistance from source to %d: %d\n", i, distance[i]);
        }
    }
    free(array);
}










void swap(heap **a, heap **b) {
  heap* temp = *b;
  *b = *a;
  *a = temp;
}

// Function to heapify the tree
void heapify(heap** array, int* size, int i) {
  if (*size == 1) {
    //printf("Single element in the heap");
  } else {
    // Find the largest among root, left child and right child
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < *size && array[l]->value < array[largest]->value)
      largest = l;
    if (r < *size && array[r]->value < array[largest]->value)
      largest = r;

    // Swap and continue heapifying if root is not largest
    if (largest != i) {
      swap(&array[i], &array[largest]);
      heapify(array, size, largest);//we dont like recursivas 
    }
  }
}

// Function to insert an element into the tree
void insert(heap** array, heap* h, int* size) {
  int i;
  if (*size == 0) {
    array[0] = h;
    *size += 1;
  } else {
    array[*size] = h;
    *size += 1;
    for (i = *size / 2 - 1; i >= 0; i--) {
      heapify(array, size, i);
    }
  }
}

// Function to delete an element from the tree
int deleteRoot(heap** array, int num, int* size) {//modifiquei este tambem
  int i, r;
  r = array[num]->V;
  for (i = 0; i < *size; i++) {
    if (num == array[i]->V)
      break;
  }
  swap(&array[num], &array[*size - 1]);
  *size -= 1;
  for (i = *size / 2 - 1; i >= 0; i--) {
    heapify(array, size, i);
  }
  return r;
}

// Print the array
void printArray(heap** array, int* size) {
  int i;
  for (i = 0; i < *size; ++i)
    printf("%d ", array[i]->value);
  printf("\n");
  for (i = 0; i < *size; ++i)
    printf("%d ", array[i]->V);
  printf("\n");
} 