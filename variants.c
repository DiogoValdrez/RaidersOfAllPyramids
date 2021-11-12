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
 *    createQueue;
 *    queue_Empty;
 *    createNode;
 *    addNodetoList;
 *    takeNodefromList
 *
 *  Description:
 *    queue related functions;
 *          
 */
queue* createQueue()
{
    queue* q;
    if((q = (queue*)malloc(sizeof(queue))) == NULL)
    {
        exit(0);
    }
    q->head = NULL;
    q->last = -1;
    return q;
}

int queue_Empty(queue* q)
{
    if (q->last == -1)
    {
        return 1;
    }else{
        return 0;
    }
}
node* createNode(int i, int j)
{
    node *no;
    if((no = (node*)malloc(sizeof(node))) == NULL)
    {
        exit(0);
    }
    no->size[0] = i;
    no->size[1] = j;
    no->next_node = NULL;
    return no;
}

void addNodetoList(queue* q, int i, int j)
{
    node *no = createNode(i, j);
    no->next_node = q->head;
    q->head = no;
    q->last++;
}

node* takeNodefromList(queue* q)
{
    node *no = q->head;
    q->head = no->next_node;
    q->last--;
    return no;
}

/*
 *  Function:
 *    add_mark_adjacents
 *
 *  Description:
 *    adds the adjacent of the given node to a queue and marks with the respective flag
 *  Arguments:
 *    int **bd of the board;
 *    node *no;
 *    queue *q;
 *    int *size coordenates of the node;
 *    int flag with which is supposed to substitute the values of the room
 *
 *  Return value:
 *    void;
 *          
 */
