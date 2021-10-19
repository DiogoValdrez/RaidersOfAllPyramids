#include "file_handling.h"

FILE* getFile(FILE *fp, char* filename, char *extra){
  if((fp = fopen(filename, "r"))==NULL){
    exit(0);
  }
  extra = &filename[strlen(filename)-4];
  *extra = '\0';
  strcat(filename, ".sol1");
  return fp;
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

void freeB(int **bd, int *size){
  int i;
  for(i = 0; i<size[0]; i++){
      free(bd[i]);
  }
  free(bd);
  return;
}

//por no .h
void read(FILE *fp, char type, void* addr, int **bd, int *size, int free){
  if(type == 'd'){
    if(!fscanf(fp, "%d", (int*)addr)){
        fclose(fp);
        if(free){
          freeB(bd, size);
        }
        exit(0);       
    }
  }else if(type == 's'){
    if(!fscanf(fp, "%s",(char*)addr)){
      fclose(fp);
      if(free){
        freeB(bd, size);
      }
      exit(0);
    }
  }
}

