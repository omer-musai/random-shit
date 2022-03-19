#include <stdio.h>


//declare functions
int seq_length(int seq);
int digit_value (int sequence , int locator);
int poweroften (int k);
int main()
{
    //declare variables ()
    int S=0, K=0, counter=0, mirrorDigit=0, digit=0, y=0 ,x=0;
    
    printf("Please enter a length:\n");
    scanf("%d",&K);

    printf("Please enter a sequence:\n");
    scanf("%d", &S);
    int SL = seq_length(S);
     
    for (int i = 0; i < SL; i++) 
    {

        digit = digit_value(S, SL - i -1);
        mirrorDigit = digit_value (S ,SL - K - i);
       
        
        while (digit == mirrorDigit)
        {
        
        x--;
        y++;
        digit = digit_value(S, SL + x - 1 - i);
        mirrorDigit = digit_value (S ,SL - K + y - i);
        
        if (x > y - K)
        {
            printf("The requested palindrome is: ");
            for (int j = 0; j < K; j++)
            {
            printf("%d", digit_value(S , SL - counter - 1 - j));
            
            }
           return 0; 
        }
        }
       counter++;
        }

           //out of number range
   printf("There is no such palindrome.\n");
    }




int seq_length(int seq)
{ 
    int length = 1;
    while (seq > 9)
    {
        seq = seq / 10;
        length++;
    }
    return length;
}


int digit_value (int sequence , int locator)
{
    
    
        return (sequence / poweroften (locator)) % 10 ;  
    }
    
   

//made it because the function "pow" doesn't works smooth
int poweroften (int k)
{
    
int tmp = 1;
for (int i = 0; i < k; i++)
{
tmp *= 10;
}

return tmp;

}








 



 
