#include <stdio.h>
#define GRADES 10

//declare functions
int maximum(int grade[GRADES]);

int main()
{
    //declare variables
    int x = 0, scanvalue = 0, maxvalue=0;
    int grade[GRADES] = {0};
    char symbol;
    

    printf("Please enter a character:\n");

    scanf("%c", &symbol);

    printf("Please enter grades:\n");


    while (scanvalue != EOF)
    {
        scanvalue = scanf("%d", &x);
        grade[x - 1]++;

    }
    //the loop goes 1 more time so igotta fix that
    grade[x -1]--;
    maxvalue = maximum(grade);
    
    printf("Histogram:\n");

    for(int j = 0; j < maxvalue; j++)
    {
        for(int i = 0; i < GRADES; i++)
        {
                if (grade[i] >= maxvalue - j && i != GRADES - 1) 
                {
                    printf("%c", symbol);
                    printf(" ");
                }   
                else if (i != GRADES - 1)
                {
                    printf("  "); 
                }  
                if (grade[i] >= maxvalue - j && i == GRADES - 1)
                {
                    printf("%c", symbol);
                    printf("\n");
                }
                else if (i == GRADES - 1)
                {
                    printf("\n");
                }  
        }
    }
    //print 1 to 10
        for (int i = 1; i <= GRADES; i++)
        {
        printf("%d ", i);
        }
}


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






