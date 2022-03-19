#include <stdio.h>
#include <math.h>

int main()
{
int result = rec(4,3,3);
printf("result: %d", result);

}

int rec(n,k,m)
{
    if(n==1)
    {
        return 2;
    }
   
    if(k == 1)
    {
       return rec(n-2,m ,m);
    }
    if(n < k)
    {
        int tmp = 1;
        for (int i = 0; i < n; i++)
        {
            tmp *= 2;
        }
        return tmp;
    }
    return rec(n-1,k-1,m) + rec(n-1,m,m);
}