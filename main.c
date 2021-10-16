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
  char *file_read;
  char *last4i;

  opt = getopt(argc, argv,"s");
  if (opt != -1 && opt == 's')
  {
      FirstSubmission = 1;
  }

  if (argv[optind] != NULL){
    file_read = argv[optind];
    last4i = &file_read[strlen(file_read)-4];
    if(strncmp(last4i, ".in1", 4) == 0 && FirstSubmission == 1){
    createBoard(file_read);
    }else{
      exit(0);//!ver se é preciso algum print
    }
  }
  exit(0);
}

//!falta refatorizar
//!tentar tirar includes a mais

//!verificar se não temos argumentos a mais , returns não usados(fscanf, funções, etc)
//!Cena de tabela demasiado grande

//!ver indice de plagio
//!comentar

//!ler enunciado bem!!

//!refacoring
//!2 linhas brancas no fim??

