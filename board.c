#include "board.h"
/*
 *  Function:
 *    createBoard
 *
 *  Description:
 *    Main loop of the program for the first submission
 *
 *  Arguments:
 *    Pointer to an array that contains the name of the file;
 *
 *  Return value:
 *    Void;
 *          
 */
void createBoard(char *filename, int type){
  int **bd = NULL;
  graph *adj_matrix = NULL;
  FILE *fp = NULL;
  char *extra = NULL;
  int i;
  int j;
  int k;
  int numb;
  int a;
  int b;
  int varia6[] = {-1, -1};//array containing the coordenates of the second cell for the variant A6
  int var_coord[2];//array containing the coordenates of the cell
  char varia[2];//variable containing the variant value
  int size[2];
  int varia6E = 0;
  int found;
  edge* e;


  fp = getFile(fp,filename,extra,type);
  read(fp, 'd', &(size[0]), bd, size, 0);
  do{
    read(fp, 'd', &(size[1]), bd, size, 0);

    for(i = 0; i<2; i++){
      read(fp, 'd', &(var_coord[i]), bd, size, 0);
    }
    if(type){//Checks what submission we are in
      read(fp, 's', varia, bd, size, 0);
      if(!strcmp(varia, "A6")){
        for(i = 0; i<2; i++){
          read(fp, 'd', &(varia6[i]), bd, size, 0);
        }
        //Checks if the second cell for variant A6 is out of the board
        if (varia6[0] > size[0] || varia6[1] > size[1] || varia6[0] < 1 || varia6[1] < 1){
          varia6E = 1;
        }
      }
    }
    read(fp, 'd', &numb, bd, size, 0);

    //Checks if the cell is out of the board
    if (var_coord[0] > size[0] || var_coord[1] > size[1] || var_coord[0] < 1 || var_coord[1] < 1 || varia6E){
      for(i = 0; i<numb; i++){
        read(fp, 'd', &a, bd, size, 0);
        read(fp, 'd', &b, bd, size, 0);
        read(fp, 'd', &a, bd, size, 0);
      }
      if(type){
        filePrint(-2, filename);
      }else{
        filePrint(-1, filename);
      }
      
      varia6E = 0;
      continue;
    }

    if((bd = (int **)malloc(sizeof(int*)*size[0]))==NULL){
      exit(0);
    }
    for(i = 0; i<size[0]; i++){
      if((bd[i] = (int*)malloc(sizeof(int)*size[1]))==NULL){
        for(j = 0; j<i; j++){
          free(bd[j]);
        }
        free(bd);
        exit(0);
      }
    } 
    for(i = 0; i<size[0]; i++){
      for (j = 0; j<size[1]; j++){
        bd[i][j] = 0;
      }
    }

    for(i = 0; i<numb; i++){
      read(fp, 'd', &a, bd, size, 1);
      /*if(a<0||a>size[0]){
        freeB(bd, size);
        fclose(fp);
        exit(0);
      }*/
      read(fp, 'd', &b, bd, size, 1);
      /*if(b<0||b>size[1]){
        freeB(bd, size);
        fclose(fp);
        exit(0);
      } */   
      read(fp, 'd', &(bd[a-1][b-1]), bd, size, 1);
    }
    if(type){
      decideVar(filename, varia, var_coord, bd, size, varia6, type);
      freeB(bd, size);
    }else{
      //ver se é realmente necessário isto da variante 5
      int xy[2];
      found = 0;
      
      if(bd[var_coord[0]-1][var_coord[1]-1]!=0){
        found = 1;
        filePrint(-1, filename);
      }
      int x = -1;
      for(i = 1; i<=size[0]; i++){
        for(j = 1; j<=size[1]; j++){
          xy[0] = i;
          xy[1] = j;
          if(bd[i-1][j-1] == 0){
            x--;
            Variant6(xy,bd,size,var_coord,x,type);
          }
        }
      }

      //talvez este check possa ser feito mais cedo
      if(bd[0][0] == bd[var_coord[0]-1][var_coord[1]-1]){
        found = 1;
        filePrint(0, filename);
      }
      if(found != 1){
        int z = (-1)*x - 1;

        int obj = bd[var_coord[0]-1][var_coord[1]-1];//pode se meter isto na estrutura

        adj_matrix = newG(z);

        for (i=0;i<size[0]; i++){
          for (j= 0; j<size[1]; j++){
            if (bd[i][j] > 0){
              if(i-1>=0 && i+1<size[0] && bd[i-1][j]<-1 && bd[i+1][j]<-1){
                if((e = (edge*)malloc(sizeof(edge)))==NULL){
                  freeG(adj_matrix);
                  freeB(bd, size);
                  exit(0);
                }
                e->ini = (-1)*(bd[i-1][j]) - 2;
                e->fin = (-1)*(bd[i+1][j]) - 2;
                e->peso = bd[i][j];
                e->i = i;
                e->j = j;
                check_adj(adj_matrix, e);

                if((e = (edge*)malloc(sizeof(edge)))==NULL){
                  freeG(adj_matrix);
                  freeB(bd, size);
                  exit(0);
                }
                e->ini = (-1)*(bd[i+1][j]) - 2;
                e->fin = (-1)*(bd[i-1][j]) - 2;
                e->peso = bd[i][j];
                e->i = i;
                e->j = j;
                check_adj(adj_matrix, e);
              }
              if(j-1>=0 && j+1<size[1]&& bd[i][j+1]<-1 && bd[i][j-1]<-1){
                if((e = (edge*)malloc(sizeof(edge)))==NULL){
                  freeG(adj_matrix);
                  freeB(bd, size);
                  exit(0);
                }
                e->ini = (-1)*(bd[i][j-1]) - 2;
                e->fin = (-1)*(bd[i][j+1]) - 2;
                e->peso = bd[i][j];
                e->i = i;
                e->j = j;
                check_adj(adj_matrix, e);

                if((e = (edge*)malloc(sizeof(edge)))==NULL){
                  freeG(adj_matrix);
                  freeB(bd, size);
                  exit(0);
                }
                e->ini = (-1)*(bd[i][j+1]) - 2;
                e->fin = (-1)*(bd[i][j-1]) - 2;
                e->peso = bd[i][j];
                e->i = i;
                e->j = j;
                check_adj(adj_matrix, e);
              }
            }
          }
        }
        freeB(bd, size);
        int *visited;
        int *dist;
        if( (visited = (int*)malloc(z*sizeof(int)))==NULL){
          freeG(adj_matrix);
          exit(0);
        }
        if((dist = (int*)malloc(z*sizeof(int)))==NULL){
          free(visited);
          freeG(adj_matrix);
          exit(0);
        }


        Dijkstra(adj_matrix, 0, visited, dist);


        
        obj = (-1)*obj - 2;
        if(dist[obj] == -1 || dist[obj] == INT_MAX){//verificar se objetivo é realmente um 0
          filePrint(-1, filename);
          free(visited);
          free(dist);
          freeG(adj_matrix);
          continue;
        }
        filePrint(dist[obj], filename);
        
        i = obj;
        j = i;
        int count = 0;
        while(visited[i] != i){
          i = visited[i]; 
          j = i;         
          count++;
        } 
        //printf("count: %d\n", count);
        filePrint(count, filename);

        int **vect;
        if((vect = (int**)malloc(sizeof(int*)*count)) ==NULL){
          free(visited);
          free(dist);
          freeG(adj_matrix);
          exit(0);
        }
        for(i = 0; i <count;i++){
          if((vect[i] = (int*)malloc(sizeof(int)*3)) == NULL)
          {
            for (k=0;k<i;k++)
            {
              free(vect[k]);
            }
          free(visited);
          free(dist);
          freeG(adj_matrix);
          exit(0);
          }
        }
        count = 0;
        i = obj;
        j = i;
        LinkedList *list;
        edge *item;
      
        while(visited[i] != i){
          list = adj_matrix->adj[i];
          item = (edge*)getItemLinkedList(list);
          i = visited[i];

          while ( item->fin != i)
          {
            list = list->next;
            item = (edge*)getItemLinkedList(list);
          }
        
          vect[count][0] = item->i + 1;
          vect[count][1] = item->j + 1;
          vect[count][2] = item->peso;    
          count++;     
        }
        for(i = count - 1; i>=0; i--){
          filePrintV(vect[i][0],vect[i][1],vect[i][2], filename);
        } 
 


        for(i = 0; i <count;i++){
          free(vect[i]);
        }
        free(vect); 
        
        free(visited);
        
        free(dist);
        freeG(adj_matrix);
        
      }
    }
  }while(fscanf(fp, "%d" , size)==1);
  fclose(fp);
  return;
}

