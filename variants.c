#include "variants.h"

int Variant1(int *var_coord, char *varia, int **bd, int *size)
{
    if (var_coord[0] > size[0] || var_coord[1] > size[1] || var_coord[0] < 1 || var_coord[1] < 1)
    {
        return -2;
    }
    return bd[var_coord[0] - 1][var_coord[1] - 1];
}

int Variant2_4(int *var_coord, char *varia, int **bd, int *size, int piece)
{
    if (var_coord[0] > size[0] || var_coord[1] > size[1] || var_coord[0] < 1 || var_coord[1] < 1)
    {
        return -2;
    }
    //1ª e ultima linha
    if(var_coord[0] == 1)
    {
        if (var_coord[1] == 1)
        {
            if(bd[var_coord[0]][var_coord[1]-1] == piece || bd[var_coord[0]-1][var_coord[1]] == piece)
            {
                return 1;
            }else{
                return 0;
            }

        }else if (var_coord[1] == size[1])
        {
            if(bd[var_coord[0]-1][var_coord[1]-2] == piece || bd[var_coord[0]][var_coord[1]-1] == piece)
            {
                return 1;
            }else{
                return 0;
            }
        }else
        {
            if(bd[var_coord[0]-1][var_coord[1]-2] == piece || bd[var_coord[0]][var_coord[1]] == piece || bd[var_coord[0]-1][var_coord[1]] == piece)
            {
                return 1;
            }else{
                return 0;
            }
        }
    }else if(var_coord[0] == size[0])
    {
        if (var_coord[1] == 1)
        {
            if(bd[var_coord[0]-2][var_coord[1]-1] == piece || bd[var_coord[0]-1][var_coord[1]] == piece)
            {
                return 1;
            }else{
                return 0;
            }
        }else if(var_coord[1] == size[1])
        {
            if(bd[var_coord[0]-1][var_coord[1]-2] == piece || bd[var_coord[0]-2][var_coord[1]-1] == piece)
            {
                return 1;
            }else{
                return 0;
            }
        }else{
            if(bd[var_coord[0]-1][var_coord[1]-2] == piece || bd[var_coord[0]-2][var_coord[1]-1] == piece || bd[var_coord[0]-1][var_coord[1]] == piece)
            {
                return 1;
            }else{
                return 0;
            }
        }
    }

//1ª e ultima coluna sem os cantos porque a excessão deles ja está imposta em cima
    if(var_coord[1] == 1)
    {
        if(bd[var_coord[0]-2][var_coord[1]-1] == piece || bd[var_coord[0]-1][var_coord[1]] == piece || bd[var_coord[0]][var_coord[1]-1] == piece)
        {
            return 1;
        }else{
            return 0;
        }
    
    }else if(var_coord[1] == size[1])
    {
        if(bd[var_coord[0]-2][var_coord[1]-1] == piece || bd[var_coord[0]-1][var_coord[1]-2] == piece || bd[var_coord[0]][var_coord[1]-1] == piece)
        {
            return 1;
        }else{
            return 0;
        }
    }

    //Células que não representam qualquer excessão
    if (bd[var_coord[0]-2][var_coord[1]-1] == piece || bd[var_coord[0]-1][var_coord[1]] == piece ||
        bd[var_coord[0]][var_coord[1]-1] == piece || bd[var_coord[0]-1][var_coord[1]-2] == piece)
    {
        return 1;
    }else{
        return 0;
    }
}






