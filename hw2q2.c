#include <stdio.h>


//declare functions
int seq_length(int seq);
int digit_value (int sequence , int locator);
int poweroften (int pw);
int findpalindrome(int S, int left_locator, int right_locator);

int main()
{
    //declare variables
    int S = 0, K = 0;
    
    //prompt the user for input
    printf("Please enter a length:\n"); scanf("%d",&K);

    printf("Please enter a sequence:\n"); scanf("%d", &S);
    
    //get the sequence length
    int SL = seq_length(S);
    
    //set digit locators
    int left_locator = SL - 1, right_locator = SL - K;
    
    //check if there is a matching palindrome
    int pali = findpalindrome(S, left_locator, right_locator);
    
    //pali didnt found
    if (pali == -1)
    {
        printf("There is no such palindrome.");
        return 0;
    }
    
    //print pali if found
    printf("The requested palindrome is: ");
    
    for (int i = 0; i < K; i++)
    {
        printf("%d", digit_value(S , SL - pali - 1 - i));
    }
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
    if (locator >= 0)
    {
        return (sequence / poweroften (locator)) % 10 ;  
    }
    
    //if the locator is out of range
    return -1;
}


int poweroften (int pw)
{
    int tmp = 1;
    for (int i = 0; i < pw; i++)
    {
        tmp *= 10;
    }

    return tmp;
}

int findpalindrome(int S, int left_locator, int right_locator)
{
    int digit = 0, mirrorDigit = 0, counter = 0;

    while (left_locator > right_locator) 
    {
        digit = digit_value(S, left_locator); mirrorDigit = digit_value (S ,right_locator);
         
         //if the locator is out of number range
         if (digit == -1 || mirrorDigit == -1)
        {
            return -1;
        }
        if (digit != mirrorDigit)
        {
            //move both locators right
            left_locator--; right_locator--; counter++;     
        }
        
        if (digit == mirrorDigit)
        {
            //move the left locator right and vice versa
            right_locator++; left_locator--; 
            //if the next pair isn't match, move both locators right
            if (digit_value(S, left_locator) != digit_value (S ,right_locator))
            {
               right_locator -= 2; counter++;            
            }
        }
    }
     return counter;
}