/*
 *  Function:
 *    decideVar
 *
 *  Description:
 *    Checks the variant value and calls the respective variant function;
 *
 *  Arguments:
 *    Pointer to an array that contains the name of the file;
 *    Pointer to an array that contains the Variant;
 *    Pointer to an array that contains the coordenates of the cell;
 *    Double pointer to the board;
 *    Pointer to an array that contains the size of the board;
 *    Pointer to an array that contains the coordenates for the second cell in case of Variant A6;
 *
 *  Return value:
 *    Void;
 *          
 */
void decideVar(char* filename, char varia[2], int var_coord[2], int** bd, int size[2], int varia6[2],int type){
    if (!strcmp(varia, "A1")){
      filePrint(Variant1(var_coord, bd, size), filename);
    }else if (!strcmp(varia, "A2")){
      filePrint(Variant2_4(var_coord, bd, size, 0), filename);
    }else if (!strcmp(varia, "A3")){
      filePrint(Variant3(var_coord,bd,size), filename);
    }else if (!strcmp(varia, "A4")){
      filePrint(Variant2_4(var_coord,bd,size,-1), filename);
    }else if (!strcmp(varia, "A5")){
      filePrint(Variant5(var_coord,bd,size), filename);
    }else if (!strcmp(varia, "A6")){
      filePrint(Variant6(var_coord,bd,size,varia6,-2, type), filename);
    }
    return;
}