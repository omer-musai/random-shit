#include <stdio.h>
#include <stdbool.h>
#define N 4

//declare functions
int is_strong (int mat[N][N], int row, int column);
int space_rank (int mat[N][N], int row, int column);

int main()
{
    //declare variables
    int matrix[N][N];
    int strongE = 0;
    int spaceR = 0;  

    //prompt the user for input and save it in array
    printf("Please enter a matrix:\n");
    
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
          {
           scanf("%d", &matrix[i][j]);
          }
    }
    //iterate through each element and check if strong and his space rank
    for (int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            strongE += is_strong (matrix, i, j);
            spaceR  += space_rank (matrix, i, j);
        }
    }
    //print the number of strong elements and the total of space ranks
    printf("Strong elements: %d\nSpace rank: %d", strongE, spaceR);
}



int space_rank (int mat[N][N], int row, int column)
{
    int sr = 0;
    int AVsr = 0;
    
    //calculate space rank
    sr = ((column < N - 1) ? mat[row][column] - mat[row][column + 1] : 0);
    
    //absolute value by definition
    AVsr = ((sr > 0) ? sr : -sr);
    
    //return the absolute value of space rank
    return AVsr;
}



int is_strong (int mat[N][N], int row, int column)
{
    //declare variables
    bool a = 0, b = 0, c = 0, d = 0;
    
    //check if the element is strong
    a = ((row > 0) ? (mat[row][column] > mat[row - 1][column]) : 1);
    b = ((row < N - 1) ? (mat[row][column] > mat[row + 1][column]) : 1);
    c = ((column > 0) ? (mat[row][column] > mat[row][column - 1]) : 1);
    d = ((column < N - 1) ? (mat[row][column] > mat[row][column + 1]) : 1);
    
    //return 1 if strong and 0 if not
    return ((a + b + c + d) / 4);
}


