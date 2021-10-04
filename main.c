#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <getopt.h>

#define LISTA_OPCOES "s"


int main(int argc, char *argv[])
{
    int opt;
    int FirstSubmission = 0; //Variable that holds info about -s option

    while((opt = getopt(argc, argv, LISTA_OPCOES)) != -1)
	{
	  switch (opt)
      {
          case 's':
            FirstSubmission = 1;
          
      }
    }
    
    return 0;
}