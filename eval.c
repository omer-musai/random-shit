#include <math.h>
#include <stdio.h>
#include <stdlib.h>


double stdDiv(int n);
double evaluateOfPi(int n);
double randfrom(double min, double max);



int main()
{
    int n = 0;
    printf("Enter number of picks: \n");
   
    scanf("%d", &n);
   
    double sigma = stdDiv(n);
    double pi = evaluateOfPi(n); 
    printf("sigma: %lf\n", sigma);
    printf("pi: %lf", pi);
}


double stdDiv(int n)
{
    return 2 * sqrt(M_PI * ((4 - M_PI) / n));
}

double evaluateOfPi(int n)
{
    int counter =0;
    double x = 0 ,y = 0;

    for (int i=0; i < n; i++)
    {
        x = randfrom(-1, 1);
        y = randfrom(-1, 1);

        if((x*x + y*y) <= 1)
        {
            counter++;
        }
    }
    
    return (double)counter / (n/4);
}

double randfrom(double min, double max) 
{
    double range = (max - min); 
    double div = RAND_MAX / range;
    return min + (rand() / div);
}