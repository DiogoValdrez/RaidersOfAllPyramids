#ifndef VARIANTS_HPP
#define VARIANTS_HPP
#include <stdio.h>
#include <stdlib.h>

int Variant1(int *var_coord, char *varia, int **bd, int *size);
int Variant2_4(int *var_coord, char *varia, int **bd, int *size, int piece);
int Variant3(int *var_coord, char *varia, int **bd, int *size);
int Variant5(int *var_coord, char *varia, int **bd, int *size);
int Variant6(int *var_coord, int **bd, int *size, int *obj);
int search(int x, int y, int **bd, int *size, int *obj);

#endif