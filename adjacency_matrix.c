#include "adjacency_matrix.h"
void new_edge(int **adj_matrix, int vert1, int vert2, int weight)
{
    int ind1 = (-1)*vert1 - 2;
    int ind2 = (-1)*vert2 - 2;

    if (adj_matrix[ind1][ind2] == -1 || adj_matrix[ind1][ind2] > weight)
    {
        adj_matrix[ind1][ind2] = weight;
        adj_matrix[ind2][ind1] = weight;
    }
}



int **create_adj_matrix(int **bd, int *size, int **adj_matrix, int x)
{
    int i,j;
    x = (-1)*x -1;
    //Allocate space for matrix and initialize it with the value of -1
    if((adj_matrix = (int **)malloc(sizeof(int*)*x))==NULL){
      exit(0);
    }
    for(i = 0; i<x; i++){
      if((adj_matrix[i] = (int*)malloc(sizeof(int)*x))==NULL){
        for(j = 0; j<i; j++){
          free(adj_matrix[j]);
        }
        free(adj_matrix);
        exit(0);
      }
    } 
    for(i = 0; i<x; i++){
      for (j = 0; j<x; j++){
        if (i==j){
            adj_matrix[i][j] = 0;
        }else{
            adj_matrix[i][j] = 1000000;
        }
      }
    }

    //Go through bd to check walls and fill adjacecny matrix
    for (i=0;i<size[0]; i++)
    {
        for (j= 0; j<size[1]; j++)
        {
            if (bd[i][j] > 0)
            {
                if ((i == 0 || i == (size[0] - 1)))
                {
                    if (bd[i][j-1] < -1 && bd[i][j+1] < -1 && j != 0 && j != (size[2]-1))
                    {
                        new_edge(adj_matrix, bd[i][j-1], bd[i][j+1], bd[i][j]);
                    }
                }else if ((j == 0 || j == (size[1] - 1)) )
                {
                    if (bd[i-1][j] < -1 && bd[i+1][j] < -1 && i != 0 && i != (size[0]-1))
                    {
                        new_edge(adj_matrix, bd[i-1][j], bd[i+1][j], bd[i][j]);
                    }
                }else
                {
                    if (bd[i][j-1] < -1 && bd[i][j+1] < -1)
                    {
                        new_edge(adj_matrix, bd[i][j-1], bd[i][j+1], bd[i][j]);
                    }else if(bd[i-1][j] < -1 && bd[i+1][j] < -1)
                    {
                        //printf("%d", bd[i+1][j]);
                        new_edge(adj_matrix, bd[i-1][j], bd[i+1][j], bd[i][j]);
                    }
                }
            }
        }
        
    }
    
    /* for (int i=0; i<x; i++){
        for(j= 0; j<x; j++){
            printf("%d ", adj_matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n"); */
    return adj_matrix;
}

void free_adj_matrix(int **adj_matrix, int x)
{
    int i;
    x = (-1)*x - 1;
    for(i = 0; i<x; i++){
        free(adj_matrix[i]);
    }
    free(adj_matrix);
    return;
}
