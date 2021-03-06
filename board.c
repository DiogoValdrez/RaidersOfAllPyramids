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
void createBoard(char *filename){
  int **bd = NULL;
  FILE *fp = NULL;
  char *extra = NULL;
  int i;
  int j;
  int numb;
  int a;
  int b;
  int varia6[] = {-1, -1};//array containing the coordenates of the second cell for the variant A6
  int var_coord[2];//array containing the coordenates of the cell
  char varia[2];//variable containing the variant value
  int size[2];
  int varia6E = 0;

  fp = getFile(fp,filename,extra);
  read(fp, 'd', &(size[0]), bd, size, 0);
  do{
    read(fp, 'd', &(size[1]), bd, size, 0);

    for(i = 0; i<2; i++){
      read(fp, 'd', &(var_coord[i]), bd, size, 0);
    }
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
    read(fp, 'd', &numb, bd, size, 0);

    //Checks if the cell is out of the board
    if (var_coord[0] > size[0] || var_coord[1] > size[1] || var_coord[0] < 1 || var_coord[1] < 1 || varia6E){
      for(i = 0; i<numb; i++){
        read(fp, 'd', &a, bd, size, 0);
        read(fp, 'd', &b, bd, size, 0);
        read(fp, 'd', &a, bd, size, 0);
      }
      filePrint(-2, filename);
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

    decideVar(filename, varia, var_coord, bd, size, varia6);

    //Print the board for testing
    /*
    for(i = 0; i<size[0]; i++){
      for (j = 0; j<size[1]; j++){
        printf("%d ", bd[i][j]);
      }
      printf("\n");
    }
    printf("\n");
    */
    
    freeB(bd, size);

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
void decideVar(char* filename, char varia[2], int var_coord[2], int** bd, int size[2], int varia6[2]){
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
      filePrint(Variant6(var_coord,bd,size,varia6), filename);
    }
    return;
}