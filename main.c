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
//!tentar tirar includes a mais
//!ver ultima aula oude o prof explica como dividir os ficheiros
//!segmentation fault quando daas ficheuiro que nao existe ou parecido, ver isto
//!verificar se não temos argumentos a mais , returns não usados(fscanf, funções, etc)
//!fazer verificações em cada scanff, malloc, chamada de funções, etc


//!verificar se não nos dão coordenadas nojentas ou assim pq o prof vai abusar de certeza

//!Cena do pocinho de tabela demasiado grande

//!ver plagio
//!comentar
//!retornos de todas as funções

//!ler enunciado bem!!
//!filename só tem 24 maximo de tamanho why???

//!refacoring
//!2 linhas brancas no fim??

