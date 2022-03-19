#include <stdio.h>
#include <stdbool.h>

bool aux(int a[], int n, int used[],int set_sum, int curr_sum, int set_size);
int main()
{
    int sum = 0;
    int n=9;
    int used[9] = {0};
    int a[] = {1,11,3,2,4,5,7,3,0};
    for (int i = 0; i < n; i++)
    {
        sum += a[i];
    }
    int set_sum = sum / 3;

    if(aux(a,n,used,set_sum,set_sum,3))
    {
        printf("success");
    }
    if(!aux(a,n,used,set_sum,set_sum,3)){
        printf("failure");
    }
}


bool aux(int a[], int n, int used[],int set_sum, int curr_sum, int set_size)
{
    if(n==0)
    {
        return true;
    }
    for (int i = 0; i < n; i++)
    {
        if(a[i] <= curr_sum && !used[i] && set_size != 1)
        {
            used[i] = 1;
            curr_sum -= a[i];
            set_size--;
            if(aux(a,n-1,used,set_sum,curr_sum,set_size))
            {
                return true;
            }
            used[i] = 0;
            curr_sum += a[i];
            set_size++;
        }
        if(a[i] == curr_sum && !used[i] && set_size == 1)
        {
            used[i] = 1;
            if(aux(a,n-1,used,set_sum,set_sum,3))
            {
                return true;
            }
            else{
                used[i] = 0;
                return false;
            }
        }
    }
 return false;
}