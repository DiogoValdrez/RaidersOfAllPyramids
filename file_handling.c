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
  int varia[2];//variavel para coordenadas da variane
  char varia2[2];//variavel com a variante
  int size[2];

  fp = fopen(filename, "r");//!fazer verificações
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
      fscanf(fp, "%d" , &(varia[i]));
    }
    fscanf(fp, "%s", varia2);
    if(!strcmp(varia2, "A6")){
      for(i = 0; i<2; i++){
        fscanf(fp, "%d" , &(varia6[i]));
      }
    }
    fscanf(fp, "%d", &numb);
    for(i = 0; i<numb; i++){
      fscanf(fp, "%d", &a);
      fscanf(fp, "%d", &b);
      fscanf(fp, "%d", &(bd[a-1][b-1]));
    }

    //print para teste
    

    for(i = 0; i<size[0]; i++){
      for (j = 0; j<size[1]; j++){
        printf("%d ", bd[i][j]);
      }
      printf("\n");
    }
    printf("\n");

    //!depois vamos trocar isto para um ficheiro á parte, mas por enquanto fica aqui
    if (!strcmp(varia2, "A1")){
      printf("\n%d\n\n", Variant1(varia, varia2, bd, size));
    }
    if (!strcmp(varia2, "A2")){
      //printf("\n%d\n\n", Variant2_4(varia, varia2, bd, size, 0));
    }
    if (!strcmp(varia2, "A3")){
      printf("\n%d\n\n", Variant3(varia,varia2,bd,size));
    }
    if (!strcmp(varia2, "A4")){
      printf("\n%d\n\n", Variant2_4(varia,varia2,bd,size,-1));
    }
  

    //free para não termos de usar reallocs
    for(i = 0; i<size[0]; i++){
      free(bd[i]);
    }
    free(bd);

  }while(fscanf(fp, "%d" , size)==1);//!ver se se escreve assim o do while
  fclose(fp);
  return bd;
}
