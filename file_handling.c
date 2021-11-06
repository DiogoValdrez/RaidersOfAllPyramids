#include "file_handling.h"

/*
 *  Function:
 *    getFile
 *
 *  Description:
 *    Opens a file and creates the name for the output file;
 *
 *  Arguments:
 *    Pointer to a file;
 *    Pointer to an array that contains the name of the file;
 *    Pointer to a helper array;
 *
 *  Return value:
 *    Pointer to the file;
 *          
 */
FILE* getFile(FILE *fp, char* filename, char *extra, int type){
  if((fp = fopen(filename, "r"))==NULL){
    exit(0);
  }
  if(type){
    extra = &filename[strlen(filename)-4];
    *extra = '\0';
    strcat(filename, ".sol1");
  }else{
    extra = &filename[strlen(filename)-3];
    *extra = '\0';
    strcat(filename, ".sol");
  }
  
  return fp;
}
/*
 *  Function:
 *    filePrint
 *
 *  Description:
 *    Writes the output file;
 *
 *  Arguments:
 *    Int that holds the value that we want to write on the output file
 *    Pointer to an array that contains the name of the file;
 *
 *  Return value:
 *    Void;
 *          
 */

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

/*
 *  Function:
 *    freeB
 *
 *  Description:
 *    Free of the board
 *
 *  Arguments:
 *    Double pointer to the board;
 *    Pointer to an array that contains the size of the board;
 *
 *  Return value:
 *    Void;
 *          
 */
void freeB(int **bd, int *size){
  int i;
  for(i = 0; i<size[0]; i++){
      free(bd[i]);
  }
  free(bd);
  return;
}

/*
 *  Function:
 *    read
 *
 *  Description:
 *    Reads the input file;
 *
 *  Arguments:
 *    Pointer to the file;
 *    Char that holds the type of value that we wnat to output;
 *    Pointer to void;
 *    Double pointer to the board;
 *    Pointer to an anrray that contains the size of the board;
 *    Int that holds the information of if we have already allocated the board;
 *
 *  Return value:
 *    Void;
 *  
 *  Other Information:
 *    The pointer to void will have the target variable that later will be recasted to the respected type;
 *          
 */
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

