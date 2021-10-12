#include "file_handling.h"
//por a estrutura num sitio e a leitura e escrita de ficherios noutro
int** createBoard(char filename[24], int *varia, char *varia2, int *size){
  int **bd;
  FILE *fp;
  int i;
  int j;
  int numb;
  int a;
  int b;
  int varia6[2];

  fp = fopen(filename, "r");//fazer verificações
  fscanf(fp, "%d" , size);//em vez de ler palavra a palavra, ler linha a linha, ou afinal não
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


    //ter atenção para caso não haver uma 3 coluna
    //por if variante
    //o prof não tinha um mostrador de labirinto?
    //ter atenção caso o numb esteja errado
    //verificar os valores do fscanf
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
    for(i = 0; i<size[0]; i++){
      for (j = 0; j<size[1]; j++){
        printf("%d ", bd[i][j]);
      }
      printf("\n");
    }

  }while(fscanf(fp, "%d" , size)==1);//ver se se escreve assim o do while
  //ter atenção, chamar aqui a função das variantes e dar free, antes de fazer a proxima tabela

  fclose(fp);
  return bd;
}
