//include files
#include <stdio.h>
#include <stdlib.h>

//Constants and definitions
#define N 11
#define P_1_SYMBOL 'X'
#define P_2_SYMBOL 'O'
#define EMPTY '_'
#define NUM_OF_PLR 2

//print functions declaration
void print_welcome();
void print_enter_board_size();
void print_board(char board[N][N], int n);
void print_player_turn(int player_index);
void print_error();
void print_winner(int player_index);
void print_tie();
//other functions declaration
int check_row_column(char board[N][N], int *r, int *col, int n);
int check_diagonal_lines(char board[N][N], int n);
void check_for_winner(char board[N][N], int *R_index, int  *C_index, int n, int* counter, int* player_index);
void undo(char board[N][N], int *Ri, int* Ci, int* counter, int n, int* player_index);
void update(char board[N][N], int player_index, int* Ri, int* Ci, int counter);
int opening(char board[N][N]);
int input_checker1(int counter,int* Ri);
int input_checker2(int counter, char board[N][N], int* Ri, int* Ci, int n);

//16 lines
int main()
{
  //variables and arrays declaration
  int counter = 0, Ri[N*N], Ci[N*N], player_index = 1;
  char board[N][N];
    
  //welcome, get board size and intialize the board
  int n = opening(board);

  while (counter < n*n)
  {   
      //get row index
      scanf("%d", &Ri[counter]);
      
      //check if legal undo
      if (input_checker1(counter, Ri))
      {
          continue;
      }
        
      //check if input is minus odd number.
      if (Ri[counter] < 0 )
      {
          //go back |input| number of steps
          undo(board, Ri + counter, Ci + counter - 1, &counter, n, &player_index);
          continue;
      }
         
      //get column index
      scanf("%d", &Ci[counter]);
       
      //check if legal input
      if (input_checker2(counter, board, Ri, Ci, n))
      {
          continue;
      }
        
      //update the game
      update(board, player_index, Ri, Ci, counter);
      check_for_winner(board, Ri + counter, Ci + counter, n, &counter, &player_index);  
  }
  //if the board is full and no1 won
  print_tie();
}

 //check if row\colum is full of 'x' or full of 'o'
 //9 lines
 int check_row_column(char board[N][N], int *r, int *col, int n)
 {
     int cnt1 = 0, cnt2 = 0;
     
     for (int i = 0; i < n - 1; i++)
     {
        if (board[i][*col - 1] == board[i+1][*col - 1] && board[i][*col - 1] != EMPTY)
        {
          cnt2++;
        }
        if (board[*r - 1][i] == board[*r - 1][i+1] && board[*r - 1][i] != EMPTY)
        {
            cnt1++;
        }
     }
     if (cnt1 == n - 1 || cnt2 == n - 1)
     {
       return 1;
     } 
   return 0;
 }
 
 //check if either one of the diagonal lines is full of 'x' or full of 'o'
 //9 lines
 int check_diagonal_lines(char board[N][N], int n)
 {
   int cnt1 = 0, cnt2 = 0;
   for (int i = 0; i < n - 1; i++)
   {
       if (board[i][i] == board[i + 1][i + 1] && board[i][i] != EMPTY)
       {
         cnt1++;
       }
        if (board[n-i-1][i] == board[n-i-1-1][i+1] && board[n-i-1][i] != EMPTY)
       {
           cnt2++;
       }
   }
   if (cnt1 == n - 1 || cnt2 == n - 1)
     {
       return 1;
     }
   return 0;
 }

//if there is a winner, print winner and quit. else print board and update the game.
//9 lines
void check_for_winner(char board[N][N], int *R_index, int  *C_index, int n, int* counter, int* player_index)
{
   
   if (check_row_column(board, R_index, C_index, n)|| check_diagonal_lines(board, n))
   {
       print_board(board, n);
       print_winner((*player_index % NUM_OF_PLR) + 1);
       exit(0);
   }
    //switch player, update counter and print board
   *player_index = (*player_index % NUM_OF_PLR) + 1;
   print_board(board, n);
   *counter = *counter + 1;
   
   if (*counter < n*n)
   {
     print_player_turn(*player_index);
   }
}

//take back the game odd number of steps
//10 lines
void undo(char board[N][N], int *Row, int* Column, int* counter, int n, int* player_index)
{

   *counter = *counter + *Row;
  int stepback = -*Row;
  *Row = 0;

  for (int i = 0; i < stepback; i++)
  {
    board[*(Row - i -1) - 1][*(Column - i) - 1] = EMPTY ;
    *(Row - i - 1) = 0;
    *(Column - i) = 0;
  }
  *player_index = (*player_index % NUM_OF_PLR) + 1;
  print_board(board, n);
  print_player_turn(*player_index);
}

//update the board
//4 lines
void update(char board[N][N], int player_index, int* Ri, int* Ci, int counter)
{
  if (player_index == 1)
  {
    board[Ri[counter] - 1][Ci[counter] -1] = P_1_SYMBOL;
  }
  if (player_index == NUM_OF_PLR)
  {
    board[Ri[counter] - 1][Ci[counter] -1] = P_2_SYMBOL;
  }              
}

//print welcome and prompt the user for board size, return board size.
//10 lines
int opening(char board[N][N])
{
    int n=0, k=1;
    
    //prompt the user for board size
    print_welcome();
    print_enter_board_size();
    
    scanf("%d", &n);

    //initialize the board
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            board[i][j] = EMPTY ;
        }
    }
    
    //print board
    print_board(board, n);
    print_player_turn(k);
    
    return n;
}

//check row index input
//5 lines
int input_checker1(int counter, int* Ri)
{
  if (Ri[counter] < -counter || ((-Ri[counter] % NUM_OF_PLR) == 0 && Ri[counter] < 0))
  {
      print_error();
      *(Ri + counter) = 0;
      return 1;
  }
  return 0;
}

//check row index and column index input
//6 lines
int input_checker2(int counter, char board[N][N], int* Ri, int* Ci, int n)
{
  if (Ri[counter] > n || Ri[counter] < 0 || Ci[counter] > n || Ci[counter] < 1 ||board[Ri[counter] - 1][Ci[counter] -1] != EMPTY)
  {
      print_error();
      *(Ri + counter) = 0;
      *(Ci + counter) = 0;
      return 1;
  } 
  return 0;
}

//print welcome message
//1 lines
void print_welcome()
{
    printf("*** Welcome to AVOIDANCE TIC-TAC-TOE game ***\n\n");
}

//print message to enter board size
//1 lines
void print_enter_board_size()
{
    printf("Please enter board size (1 to %d):\n", N);
}

//print the board
//7 lines
void print_board(char board[N][N], int n)
{
    printf("\nCurrent board:\n");
    for (int i = 0; i < n; i++)
    {
        printf("|");
        for (int j = 0; j < n; j++)
        {
            printf("%c|", board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

//print a request for player with index "player_index" to move
//1 lines
void print_player_turn(int player_index)
{
    printf("\nPlayer ** %d **, enter next move:\n", player_index);
}

//print error message
//1 lines
void print_error()
{
    printf("Illegal move!!!, please try again:\n");
}

//print the winner
//1 lines
void print_winner(int player_index)
{
    printf("Player %d Wins! Hooray!\n", player_index);
}

//print message to announce there is a tie (no one wins)
//1 lines
void print_tie()
{
    printf("It's a tie!\n");
}

