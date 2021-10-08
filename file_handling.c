#include "file_handling.h";

board* creatBoard(char filename[24]){
  FILE *fp;
  int size[2];
  fp = fopen(filename, "r");//fazer verificações
  fscanf(fp, "%d" , size);
  fscanf(fp, "%d" , &(size[1]));
  printf("%d%d\n", size[0], size[1]);
  fclose(fp);
  return NULL;
}
