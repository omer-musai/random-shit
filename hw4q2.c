#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_WORD 32
#define NOUN_LEN 6
#define VERB_LEN 5
#define ADJ_LEN 6
#define a 'a'
#define z 'z'
#define A 'A'
#define Z 'Z'
#define DOT '.'

bool is_suffix_in_dict(char *str, char *dict[], int n);
bool read_sentence(char *noun_suffixes[], int noun_suffixes_len,
                   char *verb_suffixes[], int verb_suffixes_len,
                   char *adj_suffixes[], int adj_suffixes_len,
                   int *num_of_nouns, int *num_of_verbs, int *num_of_adjs);
void print_stats(int num_of_nouns, int num_of_verbs, int num_of_adjs );





void print_stats(int num_of_nouns, int num_of_verbs, int num_of_adjs )
{
    printf("The sentence had %d special nouns, %d special verbs and %d special adjectives.\n",
               num_of_nouns, num_of_verbs, num_of_adjs);
    return;
}




int main(){
    char *noun_suffixes[] = {"msi", "re", "sci", "ssen", "tnem", "tsi"};
    char *verb_suffixes[] = {"de", "eta", "ezi", "gni", "yfi"};
    char *adj_suffixes[] = {"elba", "evi", "hsi", "la", "luf", "suo"};
    
    int nouns = 0;
    int verbs = 0;
    int adjs = 0;
    int* num_of_nouns = &nouns;
    int* num_of_verbs = &verbs;
    int* num_of_adjs = &adjs;
    printf("Enter text to analyze:\n");
    
    while(read_sentence(noun_suffixes, NOUN_LEN, verb_suffixes, VERB_LEN, adj_suffixes, ADJ_LEN, num_of_nouns, num_of_verbs, num_of_adjs))
    {
        print_stats(*num_of_nouns, *num_of_verbs, *num_of_adjs);
        *num_of_nouns = 0;
        *num_of_verbs = 0;
        *num_of_adjs = 0;
    }
  
   return 0;
}

bool is_suffix_in_dict(char *str, char *dict[], int n)
{
    int low =0, mid = 0, high = n-1;
    int c =0;
    int cnt =0;
    char word[MAX_WORD]; 
    char mirrorword[MAX_WORD];
    word[0] = '\0';
    mirrorword[0] = '\0';
    
    //copy the word but with only lowcase letters
    while(str[c])
    {
      if (str[c] >= a && str[c] <= z)
      {
          word[cnt] = str[c];
          
          cnt++;
          c++;
          continue;
      }
      if (str[c] >= A && str[c] <= Z)
      {
          word[cnt] = (str[c] + (a - A));
          
          cnt++;  
          c++;
          continue;
      }
      //go to the next charcter in the original word only
           c++;
    }
    
    //flip the word to start from the end
    for (int i=0; i < cnt; i++)
    {
    mirrorword[i] = word[cnt - i - 1];
    }

    
   //binary search, check if suffixes match
    while (low <= high)
    {
      mid = (low + high) / (1+1);

      if (strncmp(mirrorword, dict[mid], strlen(dict[mid])) < 0)
      {
          high = mid - 1;  
      }

       else if (strncmp(mirrorword, dict[mid], strlen(dict[mid]) ) > 0)
      {
          low = mid + 1;   
      }
      else
      {
          return true;
      }
      
    }
    
   return false;

}

bool read_sentence(char *noun_suffixes[], int noun_suffixes_len,
                   char *verb_suffixes[], int verb_suffixes_len,
                   char *adj_suffixes[], int adj_suffixes_len,
                   int *num_of_nouns, int *num_of_verbs, int *num_of_adjs)
                   {
                       char wrd[MAX_WORD];
                       
                       while(scanf("%s", wrd) != EOF)
                       {
                            if(is_suffix_in_dict(wrd, noun_suffixes, noun_suffixes_len))
                            {
                                *num_of_nouns += 1;
                            }
                            if(is_suffix_in_dict(wrd, verb_suffixes, verb_suffixes_len))
                            {
                                *num_of_verbs += 1;
                            }
                            if(is_suffix_in_dict(wrd, adj_suffixes, adj_suffixes_len))
                            {
                                *num_of_adjs += 1;
                            }
                            if(wrd[strlen(wrd) - 1] == DOT)
                            {
                                return true;
                            }
                       } 
                    return false;
                   }


