#include <stdio.h>
int rec(int n,int k);
int main()
{
int tmp = rec(5,3);
printf("result: %d", tmp);


}

int rec(int n,int k)
{
    if(n == 0 && k==0)
    {
        return 1;
    }
    if(k > n/2)
    {
        return 0;
    }
    if(k==0 && n>0)
    {
        n--;
        k++;
    }
    return (rec(n-2,k-1) + rec(n-1,k));
}