//include files
#include <stdio.h>
#include <stdlib.h>
#include "hw3q1_print_functions.h"

#define N 11


//function declaration
void updateFunction(int *s, int counter[6], int player, int n);

void undo(int *d, char board[N][N], int plr, int counter[4], int n);

int main()
{
    //set 6 counters
    int counter[6] = {0};
    
    //variables declaration
    int value = 0, n = 0, player_index = 1;
    char board[N][N];
    
    //prompt the user for board size
    print_welcome();

    print_enter_board_size();
    
    scanf("%d", &n);

    //arrays to save the index by order of the input (a for first index, b for second index)
    int *row = (int*) malloc(sizeof(int) * n * n * 2);
    
    //initialize the board
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            board[i][j] = '_' ;
        }
    }

    for (int i = 0; i < n * n; i++)
    {   
            //if some player have full line
            if (counter[player_index % 2] == n - 1 || counter[(player_index % 2) + 2] == n || counter[(player_index % 2) + 4] == n) 
            {
               print_winner(player_index);
               //free mallocs and exit
               free(row);
               
               free(counter);
               exit(0);
            }   
        
        //prompt the user for index (save row index in a and column index in b)
        print_player_turn(player_index);
        
        
        
          scanf("%d",row + i);
           
            if (*(row+i) < 0 && -(*(row+i) % 2) == 1)
            {
                int f = *(row+i);
                undo(row+i, board, player_index, counter, n);
                
                i += f;
                print_board(board, n);
                player_index = (player_index % 2) + 1;
                continue;
           }
           scanf("%d",row + i +1);
        
        if (board[*(row + i) -1][*(row + 1 + i) -1] == '_')
        {
            if (player_index == 1)
            {
                board[*(row + i) -1][*(row + 1 + i) - 1] = 'X';
            }
            if (player_index == 2)
            {
                board[*(row + i) -1][*(row + 1 + i) -1] = 'O';
            }
           
           
            print_board(board, n);
            
            //update counters
            updateFunction(row+i, counter ,player_index - 1, n);
            
            //switch players
            player_index = (player_index % 2) + 1;
        }
        else
        {
            print_error();
            *(row+i) = 0;
            *(row+i+1)= 0;
            i--;
        }
    }
    
    print_tie();
    exit(0);
}

void updateFunction(int *s,int counter[6], int player, int n)
{      
    
        // check for full row (check both players simultaneously with two counters)
        if (*(s-4) == *s && *s != 0)
        {
            counter[player]++;
        }
        //check for full column
        if (*(s-3) == *(s+1) && *(s+1) != 0)
        {
            counter[player]++;
        }
        
        //check for full main diagonal line (different counters)
        if(*s == *(s+1) && *s != 0)
        {
            counter[player+2]++;
        }
        //check for full secondary diagonal line (different counters)
        if((*s + *(s+1)) == n + 1 )
        {
           counter[player+4]++;
        }


}



void undo(int *d, char board[N][N], int plr, int counter[4], int n)
{
    
    for(int i = 0; i < -*d; i++)
    {
        board[*(d - (2*i) - 2) -1][*(d - (2*i) -1) -1] = '_' ;

        
        if (*(d-4 - i) == *(d-i) && *(d-i) != 0)
        {
            counter[plr]--;
        }
        //check for full column
        if (*(d-3-i) == *(d+1-i) && *(d+1-i) != 0)
        {
            counter[(plr + i) % 2]--;
        }
        
        //check for full main diagonal line (different counters)
        if(*(d-i) == *(d+1-i) && *(d-i) != 0)
        {
            counter[((plr+i) % 2) + 2]--;
        }
        
        //secondary diagonal line
         if((*d + *(d+1)) == n + 1 )
        {
           counter[((plr+i) % 2) +4]--;
        }
    }

    for (int j = 1; j < -2 * (*d); j++ )
    {
      *(d-j) = 0;
      
    }
}