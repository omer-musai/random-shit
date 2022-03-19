//include files
#include <stdio.h>
#include <stdlib.h>
#include "hw3q1_print_functions.h"

#define N 11


//function declaration
void updateFunction(int *s, int *l, int counter[6], int player, int n, int state);

void undo(int *indexR, int *indexC,  char board[N][N], int plr, int counter[4], int n);

int main()
{
    //set 6 counters
    int counter[6] = {0};
    
    //variables declaration
    int n = 0, player_index = 1;
    char board[N][N];
    
    
    //prompt the user for board size
    print_welcome();

    print_enter_board_size();

    scanf("%d", &n);

    //arrays to save the index by order of the input (a for first index, b for second index)
    int *row_index = (int*) malloc(sizeof(int) * n * n);
    int *column_index= (int*) malloc(sizeof(int) * n * n);
    
    if (row_index == NULL || column_index == NULL)
    {
        printf("error\n");
        exit(-1);
    }
    //initialize the board
    for (int i = 0; i < n; i++)
    {

        for (int j = 0; j < n; j++)
        {
            board[i][j] = '_' ;
        }
    }

    for (int i = 0; i < (n * n); i++)
    {   
        printf("c1:%d c2:%d c3:%d c4:%d c5:%d c6:%d", counter[0],counter[1],counter[2],counter[3],counter[4],counter[5]);
        
            //if some player have full line
            if (counter[player_index % 2] == n - 1|| counter[(player_index % 2) + 2] == n || counter[(player_index % 2) + 4] == n) 
            {
               print_winner(player_index);
               //free mallocs and exit
               free(row_index);
               free(column_index);
               exit(0);
            }   
        
        //prompt the user for index (save row index in a and column index in b)
        print_player_turn(player_index);
        
        scanf("%d", row_index + i);
        
        //USE HERE UNDO FUNCTION //i is also the number of sucsess inputs (i track how many O and X there is)
        if (*(row_index+i) < 0 && ((-*(row_index+i)) % 2) == 1 && *(row_index+i) >= -i)
        {
        
        int f = *(row_index+i);
        undo(row_index+i, column_index+i-1, board, player_index, counter, n);
        
        i += f - 1;
        print_board(board, n);
        player_index = (player_index % 2) + 1;
        continue;
        }
        scanf("%d",column_index + i);
        
        if (board[*(row_index + i) -1][*(column_index + i) -1] == '_')
        {
            
            if (player_index == 1)
            {
                board[*(row_index + i) -1][*(column_index + i) - 1] = 'X';
            }
            if (player_index == 2)
            {
                board[*(row_index + i) -1][*(column_index + i) -1] = 'O';
            }
           
           
            print_board(board, n);
            
            //update counters
            
            updateFunction(row_index+i, column_index+i, counter ,player_index - 1, n, i);
            
            //switch players
            player_index = (player_index % 2) + 1;
        }
        else
        {
            print_error();
            *(row_index+i) = 0;
            *(column_index+i) = 0;
            i--;

        }
    }
    
    print_tie();
    exit(0);
}

void updateFunction(int *s, int *l, int counter[6], int player, int n, int state)
{      
        if (state >=2)
        {
            // check for full row (check both players simultaneously with two counters)
            if (*(s-2) == *s && *s != 0)
            {
                counter[player]++;
            }
            //check for full column
            if (*(l-2) == *l && *l != 0)
            {
                counter[player]++;
            }
        }
        //check for full main diagonal line (different counters)
        if(*s == *l && *s != 0)
        {
            counter[player+2]++;
        }
        //check for full secondary diagonal line (different counters)
        if((*s + *l) == n + 1 )
        {
           counter[player+4]++;
        }


}


void undo(int *indexR, int *indexC,  char board[N][N], int plr, int counter[4], int n)
{
    
    for(int i = 0; i < -*indexR; i++)
    {
        board[*(indexR - i - 1) -1][*(indexC - i) -1] = '_' ;

        
        if (*(indexR-2 - i) == *(indexR-i) && *(indexR-i) != 0)
        {
            counter[(plr * i) % 2]--;
        }
        //check for full column
        if (*(indexC-2-i) == *(indexC-i) && *(indexC-i) != 0)
        {
            counter[(plr + i) % 2]--;
        }
        
        //check for full main diagonal line (different counters)
        if(*(indexR -1 -i) == *(indexC-i) && *(indexR-i) != 0)
        {
            counter[((plr+i) % 2) + 2]--;
        }
        
        //secondary diagonal line
         if((*(indexR-1 - i) + *(indexC- i)) == n + 1 )
        {
           counter[((plr+i) % 2) +4]--;
        }
    }

    for (int j = 0; j < -*indexR; j++ )
    {
      *(indexR -1 -j) = 0;
      *(indexC-j) = 0;
    }
    *indexR = 0;
}