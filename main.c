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

  opt = getopt(argc, argv,"s");
  if (opt != -1 && opt == 's')
  {
      FirstSubmission = 1;
      printf("fd\n");
  }

  if (argv[optind] != NULL){
    char *file_read = argv[optind];//why works?
    char *last4i = &file_read[strlen(file_read)-4];
    if(strncmp(last4i, ".in1", 4) == 0 && FirstSubmission == 1){
      creatBoard(file_read);
    }else{
      return EXIT_FAILURE;//ver se é preciso algum print
    }
  }
  return 0;
}