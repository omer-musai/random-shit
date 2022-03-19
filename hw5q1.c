/*-------------------------------------------------------------------------
  Include files:
--------------------------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

/*=========================================================================
  Constants and definitions:
==========================================================================*/


#define LEX 1
#define LET_DIVER 2
#define MAX_LEN 21
#define a 'a'
#define A 'A'
#define Z 'Z'
#define z 'z'


//functions declaration
int compareStr(const char *str1, const char *str2, int rule);

void sortString(const char *str_arr[], int n, int rule);

int diversity(char *LCstr);

void swapstrings(const char *str_arr[], int loc);

bool bubble(const char *str_arr[], int n, int rule);

char* lowercase(const char *str);

// Print Functions' Declarations
void printNumStringsInputMessage();

void printStringsInputMessage(int n);

void printRuleOfComparisonInputMessage();

void printSortedStrings(const char *str_arr[], int n);

void printAllocationError();

/*-------------------------------------------------------------------------
  The main program. (describe what your program does here)
 -------------------------------------------------------------------------*/
int main() 
{
    int n = 0, rule = 0;
    
    //prompt the user for num of strings
    printNumStringsInputMessage();
    scanf("%d", &n);

    const char **str_arr =  (const char**)malloc(n * sizeof(char*));
    if( str_arr == NULL)
    {
        printAllocationError();
        return 0;
    }
    
    printStringsInputMessage(n); 
    
    //get strings from the user
    for (int i=0; i <n; i++)
    {
        char* str = (char*)calloc(MAX_LEN, sizeof(char));
        if(str == NULL)
        {
            printAllocationError();
            return 0;
        }
        scanf("%s", str);

        str_arr[i] = str;
    }
    
    //prompt the user for a rule
    printRuleOfComparisonInputMessage(); 
    scanf("%d", &rule);

    //sort the strings by the order of the rule and print sorted list
    sortString(str_arr, n, rule);
    printSortedStrings(str_arr, n); 
    
    //free allocated memory
    for(int j=0; j <n; j++)
    {
        free((char*)str_arr[j]);
    }
    free(str_arr);
    return 0;
}

//compare the strings
int compareStr(const char *str1, const char *str2, int rule) 
{
   char* LCword1 = NULL;
   char* LCword2 = NULL;
   LCword1 =lowercase(str1);
   LCword2 = lowercase(str2);
    
    if (rule == LEX)
    {
        for (int i=0; i < MAX_LEN; i++ )
        {
           
           if (LCword1[i] > LCword2[i])
           {
               free(LCword1); free(LCword2);
               return 1;
           } 
            if (LCword1[i] < LCword2[i])
           {
               free(LCword1); free(LCword2);
               return -1;
           }      
        }
        free(LCword1); free(LCword2);
        return 0;
    }
    
    if (rule == LET_DIVER)
    {  
        int div1 = diversity(LCword1);
        int div2 = diversity(LCword2);
       
        if (div1 > div2 )
        {
            free(LCword1); free(LCword2);
            return 1;
        }
        if (div1 < div2)
        {
            free(LCword1); free(LCword2);
            return -1;
        }
    free(LCword1); free(LCword2);
    return 0;
    }
    free(LCword1); free(LCword2);
    return 0;
}

//sort the strings using bubble sort algorithm
void sortString(const char *str_arr[], int n, int rule) 
{
     bool not_sorted = true;
    while(n > 1 && not_sorted)
    {
        not_sorted = bubble(str_arr, n--, rule);
    }
}

// Print Functions
void printNumStringsInputMessage() {
    printf("Please enter the number of strings:\n");
}

void printStringsInputMessage(int n) {
    printf("Please enter the %d strings:\n", n);
}

void printRuleOfComparisonInputMessage() {
    printf("Please enter the rule of comparison between strings.\n");
    printf("%d: Lexicographic order.\n", LEX);
    printf("%d: By the diversity of letters.\n", LET_DIVER);
}

void printSortedStrings(const char *str_arr[], int n) {
    printf("The sorted strings are:\n");
    for (int i = 0; i < n; i++) {
        printf("%s\n", str_arr[i]);
    }
}

void printAllocationError() {
    printf("ERROR: allocation failed.\n");
}

//calculate the diversity of letters in a string
int diversity(char *LCstr)
{
    int len = strlen(LCstr);
  
    int div=0;
    bool x = true;
    for (int j=0; j < len; j++)
    {
        if (LCstr[j] >= a && LCstr[j] <= z)
        {
            for(int i=1; i < len -j; i++)
            {
                if(LCstr[j] == LCstr[j +i])
                {
                    x = false;
                } 
            }
            if(x)
            {
                div++;
            }
            x = true;
        }
    }
    return div;
}

void swapstrings(const char *str_arr[], int loc )
{
   const char* tmp = str_arr[loc];
   str_arr[loc] = str_arr[loc-1];
   str_arr[loc-1] = tmp;
}

bool bubble(const char *str_arr[], int n, int rule)
{
    bool swapped = false;
    
    for (int i=1; i < n; i++)
    {
        
        if(compareStr(str_arr[i-1], str_arr[i], rule) > 0)
        {
            
            swapstrings(str_arr, i);
            
            swapped = true;
        }
    }
    return swapped;

}

//change all uppercase letters to lowercase
char* lowercase(const char *str)
{
    int counter =0;
    char* LCword = (char*)calloc(MAX_LEN, sizeof(char));
    if(LCword == NULL)
    {
        printAllocationError();
    }
     while(str[counter])
    {
        if (str[counter] >= A && str[counter] <= Z)
        {
          LCword[counter] = (str[counter] + (a - A)); 
          
        }
        else
        {
             LCword[counter] = str[counter];  
        }
     counter++;
    }
    return LCword;

}