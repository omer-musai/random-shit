#include <stdio.h>
 
int main()
{
    int arr[] = {1,1,5,5,1,1,5,1,1};
    int n = 9;
    int left = 0, right = n-1;
    while(left <= right)
    {
        int mid = (right+left)/2;
        if(arr[mid] != arr[mid-1] && arr[mid] != arr[mid+1])
        {
            printf("%d", mid);
            return 0;
        }
        else if(arr[mid] == arr[mid-1])
        {
            if(mid%2 == 0)
            {
                right = mid -1;
            }
            else{
                left = mid + 1;
            }
        }
        else
        {
            if(mid%2 == 0)
            {
                left = mid + 1;
            }
            else{
                right = mid -1;
            }
        }

    }
}