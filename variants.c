#include "variants.h"

int Variant1(int *var_coord, int **bd, int *size){
    return bd[var_coord[0] - 1][var_coord[1] - 1];
}

int Variant2_4(int *var_coord, int **bd, int *size, int piece){
    //Caso o tabuleiro seja apenas uma linha
    if (size[0] == 1 && size[1] == 1){
        return 0;
    }
    if (size[0] == 1){
        if (var_coord[1] == 1 && bd[var_coord[0]-1][var_coord[1]] == piece)
        {
            return 1;
        }else if (var_coord[1] == size[1] && bd[var_coord[0]-1][var_coord[1]-2] == piece){
            return 1;
        }else if (bd[var_coord[0]-1][var_coord[1]-2] == piece || bd[var_coord[0]-1][var_coord[1]] == piece){
            return 1;
        }else{
            return 0;
        }
    }
    //Caso o tabuleiro seja apenas uma coluna
    if (size[1] == 1){
        if (var_coord[0] == 1 && bd[var_coord[0]][var_coord[1]-1] == piece){
            return 1;
        }else if (var_coord[0] == size[1] && bd[var_coord[0]-2][var_coord[1]-1] == piece){
            return 1;
        }else if(bd[var_coord[0]-2][var_coord[1]-1] == piece || bd[var_coord[0]][var_coord[1]-1] == piece){
            return 1;
        }else{
            return 0;
        }
    }
    
    //1ª e ultima linha
    if(var_coord[0] == 1){
        if (var_coord[1] == 1){
            if(bd[var_coord[0]][var_coord[1]-1] == piece || bd[var_coord[0]-1][var_coord[1]] == piece){
                return 1;
            }else{
                return 0;
            }

        }else if (var_coord[1] == size[1]){
            if(bd[var_coord[0]-1][var_coord[1]-2] == piece || bd[var_coord[0]][var_coord[1]-1] == piece){
                return 1;
            }else{
                return 0;
            }
        }else{
            if(bd[var_coord[0]-1][var_coord[1]-2] == piece || bd[var_coord[0]][var_coord[1]] == piece || bd[var_coord[0]-1][var_coord[1]-1] == piece){
                return 1;
            }else{
                return 0;
            }
        }
    }else if(var_coord[0] == size[0]){
        if (var_coord[1] == 1){
            if(bd[var_coord[0]-2][var_coord[1]-1] == piece || bd[var_coord[0]-1][var_coord[1]] == piece){
                return 1;
            }else{
                return 0;
            }
        }else if(var_coord[1] == size[1]){
            if(bd[var_coord[0]-1][var_coord[1]-2] == piece || bd[var_coord[0]-2][var_coord[1]-1] == piece){
                return 1;
            }else{
                return 0;
            }
        }else{
            if(bd[var_coord[0]-1][var_coord[1]-2] == piece || bd[var_coord[0]-2][var_coord[1]-1] == piece || bd[var_coord[0]-1][var_coord[1]] == piece){
                return 1;
            }else{
                return 0;
            }
        }
    }

//1ª e ultima coluna sem os cantos porque a excessão deles ja está imposta em cima
    if(var_coord[1] == 1)
    {
        if(bd[var_coord[0]-2][var_coord[1]-1] == piece || bd[var_coord[0]-1][var_coord[1]] == piece || bd[var_coord[0]][var_coord[1]-1] == piece){
            return 1;
        }else{
            return 0;
        }
    
    }else if(var_coord[1] == size[1])
    {
        if(bd[var_coord[0]-2][var_coord[1]-1] == piece || bd[var_coord[0]-1][var_coord[1]-2] == piece || bd[var_coord[0]][var_coord[1]-1] == piece){
            return 1;
        }else{
            return 0;
        }
    }

    //Células que não representam qualquer excessão
    if (bd[var_coord[0]-2][var_coord[1]-1] == piece || bd[var_coord[0]-1][var_coord[1]] == piece ||
        bd[var_coord[0]][var_coord[1]-1] == piece || bd[var_coord[0]-1][var_coord[1]-2] == piece){
        return 1;
    }else{
        return 0;
    }
}






