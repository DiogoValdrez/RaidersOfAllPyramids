#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <getopt.h>
#include "board.h"

#define LISTA_OPCOES "s"

/*
 * Autores: Diogo Valdrez 99914
 *          Pedro Raposo 100059
 *
 * Descrição:  Projeto Raiders of all Pyramids
 *          
 */

int main(int argc, char *argv[])
{
  int opt;
  int FirstSubmission = 0; //Variable that holds info about -s option
  char *file_read;
  char *last4i;

  opt = getopt(argc, argv,"s");
  if (opt != -1 && opt == 's'){
      FirstSubmission = 1;
  }

  if (argv[optind] != NULL){
    file_read = argv[optind];
    last4i = &file_read[strlen(file_read)-4];
    if(strncmp(last4i, ".in1", 4) == 0 && FirstSubmission == 1){
    createBoard(file_read);
    }else if(strncmp(last4i, ".in", 3) == 0 && FirstSubmission == 0){
    //createBoard(file_read);
    }else{
      exit(0);
    }
  }
  exit(0);
}


