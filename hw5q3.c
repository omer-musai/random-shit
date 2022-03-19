

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <assert.h>

//
//  hw5q3main.c
//
//
//  Created by Catherine Haddad on 04/01/2021.
//

#define FAILURE -1
#define SUCCESS 0

int memcpy_count;

void merge(int* A, int* L, int leftCount, int* R, int rightCount);
void memCopy(int* base, int* temp_array, int len);
int merge_sort(int ar[], int n);
void swap(int** from, int** to);
void internal_msort(int ar[], int n ,int* temp_array);

int merge_sort(int ar[], int n)
{
    
    int* temp_array;
    temp_array = (int*)malloc(sizeof(int) * n);

    if (temp_array == NULL)
    {
        printf("Dynamic Allocation Error in merge_sort");
        return FAILURE;
    }
    internal_msort(ar, n , temp_array);
    free(temp_array);
    return SUCCESS;
}


void merge(int* A, int* L, int leftCount, int* R, int rightCount)
{
    int i, j, k;
    i = 0; j = 0; k = 0;

    while (i < leftCount && j < rightCount)
    {
        if (L[i] < R[j]) A[k++] = L[i++];
        else A[k++] = R[j++];
    }
    while (i < leftCount) A[k++] = L[i++];
    while (j < rightCount) A[k++] = R[j++];
}


void memCopy(int* base, int* temp_array, int len)
{
    ++memcpy_count;

    memcpy(base, temp_array, (len * sizeof(int)));

}

void swap(int** from, int** to)
{
    int* tmp = *to;
    *to = *from;
    *from = tmp;
}

int main()
{

    int n = 0;
    /* if (scanf("%d", &n) != 1)
         return 1;
     int num = 0, i=0;
     int* numbers = (int*)malloc (n*sizeof(int));
     while (scanf("%d", &num) !=1)
     {
         numbers[i] = num;
         i++;
     }*/

    int numbers[32] = { 3,7,9,-1, 3,7,9,-1, 3,7,9,-1, 3,7,9,-1, 3,7,9,-1, 3,7,9,-1, 3,7,9,-1, 3,7,9,-1 };
    merge_sort(numbers, 32);
    for (int i = 0; i < 32; i++)
    {
        if (i > 0)
            printf(", ");
        printf("%d", numbers[i]);
    }
    printf("\n");

    assert(memcpy_count <= 1);

    return 0;
  
}

void internal_msort(int ar[],int n ,int* temp_array)
{
    int left = n/2;
    int right = n - left;
    if (n < 2)
    {
        return;
    }
    internal_msort(ar, left , temp_array);
    internal_msort(ar + left, right , temp_array);
    merge(ar, left, ar+left, right, temp_array);
    memCopy(ar, temp_array, n);
}