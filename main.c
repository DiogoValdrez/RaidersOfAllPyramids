#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <getopt.h>
#include "file_handling.h"

#define LISTA_OPCOES "s"

int main(int argc, char *argv[])
{
  int opt;
  int FirstSubmission = 0; //Variable that holds info about -s option
  int **bd;

  opt = getopt(argc, argv,"s");
  if (opt != -1 && opt == 's')
  {
      FirstSubmission = 1;
  }

  if (argv[optind] != NULL){
    char *file_read = argv[optind];//!why works? alocar dinamicamente
    char *last4i = &file_read[strlen(file_read)-4];
    if(strncmp(last4i, ".in1", 4) == 0 && FirstSubmission == 1){
      bd = createBoard(file_read);
    }else{
      return EXIT_FAILURE;//!ver se é preciso algum print
    }
  }
  return 0;
}

//!falta refatorizar
//!main-createboard-decidirVar-varPrint-(continua o loop, por isso pode ser preciso free)-end
//!tentar tirar includes a mais
//!ver ultima aula oude o prof explica como dividir os ficheiros

//!refacoring
//!printing output to file
