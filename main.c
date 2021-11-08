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
  char *last3i;

  opt = getopt(argc, argv,"s");
  if (opt != -1 && opt == 's'){
      FirstSubmission = 1;
  }

  if (argv[optind] != NULL){
    file_read = argv[optind];
    last4i = &file_read[strlen(file_read)-4];
    last3i = &file_read[strlen(file_read)-3];
    if(strncmp(last4i, ".in1", 4) == 0 && FirstSubmission == 1){
      createBoard(file_read, 1);
    }else if(strncmp(last3i, ".in", 3) == 0 && FirstSubmission == 0){
      createBoard(file_read, 0);
    }else{
      exit(0);
    }
  }
  exit(0);
}


//!comentarios
//!refactoring
//! -O3
//!dar free da bd mais cedo
//! tentar poupar memoria e dar frees o mais cedo possivel
//! mudar nomes de variaveis para nomes decentes
//! por tudo nos .h
//! tirar prints