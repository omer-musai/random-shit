#include <stdio.h>
#define GRADES 10

//declare functions
int maximum(int grade[GRADES]);
void histogram(int grade[GRADES],  int maxamount , int symbol);


int main()
{
    //declare variables
    int x = 0, maxamount = 0;
    int grade[GRADES] = {0};
    char symbol;
    
    //prompt the user for input
    printf("Please enter a character:\n");

    scanf("%c", &symbol);

    printf("Please enter grades:\n");

    //keep ask for input untill EOF
    while (scanf("%d", &x) != EOF)
    { 
        grade[x - 1]++;  
    }
    //get the max amount of the same grade
    maxamount = maximum(grade);
    
    //print the histogram
    printf("Histogram:\n");
    histogram(grade, maxamount , symbol);
    return 0;
}

//get the max amount of the same grade
int maximum(int grade[GRADES])
{
    int max = 0;

    for (int i = 0; i < GRADES; i++)
    {
        if (max < grade[i])
        {
            max = grade[i];
        }

    }
    return max;
}


void histogram(int grade[GRADES],  int maxamount , int symbol)
{
    for(int j = 0; j < maxamount; j++)
    {
        for(int i = 0; i < GRADES; i++)
        {
            if (grade[i] >= maxamount - j && i != GRADES - 1) 
            {
                printf("%c", symbol);
                printf(" ");
            }   
            else if (i != GRADES - 1)
            {
                printf("  "); 
            }  
            if (grade[i] >= maxamount - j && i == GRADES - 1)
            {
                printf("%c", symbol);
                printf(" \n");
            }
            else if (i == GRADES - 1)
            {
                printf(" \n");
            }  
        }
    }
    //print 1 to 10
    for (int i = 1; i < GRADES; i++)
    {
        printf("%d ", i);
    }
    //space doesnt follow the last digit
    printf("%d", GRADES);

}