void add_mark_adjacents(int **bd, node *no, queue *q, int *size, int flag)
{
    //Matrix 1xY
    if (size[0] == 1)
    {
        if (no->size[1] == (size[1]-1))
        {
            if (bd[no->size[0]][no->size[1]-1] == 0 )
            {
                addNodetoList(q, no->size[0],no->size[1]-1);
                bd[no->size[0]][no->size[1]-1] = flag;
            }
        }else if(no->size[1] == 0){
            if (bd[no->size[0]][no->size[1]+1] == 0 )
            {
                addNodetoList(q, no->size[0],no->size[1]+1);
                bd[no->size[0]][no->size[1]+1] = flag;
            }
        }else{
            if (bd[no->size[0]][no->size[1]-1] == 0 )
            {
                addNodetoList(q, no->size[0],no->size[1]-1);
                bd[no->size[0]][no->size[1]-1] = flag;
            }
            if (bd[no->size[0]][no->size[1]+1] == 0 )
            {
                addNodetoList(q, no->size[0],no->size[1]+1);
                bd[no->size[0]][no->size[1]+1] = flag;
            }
        }
        return;
    }
    //Matrix Yx1
    if (size[1] == 1)
    {
        if (no->size[0] == (size[0]-1))
        {
            if (bd[no->size[0]-1][no->size[1]] == 0 )
            {
                addNodetoList(q, no->size[0]-1,no->size[1]);
                bd[no->size[0]-1][no->size[1]] = flag;
            }
        }else if(no->size[0] == 0){
            if (bd[no->size[0]+1][no->size[1]] == 0 )
            {
                addNodetoList(q, no->size[0]+1,no->size[1]);
                bd[no->size[0]+1][no->size[1]] = flag;
            }
        }else{
            if (bd[no->size[0]-1][no->size[1]] == 0 )
            {
                addNodetoList(q, no->size[0]-1,no->size[1]);
                bd[no->size[0]-1][no->size[1]] = flag;
            }
            if (bd[no->size[0]+1][no->size[1]] == 0 )
            {
                addNodetoList(q, no->size[0]+1,no->size[1]);
                bd[no->size[0]+1][no->size[1]] = flag;
            }
        }
        return;
    }
    //i&j==0
    if((no->size[0]) == 0 && (no->size[1]) == 0)
    {
        if (bd[no->size[0]+1][no->size[1]] == 0 )
        {
            addNodetoList(q, no->size[0]+1,no->size[1]);
            bd[no->size[0]+1][no->size[1]] = flag;
        }
        if (bd[no->size[0]][no->size[1]+1] == 0 )
        {
            addNodetoList(q, no->size[0],no->size[1]+1);
            bd[no->size[0]][no->size[1]+1] = flag;
        }
        return;
    }
    //i&j == max
    if((no->size[0]) == (size[0] -1) && (no->size[1]) == (size[1]-1))
    {
        if (bd[no->size[0]-1][no->size[1]] == 0 )
        {
            addNodetoList(q, no->size[0]-1,no->size[1]);
            bd[no->size[0]-1][no->size[1]] = flag;
        }
        if (bd[no->size[0]][no->size[1]-1] == 0 )
        {
            addNodetoList(q, no->size[0],no->size[1]-1);
            bd[no->size[0]][no->size[1]-1] = flag;
        }
        return;
    }
    //i = 0;j == max
    if((no->size[0]) == 0 && (no->size[1]) == (size[1]-1))
    {
        if (bd[no->size[0]][no->size[1]-1] == 0 )
        {
            addNodetoList(q, no->size[0],no->size[1]-1);
            bd[no->size[0]][no->size[1]-1] = flag;
        }
        if (bd[no->size[0]+1][no->size[1]] == 0 )
        {
            addNodetoList(q, no->size[0]+1,no->size[1]);
            bd[no->size[0]+1][no->size[1]] = flag;
        }
        return;
    }
    //i = max;j == 0
    if((no->size[0]) == (size[0]-1) && (no->size[1]) == 0)
    {
        if (bd[no->size[0]-1][no->size[1]] == 0 )
        {
            addNodetoList(q, no->size[0]-1,no->size[1]);
            bd[no->size[0]-1][no->size[1]] = flag;
        }
        if (bd[no->size[0]][no->size[1]+1] == 0 )
        {
            addNodetoList(q, no->size[0],no->size[1]+1);
            bd[no->size[0]][no->size[1]+1] = flag;
        }
        return;
    }
    //i=0
    if(no->size[0] == 0)
    {
        if (bd[no->size[0]+1][no->size[1]] == 0 )
        {
            addNodetoList(q, no->size[0]+1,no->size[1]);
            bd[no->size[0]+1][no->size[1]] = flag;
        }
        if (bd[no->size[0]][no->size[1]+1] == 0 )
        {
            addNodetoList(q, no->size[0],no->size[1]+1);
            bd[no->size[0]][no->size[1]+1] = flag;
        }
        if (bd[no->size[0]][no->size[1]-1] == 0 )
        {
            addNodetoList(q, no->size[0],no->size[1]-1);
            bd[no->size[0]][no->size[1]-1] = flag;
        }
        return;
    }
    //j=0
    if(no->size[1] == 0)
    {
        if (bd[no->size[0]+1][no->size[1]] == 0 )
        {
            addNodetoList(q, no->size[0]+1,no->size[1]);
            bd[no->size[0]+1][no->size[1]] = flag;
        }
        if (bd[no->size[0]][no->size[1]+1] == 0 )
        {
            addNodetoList(q, no->size[0],no->size[1]+1);
            bd[no->size[0]][no->size[1]+1] = flag;
        }
        if (bd[no->size[0]-1][no->size[1]] == 0 )
        {
            addNodetoList(q, no->size[0]-1,no->size[1]);
            bd[no->size[0]-1][no->size[1]] = flag;
        }
        return;
    }
    //i = max
    if(no->size[0] == size[0]-1)
    {
        if (bd[no->size[0]-1][no->size[1]] == 0 )
        {
            addNodetoList(q, no->size[0]-1,no->size[1]);
            bd[no->size[0]-1][no->size[1]] = flag;
        }
        if (bd[no->size[0]][no->size[1]-1] == 0 )
        {
            addNodetoList(q, no->size[0],no->size[1]-1);
            bd[no->size[0]][no->size[1]-1] = flag;
        }
        if (bd[no->size[0]][no->size[1]+1] == 0 )
        {
            addNodetoList(q, no->size[0],no->size[1]+1);
            bd[no->size[0]][no->size[1]+1] = flag;
        }
        return;
    }
    //j=max
    if(no->size[1] == size[1]-1)
    {
        if (bd[no->size[0]-1][no->size[1]] == 0 )
        {
            addNodetoList(q, no->size[0]-1,no->size[1]);
            bd[no->size[0]-1][no->size[1]] = flag;
        }
        if (bd[no->size[0]][no->size[1]-1] == 0 )
        {
            addNodetoList(q, no->size[0],no->size[1]-1);
            bd[no->size[0]][no->size[1]-1] = flag;
        }
        if (bd[no->size[0]+1][no->size[1]] == 0 )
        {
            addNodetoList(q, no->size[0]+1,no->size[1]);
            bd[no->size[0]+1][no->size[1]] = flag;
        }
        return;
    }
    //else
    if (bd[no->size[0]-1][no->size[1]] == 0 )
    {
        addNodetoList(q, no->size[0]-1,no->size[1]);
        bd[no->size[0]-1][no->size[1]] = flag;
    }
    if (bd[no->size[0]][no->size[1]-1] == 0 )
    {
        addNodetoList(q, no->size[0],no->size[1]-1);
        bd[no->size[0]][no->size[1]-1] = flag;
    }
    if (bd[no->size[0]+1][no->size[1]] == 0 )
    {
        addNodetoList(q, no->size[0]+1,no->size[1]);
        bd[no->size[0]+1][no->size[1]] = flag;
    }
    if (bd[no->size[0]][no->size[1]+1] == 0 )
    {
        addNodetoList(q, no->size[0],no->size[1]+1);
        bd[no->size[0]][no->size[1]+1] = flag;
    }
    return;
}

/*
 *  Function:
 *    Variant6
 *
 *  Description:
 *    Implements variant6 with BFS
 *  Arguments:
 *    int *var_coord coordenates given;
 *    int **bd board;
 *    int *size size of board;
 *    int *obj coordenates of objective;
 *    int flag to cheange rooms;
 *    int type;
 *
 *  Return value:
 *    int answer to variant6;
 *    0 if it is a negative answer;
 *    1 if it is a positive answer;
 *          
 */
int Variant6(int *var_coord, int **bd, int *size, int *obj, int flag, int type){
    if((bd[var_coord[0]-1][var_coord[1]-1] != 0) || ((bd[obj[0]-1][obj[1]-1] != 0) && type == 1)){
        return 0;
    }
    queue *q = createQueue();
    addNodetoList(q, var_coord[0]-1,var_coord[1]-1);
    bd[var_coord[0]-1][var_coord[1]-1] = flag;
    node *currentVertex;

    while(queue_Empty(q) == 0)
    {
        currentVertex = takeNodefromList(q);
        add_mark_adjacents(bd, currentVertex, q, size, flag);
        free(currentVertex);
    }
    free(q);
    if (bd[var_coord[0]-1][var_coord[1]-1] == bd[obj[0]-1][obj[1]-1])
    {
        return 1;
    }else{
        return 0;
    }

}
