#include "variants.h"

int Variant1(int *var_coord, char *varia, int **bd, int *size)
{
    if (var_coord[0] > size[0] || var_coord[1] > size[1] || var_coord[0] < 1 || var_coord[1] < 1)
    {
        return -2;
    }
    return bd[var_coord[0] - 1][var_coord[1] - 1];
}