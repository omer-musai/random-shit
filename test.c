#include <stdio.h>
#define N 4
//declare functions
int is_strong (int mat[N][N], int row, int column);

int main()
{
    
    int matrix[N][N];
    int d = 0;
    int x = 0;
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
        d = is_strong(matrix, i, j);
      printf("%d", d);
    }
    
}


}


int is_strong (int mat[N][N], int row, int column)
{
  if (row == 0) //deal with first row   
  {
      if (column == 0)
    {
        if (mat[row][column] > mat[row][column + 1] && mat[row][column] > mat[row + 1][column])
           { 
               return 1;
           }
    return 0;
    }
    if (column == N - 1)
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
    
  
  if (row == N - 1) //deal with last row
 {
     if (column == 0)
    {
        if (mat[row][column] > mat[row][column + 1] && mat[row][column] >mat[row - 1][column])
          return 1;
    return 0;
   }  
     if (column == N - 1)
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



else // if the element is surrounded ^.^
{
    if (mat[row][column] > mat[row][column + 1] && mat[row][column - 1] > mat[row + 1][column] && mat[row][column] > mat[row - 1][column])
        return 1;
return 0;
}

}

