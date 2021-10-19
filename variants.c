#include "variants.h"

/*
 *  Function:
 *    Variant1
 *
 *  Description:
 *    Variant A1 - identify the type of cell
 *
 *  Arguments:
 *    Pointer to an array that holds the coordenates to check;
 *    Double pointer to a table that holds the board;
 *    Pointer to an array that olds the size of the board;
 *
 *  Return value:
 *    Int - answer to the variant A1:
 *       0 if the cell is white;
 *       -1 if the cell is black;
 *       natural number, if the cell is grey, which holds the value of the cell;
 *  
 *  Other information:
 *    if the cell is out of bounds the value of the variant answer is -2, but that check is made before the function is called;
 *          
 */

int Variant1(int *var_coord, int **bd, int *size){
    return bd[var_coord[0] - 1][var_coord[1] - 1];
}

/*
 *  Function:
 *    Variant2_4
 *
 *  Description:
 *    Variant A2 - identify if any neighbour is white
 *    Variant A4 - identify if any neighbour is black
 *
 *  Arguments:
 *    Pointer to an array that holds the coordenates to check;
 *    Double pointer to a table that holds the board;
 *    Pointer to an array that olds the size of the board;
 *    int which is going to be 0 or -1 if want to check for varriant A2 or A4, accordingly;
 *
 *  Return value:
 *    Int - answer to the variant A2 or A4:
 *       0 if it is a negative answer;
 *       1 if it is a positive answer;
 *  
 *  Other information:
 *    if the cell is out of bounds the value of the variant answer is -2, but that check is made before the function is called;
 *          
 */

int Variant2_4(int *var_coord, int **bd, int *size, int piece){
    //In case the board is of the type Yx1 or 1xY, only one line or only one collumn
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
    
    //Case of the cell being on thhe First or the Last line including corners
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

    //Case of the cell being on the First or Last collum without corner, because they are already covered
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

    //Cells that dont consitute any exception
    if (bd[var_coord[0]-2][var_coord[1]-1] == piece || bd[var_coord[0]-1][var_coord[1]] == piece ||
        bd[var_coord[0]][var_coord[1]-1] == piece || bd[var_coord[0]-1][var_coord[1]-2] == piece){
        return 1;
    }else{
        return 0;
    }
}



/*
 *  Function:
 *    Variant3
 *
 *  Description:
 *    Variant A3 - identify if any neighbour is grey
 *
 *  Arguments:
 *    Pointer to an array that holds the coordenates to check;
 *    Double pointer to a table that holds the board;
 *    Pointer to an array that olds the size of the board;
 *
 *  Return value:
 *    Int - answer to the variant A3:
 *       0 if it is a negative answer;
 *       1 if it is a positive answer;
 *  
 *  Other information:
 *    if the cell is out of bounds the value of the variant answer is -2, but that check is made before the function is called;
 *          
 */


int Variant3(int *var_coord, int **bd, int *size)
{
    //In case the board is of the type Yx1 or 1xY, only one line or only one collumn
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
    
    //Case of the cell being on thhe First or the Last line including corners
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

    //Case of the cell being on the First or Last collum without corner, because they are already covered
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

    //Cells that dont consitute any exception
    if (bd[var_coord[0]-2][var_coord[1]-1] > 0 || bd[var_coord[0]-1][var_coord[1]] > 0 ||
        bd[var_coord[0]][var_coord[1]-1] > 0 || bd[var_coord[0]-1][var_coord[1]-2] > 0){
        return 1;
    }else{
        return 0;
    }
}

/*
 *  Function:
 *    Variant5
 *
 *  Description:
 *    Variant A5 - identify if the cell is grey, and in that case if it is breakable
 *
 *  Arguments:
 *    Pointer to an array that holds the coordenates to check;
 *    Double pointer to a table that holds the board;
 *    Pointer to an array that olds the size of the board;
 *
 *  Return value:
 *    Int - answer to the variant A2 or A4:
 *       0 if it is a negative answer;
 *       1 if it is a positive answer;
 *       -1 if the cell is not grey;
 *  
 *  Other information:
 *    if the cell is out of bounds the return value is -2, but that check is made before the function is called;
 *          
 */

