/*
*
* DO NOT ALTER
*
*/

#define _CRT_SECURE_NO_WARNINGS

#define I_KNOW 0
#define I_DONT_KNOW 1
#define UNASSIGNED -1

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool is_partition_possible(int arr[], int n);
bool is_partition_possible_aux(int arr[], int n, int partition[],  int triplet_sum, int current, int next_unassigned);
bool PossibleToAssign(int arr[], int n, int partition[],  int triplet, int triplet_sum);


void PrintIDontKnow()
{
	printf("%d\n", I_DONT_KNOW);
}

void PrintIKnow()
{
	printf("%d\n", I_KNOW);
}


int main()
{
	// If you don't know uncomment next line 
	// PrintIDontKnow();
	PrintIKnow();

	int arr1[] = { 1,11,3,2,4,5,7,3,0 };
	int n1 = 9;
	printf("%d\n", is_partition_possible(arr1, n1));
	int arr2[] = { 1,14,3,2,4,5,7,3,0 };
	int n2 = 9;
	printf("%d\n", is_partition_possible(arr2, n2));


	return 0;
}

/* *********************************************************************** */
//
//							make changes here
//
/* *********************************************************************** */

bool is_partition_possible(int arr[], int n)
{
    int total_sum = 0;
    int* partition = (int*)malloc(sizeof(int) * n);


    for (int i = 0; i < n; i++)
    {
        total_sum += arr[i];
        partition[i] = UNASSIGNED;
    }
    
    bool possible = is_partition_possible_aux(arr, n, partition, total_sum / (n / 3), 0, 0);

    free(partition);
    return possible;
}


bool is_partition_possible_aux(int arr[], int n, int partition[],  int triplet_sum, int current, int next_unassigned)
{

    if (current == n)
    {
        return next_unassigned == (n / 3);
    }

    for (int triplet = 0; triplet <= next_unassigned; triplet++)
    {
        partition[current] = triplet;
        if(PossibleToAssign(arr, n, partition, triplet, triplet_sum))
        {
            if (is_partition_possible_aux(arr,n,  partition,  triplet_sum,  current + 1,  next_unassigned + (triplet == next_unassigned)))
            {
                return true;
            }
        }
    }
    partition[current] = UNASSIGNED;
    return false;

}


bool PossibleToAssign(int arr[], int n, int partition[],  int triplet, int triplet_sum)
{
    int num_in_triplet = 0, sum_in_triplet =0;

        for (int i = 0; i < n; i++)
        {
            if(partition[i] == triplet)
            {
                num_in_triplet++;
                sum_in_triplet += arr[i];
            }
        }

        if(num_in_triplet > 3)
        {
            return false;
        }

        if(num_in_triplet == 3 && sum_in_triplet != triplet_sum)
        {
            return false;
        }

        return true;


}
