#include <stdio.h>
#define N 4
//declare functions
int is_strong (int mat[N][N], int row, int column);
int first_row(int mat[N][N], int row, int column);
int last_row(int mat[N][N], int row, int column);
int FL_column(int mat[N][N], int row, int column);

int main()
{
    int matrix[N][N];
    int x = 0;
    int y[N][N];
    for (int j = 0; j < N; j++)
    {
        for (int i = 0; i < N; i++)
          {
           scanf("%d", &x);
            matrix[i][j] = x;
          }
    }

for (int j = 0; j < N; j++)
{
    for(int i = 0; i < N; i++)
    {
        y[i][j] = is_strong (matrix, i, j);
      printf("%d", y[i][j]);
    }
    
}

}


int is_strong (int mat[N][N], int row, int column)
{
  if (row == 0) //deal with first row
     return first_row(mat, row, column);
  
  if (row == N - 1) //deal with last row
     return last_row(int mat, row, column);
  
  if (column == 0 || column == N - 1) //deal with first and last columns (without edges)
     return FL_column(mat, row, column);

else // if the element is surrounded ^.^
{
    if (mat[row][column] > mat[row][column + 1] && mat[row][column - 1] > mat[row + 1][column] && mat[row][column] > mat[row - 1][column])
        return 1;
return 0;
}

int last_row(int mat[N][N], int row, int column) //deal with last row
{
 if (column == 0)
    {
        if (mat[row][column] > mat[row][column + 1] && mat[row][column] >mat[row - 1][column])
            return 1;
    return 0;
    }
    else if (column == N - 1)
    {   
        if (mat[row][column] > mat[row][column - 1] && mat[row][column] >mat[row - 1][column])
            return 1;
    return 0;
    }
    else
    {
        if (mat[row][column] > mat[row][column + 1] && mat[row][column] > mat[row][column - 1] && mat[row][column] >mat[row - 1][column])
        return 1;
    return 0;
    }
}

int first_row(int mat[N][N], int row, int column)    //deal with first row
{
    if (column == 0)
    {
        if (mat[row][column] > mat[row][column + 1] && mat[row][column] > mat[row + 1][column])
            return 1;
    return 0;
    }
    else if (column == N - 1)
    {
       if (mat[row][column] > mat[row][column + 1] && mat[row][column] > mat[row + 1][column])
           return 1;
    return 0;
    }
    else
    {
        if (mat[row][column] > mat[row][column + 1] && mat[row][column] > mat[row][column - 1] && mat[row][column] > mat[row + 1][column])
            return 1;
    return 0;    
    }
}


int FL_column(int mat[N][N], int row, int column)
{
    if (column == 0)
{
    if (mat[row][column] > mat[row][column + 1] && mat[row][column] > mat[row + 1][column] && mat[row][column] > mat[row - 1][column])
        return 1;
return 0; 
}
if (column == N - 1)
{
    if (mat[row][column] > mat[row][column - 1] && mat[row][column] > mat[row][column - 1] && mat[row][column] > mat[row - 1][column])
        return 1;
return 0;
}
}


