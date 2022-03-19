#include <stdio.h>
#include <stdbool.h>
#define LETTERS 26
bool scramble(char *cubes[], int n, char* word);
bool scramble_aux(char *cubes[], int n, char hist[LETTERS]);
void fillHist(char* word, char hist[LETTERS]);
bool histIsEmpty(char hist[LETTERS]);
int main()
{

    char* cubes[4];
    cubes[0] = "ABC";
    cubes[1] = "AET";
    cubes[2] = "EOU";
    cubes[3] = "LNRST";
    char* word = "BAT";
    if(scramble(cubes, 4, word))
    {
        printf("true");
    }

    else if(!scramble(cubes, 4, word))
    {
        printf("false");
    }
}


bool scramble(char *cubes[], int n, char* word)
{
    char hist[LETTERS] = {0};
    fillHist(word, hist);
    return scramble_aux(cubes, n ,hist);
}

void fillHist(char* word, char hist[LETTERS])
{
    while(*word)
    {
        hist[(*word) - 'A']++;
        word++;
    }
}

bool scramble_aux(char *cubes[], int n, char hist[LETTERS])
{
    if(n==0)
    {
        return histIsEmpty(hist);
    }
    char *currCube = cubes[n-1];
    bool empty = false;

    while(*currCube && !empty)
    {
        hist[*currCube - 'A']--;
        empty = scramble_aux(cubes, n-1, hist);
        
        hist[*currCube - 'A']++;
        currCube++;
    }
    return empty;
}


bool histIsEmpty(char hist[LETTERS])
{
    for (int i=0; i<LETTERS; i++)
    {
        if (hist[i] > 0)
        {
            return false;
        }
    }
    return true;
}