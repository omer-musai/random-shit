#include <stdio.h>
#include <stdlib.h>

#define ABC 26

void cipher(char* s, int x)
{
    
    int y = x%ABC;
    int i=0;
    while(*(s + i))
    {
        if(*(s+i) + y > 'z' || *(s+i) + y > 'Z' && *(s+i) + y < 'a')
        {
            *(s+i) += y - ABC;;
        } 
        else
        {
            *(s+i) += y;
        }
        ++i;
    }
}

int main()
{
    char s[9] = "YesWeCan";
    //printf("%s", s);
    cipher(s, 3);
    
    printf("%s", s);
}