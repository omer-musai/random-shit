/*-------------------------------------------------------------------------
  Include files:
--------------------------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*=========================================================================
  Constants and definitions:
==========================================================================*/
bool partitions(int* vals, int n, int sum, int k, int* counter);
// Print Functions' Declarations
void printNumCoinsInputMessage();

void printCoinValsInputMessage();

void printSumInputMessage();

void printLimitInputMessage();

void printAnswerMessage(int n);

void printAllocationError();

/*-------------------------------------------------------------------------
  The main program. (describe what your program does here)
 -------------------------------------------------------------------------*/
int main() 
{
    //variables declaration
    int k=0,sum=0, n=0;
    int counter[1];
    counter[0] = 0;
    

printNumCoinsInputMessage();
scanf("%d", &n);
    
int* coins = (int*)calloc(n, sizeof(int));
if (coins == NULL)
{
    printAllocationError(); 
    return 0;
}

printCoinValsInputMessage();
for (int i = 0; i < n; i++)
{
scanf("%d", &coins[i]);
}


printSumInputMessage();
scanf("%d", &sum);

printLimitInputMessage(); 
scanf("%d", &k);

//calculate all possible partitions
partitions( coins ,n,  sum,k, counter);


printAnswerMessage(counter[0]); 
    
    free(coins);
    return 0;
}

void printNumCoinsInputMessage() {
    printf("Please enter coins num:\n");
}

void printCoinValsInputMessage() {
    printf("Please enter coins vals:\n");
}

void printSumInputMessage() {
    printf("Please enter the requested sum:\n");
}

void printLimitInputMessage() {
    printf("Please enter the coins limit:\n");
}

void printAnswerMessage(int n) {
    printf("There are %d possible partitions.\n", n);
}

void printAllocationError() {
    printf("ERROR: allocation failed.\n");
}

//calculating all possible partitions and save result in a counter
bool partitions(int* vals, int n, int sum, int k, int* counter)
{
    if (sum==0)
    {
        counter[0]++;
        return false;
    }
    if(n <= 0)
    {
        return false;
    }
    if(k <= 0)
    {
        return false;
    }
    if (vals[0] <= sum && partitions(vals, n, sum - vals[0], k -1, counter))
    {
        return true;
    }
    return partitions(vals+1, n-1, sum, k, counter);
    
}