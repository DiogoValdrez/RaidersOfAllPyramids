#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <getopt.h>

#define LISTA_OPCOES "s"


int main(int argc, char *argv[])
{
    int opt;
    int FirstSubmission = 0; //Variable that holds info about -s option
    char file_read[24];
    int i = -1;

  opt = getopt(argc, argv,"s");
  if (opt != -1 && opt == 's')
  {
      FirstSubmission = 1;
      printf("fd");
  }

  if (argv[optind] != NULL)
  {
    strcpy(file_read, argv[optind]);
    //printf("%s", file_read);
  }
  
  char *last4i = &file_read[strlen(file_read)-3];
  if(strncmp(last4i, ".in", -3) != 0)
  {
    return EXIT_FAILURE;
  }

  
  
  return 0;
}