#include <stdio.h>

int rec(n,m);
int main()
{
    int result = rec(3,2);
    printf("the result is: %d", result);


}

int rec(n,m)
{
    
    if(m==0 && n ==0)
    {
        return 1;
    }
    else if(n ==0 && m !=0)
    {
        return 0;
    }
    return (rec(n-1,m-1) + rec(n-1,m));
}