int Variant3(int *var_coord, int **bd, int *size)
{
    if (size[0] == 1 && size[1] == 1){
        return 0;
    }
    if (size[0] == 1){
        if (var_coord[1] == 1 && bd[var_coord[0]-1][var_coord[1]] > 0){
            return 1;
        }else if (var_coord[1] == size[1] && bd[var_coord[0]-1][var_coord[1]-2] > 0){
            return 1;
        }else if (bd[var_coord[0]-1][var_coord[1]-2] > 0 || bd[var_coord[0]-1][var_coord[1]] > 0){
            return 1;
        }else{
            return 0;
        }
    }
    //Caso o tabuleiro seja apenas uma coluna
    if (size[1] == 1){
        if (var_coord[0] == 1 && bd[var_coord[0]][var_coord[1]-1] > 0){
            return 1;
        }else if (var_coord[0] == size[1] && bd[var_coord[0]-2][var_coord[1]-1] > 0){
            return 1;
        }else if (bd[var_coord[0]-2][var_coord[1]-1] > 0 || bd[var_coord[0]][var_coord[1]-1] >  0){
            return 1;
        }else{
            return 0;
        }
    }
    
    //1ª e ultima linha
    if(var_coord[0] == 1){
        if (var_coord[1] == 1){
            if(bd[var_coord[0]][var_coord[1]-1] > 0 || bd[var_coord[0]-1][var_coord[1]] > 0){
                return 1;
            }else{
                return 0;
            }

        }else if (var_coord[1] == size[1]){
            if(bd[var_coord[0]-1][var_coord[1]-2] > 0 || bd[var_coord[0]][var_coord[1]-1] > 0){
                return 1;
            }else{
                return 0;
            }
        }else{
            if(bd[var_coord[0]-1][var_coord[1]-2] > 0 || bd[var_coord[0]][var_coord[1]-1] > 0 || bd[var_coord[0]-1][var_coord[1]] > 0){
                return 1;
            }else{
                return 0;
            }
        }
    }else if(var_coord[0] == size[0]){
        if (var_coord[1] == 1){
            if(bd[var_coord[0]-2][var_coord[1]-1] > 0 || bd[var_coord[0]-1][var_coord[1]] > 0){
                return 1;
            }else{
                return 0;
            }
        }else if(var_coord[1] == size[1]){
            if(bd[var_coord[0]-1][var_coord[1]-2] > 0 || bd[var_coord[0]-2][var_coord[1]-1] > 0){
                return 1;
            }else{
                return 0;
            }
        }else{
            if(bd[var_coord[0]-1][var_coord[1]-2] > 0 || bd[var_coord[0]-2][var_coord[1]-1] > 0 || bd[var_coord[0]-1][var_coord[1]] > 0){
                return 1;
            }else{
                return 0;
            }
        }
    }

//1ª e ultima coluna sem os cantos porque a excessão deles ja está imposta em cima
    if(var_coord[1] == 1)
    {
        if(bd[var_coord[0]-2][var_coord[1]-1] > 0 || bd[var_coord[0]-1][var_coord[1]] > 0 || bd[var_coord[0]][var_coord[1]-1] > 0){
            return 1;
        }else{
            return 0;
        }
    
    }else if(var_coord[1] == size[1])
    {
        if(bd[var_coord[0]-2][var_coord[1]-1] > 0 || bd[var_coord[0]-1][var_coord[1]-2] > 0 || bd[var_coord[0]][var_coord[1]-1] > 0){
            return 1;
        }else{
            return 0;
        }
    }

    //Células que não representam qualquer excessão
    if (bd[var_coord[0]-2][var_coord[1]-1] > 0 || bd[var_coord[0]-1][var_coord[1]] > 0 ||
        bd[var_coord[0]][var_coord[1]-1] > 0 || bd[var_coord[0]-1][var_coord[1]-2] > 0){
        return 1;
    }else{
        return 0;
    }
}


int Variant5(int *var_coord, int **bd, int *size){
    if (bd[var_coord[0]-1][var_coord[1]-1] < 1){
        return -1;
    }
    if ((var_coord[0] == 1 && var_coord[1] == 1) || (var_coord[0] == 1 && var_coord[1] == size[1]) ||
        (var_coord[0] == size[0] && var_coord[1] == 1) || (var_coord[0] == size[0] && var_coord[1] == size[1])){
        return 0;
    }

    if (var_coord[0] == 1 || var_coord[0] == size[0]){
        if (bd[var_coord[0]-1][var_coord[1]-2] == 0 && bd[var_coord[0]-1][var_coord[1]] == 0){
            return 1;
        }else{
            return 0;
        }
    }else if (var_coord[1] == 1 || var_coord[1] == size[1]){
        if (bd[var_coord[0]-2][var_coord[1]-1] == 0 && bd[var_coord[0]][var_coord[1]-1] == 0){
            return 1;
        }else{
            return 0;
        }
    }else{
        if ((bd[var_coord[0]-1][var_coord[1]-2] == 0 && bd[var_coord[0]-1][var_coord[1]] == 0)||
            (bd[var_coord[0]-2][var_coord[1]-1] == 0 && bd[var_coord[0]][var_coord[1]-1] == 0)){
            return 1;
        }else{
            return 0;
        }
    }
}

int search(int x, int y, int **bd, int *size, int *obj){
    if(x==obj[0]-1 && y==obj[1]-1){
        return 1;
    }else if(bd[x][y]!=0){//parede ou visitada
        return 0;
    }
    //nova procura

    bd[x][y] = -2;

    //ver se a comparação de x com size esta certa
    if((x<size[0]-1 && search(x+1,y,bd,size,obj))||
       (x>0 && search(x-1,y,bd,size,obj))||
       (y<size[1]-1 && search(x,y+1,bd,size,obj))||
       (y>0 && search(x,y-1,bd,size,obj))){
           return 1;
       }
    return 0;
}

int Variant6(int *var_coord, int **bd, int *size, int *obj){
    if(bd[var_coord[0]-1][var_coord[1]-1] != 0 || bd[obj[0]-1][obj[1]-1] != 0){
        return 0;
    }
    return search(var_coord[0]-1,var_coord[1]-1,bd,size,obj);
}