int Variant3(int *var_coord, char *varia, int **bd, int *size)
{
    if (var_coord[0] > size[0] || var_coord[1] > size[1] || var_coord[0] < 1 || var_coord[1] < 1)
    {
        return -2;
    }
    //1ª e ultima linha
    if(var_coord[0] == 1)
    {
        if (var_coord[1] == 1)
        {
            if(bd[var_coord[0]][var_coord[1]-1] > 0 || bd[var_coord[0]-1][var_coord[1]] > 0)
            {
                return 1;
            }else{
                return 0;
            }

        }else if (var_coord[1] == size[1])
        {
            if(bd[var_coord[0]-1][var_coord[1]-2] > 0 || bd[var_coord[0]][var_coord[1]-1] > 0)
            {
                return 1;
            }else{
                return 0;
            }
        }else
        {
            if(bd[var_coord[0]-1][var_coord[1]-2] > 0 || bd[var_coord[0]][var_coord[1]] > 0 || bd[var_coord[0]-1][var_coord[1]] > 0)
            {
                return 1;
            }else{
                return 0;
            }
        }
    }else if(var_coord[0] == size[0])
    {
        if (var_coord[1] == 1)
        {
            if(bd[var_coord[0]-2][var_coord[1]-1] > 0 || bd[var_coord[0]-1][var_coord[1]] > 0)
            {
                return 1;
            }else{
                return 0;
            }
        }else if(var_coord[1] == size[1])
        {
            if(bd[var_coord[0]-1][var_coord[1]-2] > 0 || bd[var_coord[0]-2][var_coord[1]-1] > 0)
            {
                return 1;
            }else{
                return 0;
            }
        }else{
            if(bd[var_coord[0]-1][var_coord[1]-2] > 0 || bd[var_coord[0]-2][var_coord[1]-1] > 0 || bd[var_coord[0]-1][var_coord[1]] > 0)
            {
                return 1;
            }else{
                return 0;
            }
        }
    }

//1ª e ultima coluna sem os cantos porque a excessão deles ja está imposta em cima
    if(var_coord[1] == 1)
    {
        if(bd[var_coord[0]-2][var_coord[1]-1] > 0 || bd[var_coord[0]-1][var_coord[1]] > 0 || bd[var_coord[0]][var_coord[1]-1] > 0)
        {
            return 1;
        }else{
            return 0;
        }
    
    }else if(var_coord[1] == size[1])
    {
        if(bd[var_coord[0]-2][var_coord[1]-1] > 0 || bd[var_coord[0]-1][var_coord[1]-2] > 0 || bd[var_coord[0]][var_coord[1]-1] > 0)
        {
            return 1;
        }else{
            return 0;
        }
    }

    //Células que não representam qualquer excessão
    if (bd[var_coord[0]-2][var_coord[1]-1] > 0 || bd[var_coord[0]-1][var_coord[1]] > 0 ||
        bd[var_coord[0]][var_coord[1]-1] > 0 || bd[var_coord[0]-1][var_coord[1]-2] > 0)
    {
        return 1;
    }else{
        return 0;
    }
}


int Variant5(int *var_coord, char *varia, int **bd, int *size)
{
    if (var_coord[0] > size[0] || var_coord[1] > size[1] || var_coord[0] < 1 || var_coord[1] < 1)
    {
        return -2;
    }
    if (bd[var_coord[0]-1][var_coord[1]-1] < 1)
    {
        return -1;
    }
    if ((var_coord[0] == 1 && var_coord[1] == 1) || (var_coord[0] == 1 && var_coord[1] == size[1]) ||
        (var_coord[0] == size[0] && var_coord[1] == 1) || (var_coord[0] == size[0] && var_coord[1] == size[1]))
    {
        return 0;
    }

    if (var_coord[0] == 1 || var_coord[0] == size[0])
    {
        if (bd[var_coord[0]-1][var_coord[1]-2] == 0 && bd[var_coord[0]-1][var_coord[1]] == 0)
        {
            return 1;
        }else{
            return 0;
        }
    }else if (var_coord[1] == 1 || var_coord[1] == size[0])
    {
        if (bd[var_coord[0]-2][var_coord[1]-1] == 0 && bd[var_coord[0]][var_coord[1]-1] == 0)
        {
            return 1;
        }else{
            return 0;
        }
    }else
    {
        if ((bd[var_coord[0]-1][var_coord[1]-2] == 0 && bd[var_coord[0]-1][var_coord[1]] == 0)||
            (bd[var_coord[0]-2][var_coord[1]-1] == 0 && bd[var_coord[0]][var_coord[1]-1] == 0))
        {
            return 1;
        }else{
            return 0;
        }
    }
}