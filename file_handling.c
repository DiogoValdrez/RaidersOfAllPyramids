#include "file_handling.h"
#include "variants.h"
//!por a estrutura num sitio e a leitura e escrita de ficherios noutro
int** createBoard(char filename[24]){
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

  fp = fopen(filename, "r");//!fazer verificações

  char *extra = &filename[strlen(filename)-4];//!isto destroi o filename,depois arrajamos
  *extra = '\0';
  strcat(filename, ".sol1");

  fscanf(fp, "%d" , size);
  do{
    fscanf(fp, "%d" , &(size[1]));

    bd = (int **)malloc(sizeof(int*)*size[0]);//fazer verificações
    for(i = 0; i<size[0]; i++){
      bd[i] = (int*)malloc(sizeof(int)*size[1]);
    } 
    for(i = 0; i<size[0]; i++){
      for (j = 0; j<size[1]; j++){
        bd[i][j] = 0;
      }
    }


    //!ter atenção para caso não haver uma 3 coluna
    //!o prof não tinha um mostrador de labirinto?
    //!ter atenção caso o numb esteja errado
    //!verificar os valores do fscanf

    for(i = 0; i<2; i++){
      fscanf(fp, "%d" , &(var_coord[i]));
    }
    fscanf(fp, "%s", varia);
    if(!strcmp(varia, "A6")){
      for(i = 0; i<2; i++){
        fscanf(fp, "%d" , &(varia6[i]));
      }
    }
    fscanf(fp, "%d", &numb);
    for(i = 0; i<numb; i++){
      fscanf(fp, "%d", &a);
      fscanf(fp, "%d", &b);
      fscanf(fp, "%d", &(bd[a-1][b-1]));//!da fuck, ivalide read of size 8
    }

    //!depois vamos trocar isto para um ficheiro á parte, mas por enquanto fica aqui
    if (!strcmp(varia, "A1")){
      filePrint(Variant1(var_coord, varia, bd, size), filename);
    }else if (!strcmp(varia, "A2")){
      filePrint(Variant2_4(var_coord, varia, bd, size, 0), filename);
    }else if (!strcmp(varia, "A3")){
      filePrint(Variant3(var_coord,varia,bd,size), filename);
    }else if (!strcmp(varia, "A4")){
      filePrint(Variant2_4(var_coord,varia,bd,size,-1), filename);
    }else if (!strcmp(varia, "A5")){
      filePrint(Variant5(var_coord,varia,bd,size), filename);
    }else if (!strcmp(varia, "A6")){
      filePrint(Variant6(var_coord,bd,size,varia6), filename);
    }
  
    //print para teste
    for(i = 0; i<size[0]; i++){
      for (j = 0; j<size[1]; j++){
        printf("%d ", bd[i][j]);
      }
      printf("\n");
    }
    printf("\n");

    //free para não termos de usar reallocs
    for(i = 0; i<size[0]; i++){
      free(bd[i]);
    }
    free(bd);

  }while(fscanf(fp, "%d" , size)==1);//!ver se se escreve assim o do while
  fclose(fp);
  return bd;
}
int filePrint(int value, char filename[24]){
  FILE *fp;

  fp = fopen(filename, "a");
  fprintf(fp, "%d\n", value);
  fprintf(fp, "\n");
  fclose(fp);
  return 1;
}
