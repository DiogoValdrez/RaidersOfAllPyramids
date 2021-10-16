#include "file_handling.h"
#include "variants.h"

void createBoard(char *filename){
  int **bd;
  FILE *fp;
  int i;
  int j;
  int numb;
  int a;
  int b;
  int varia6[2];
  int var_coord[2];//variavel para coordenadas da variane
  char varia[2];//variavel com a variante
  int size[2];
  char *extra;

  if((fp = fopen(filename, "r"))==NULL){
    exit(0);
  }

  extra = &filename[strlen(filename)-4];
  *extra = '\0';
  strcat(filename, ".sol1");//!no retrun value for error

  if(!fscanf(fp, "%d" , size)){
    fclose(fp);
    exit(0);
  }
  do{
    if(!fscanf(fp, "%d" , &(size[1]))){
      fclose(fp);
      exit(0);
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


    //!ter atenção caso o numb esteja errado

    for(i = 0; i<2; i++){
      if(!fscanf(fp, "%d" , &(var_coord[i]))){//!make function to do this verification
      freeB(bd, size);
      fclose(fp);
      exit(0);
      }
    }
    if(!fscanf(fp, "%s", varia)){
      freeB(bd, size);
      fclose(fp);
      exit(0);
      }
    if(!strcmp(varia, "A6")){
      for(i = 0; i<2; i++){
        if(!fscanf(fp, "%d" , &(varia6[i]))){
          freeB(bd, size);
          fclose(fp);
          exit(0);
        }
      }
    }
    
    if(!fscanf(fp, "%d", &numb)){
      freeB(bd, size);
      fclose(fp);
      exit(0);
    }
    for(i = 0; i<numb; i++){
      
      if(!fscanf(fp, "%d", &a)){
        freeB(bd, size);
        fclose(fp);
        exit(0);
      }
      /*if(a<0||a>size[0]){
        freeB(bd, size);
        fclose(fp);
        exit(0);
      }*/
      if(!fscanf(fp, "%d", &b)){
        freeB(bd, size);
        fclose(fp);
        exit(0);
      }
      /*if(b<0||b>size[1]){
        freeB(bd, size);
        fclose(fp);
        exit(0);
      } */   
      if(!fscanf(fp, "%d", &(bd[a-1][b-1]))){
        freeB(bd, size);
        fclose(fp);
        exit(0);
      }
    }

    //!depois vamos trocar isto para um ficheiro á parte, mas por enquanto fica aqui
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
void filePrint(int value, char *filename){
  FILE *fp;

  if((fp = fopen(filename, "a"))==NULL){
    exit(0);
  }
  fprintf(fp, "%d\n", value);
  fprintf(fp, "\n");
  fclose(fp);
  return;
}

void freeB(int **bd,int *size){
  int i;
  for(i = 0; i<size[0]; i++){
      free(bd[i]);
    }
  free(bd);
  return;
}
