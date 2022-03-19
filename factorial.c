#include <stdio.h>

int main()
{
     unsigned int factorial = 1;
     
     int n, i = 2;
     
     printf("positive number: ");
     
     scanf("%d", &n);

     while (i <= n)
     {
         factorial = factorial * i;
         i++;
     }
     printf("n! = %u", factorial);



}