int Variant5(int *var_coord, int **bd, int *size){
    //Check if the cell is grey
    if (bd[var_coord[0]-1][var_coord[1]-1] < 1){
        return -1;
    }
    //Case of corners, they are not breakable
    if ((var_coord[0] == 1 && var_coord[1] == 1) || (var_coord[0] == 1 && var_coord[1] == size[1]) ||
        (var_coord[0] == size[0] && var_coord[1] == 1) || (var_coord[0] == size[0] && var_coord[1] == size[1])){
        return 0;
    }
    //Case of the cell being on thhe First or the Last line
    if (var_coord[0] == 1 || var_coord[0] == size[0]){
        if (bd[var_coord[0]-1][var_coord[1]-2] == 0 && bd[var_coord[0]-1][var_coord[1]] == 0){
            return 1;
        }else{
            return 0;
        }
    }else if (var_coord[1] == 1 || var_coord[1] == size[1]){//Case of the cell being on thhe First or the Last collum
        if (bd[var_coord[0]-2][var_coord[1]-1] == 0 && bd[var_coord[0]][var_coord[1]-1] == 0){
            return 1;
        }else{
            return 0;
        }
    }else{//Cells that dont constitute an exception
        if ((bd[var_coord[0]-1][var_coord[1]-2] == 0 && bd[var_coord[0]-1][var_coord[1]] == 0)||
            (bd[var_coord[0]-2][var_coord[1]-1] == 0 && bd[var_coord[0]][var_coord[1]-1] == 0)){
            return 1;
        }else{
            return 0;
        }
    }
}

/*
 *  Function:
 *    search
 *
 *  Description:
 *    Recursive function to find if two cells are in the same room
 *
 *  Arguments:
 *    Int for the x coordenate of a cell;
 *    Int for the y coordenate of a cell
 *    Double pointer to a table that holds the board;
 *    Pointer to an array that olds the size of the board;
 *    Pointer to an array that holds the coordenates of the second cell;
 *
 *  Return value:
 *    Int:
 *       0 if it is a wall or an already visited cell;
 *       1 if it is the cell we want to check;
 *  
 *  Other information:
 *    if the cell is out of bounds value of the variant answer is -2, but that check is made before the function is called;
 *    if one of the cells isnt white the value of the variant answer is -2, but that check is made before the function is called;
 *          
 */
int search(int x, int y, int **bd, int *size, int *obj){
    if(x==obj[0]-1 && y==obj[1]-1){
        return 1;
    }else if(bd[x][y]!=0){//Wall or already visited cell
        return 0;
    }
    //new search

    bd[x][y] = -2;

    if((x<size[0]-1 && search(x+1,y,bd,size,obj))||
       (x>0 && search(x-1,y,bd,size,obj))||
       (y<size[1]-1 && search(x,y+1,bd,size,obj))||
       (y>0 && search(x,y-1,bd,size,obj))){
           return 1;
       }
    return 0;
}

/*
 *  Function:
 *    Variant6
 *
 *  Description:
 *    Variant A6 - if both cells are white, identify if they belong to the same room
 *
 *  Arguments:
 *    Pointer to an array that holds the coordenates of the first cell;
 *    Double pointer to a table that holds the board;
 *    Pointer to an array that olds the size of the board;
 *    Pointer to an array that holds the coordenates of the second cell;
 *    
 *
 *  Return value:
 *    Int - answer to the variant A6:
 *       0 if it is a negative answer;
 *       1 if it is a positive answer;
 *  
 *  Other information:
 *    if the cell is out of bounds value of the variant answer is -2, but that check is made before the function is called;
 *    if one of the cells isnt white the value of the variant answer is -2, but that check is made before the function is called;
 *          
 */

int Variant6(int *var_coord, int **bd, int *size, int *obj){
    if(bd[var_coord[0]-1][var_coord[1]-1] != 0 || bd[obj[0]-1][obj[1]-1] != 0){
        return 0;
    }
    return search(var_coord[0]-1,var_coord[1]-1,bd,size,obj);
}
