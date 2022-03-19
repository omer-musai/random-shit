#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define MAX_LENGTH 32
#define TWO 2
#define CAP_A 'A'
#define CAP_Z 'Z'
#define SM_A 'a'
#define SM_Z 'z'
#define DOT '.'
#define SPACE ' '
#define BA_ZERO '\0'
#define NOUN_LENGTH 6
#define VERB_LENGTH 5
#define ADJ_LENGTH  6


bool is_suffix_in_dict(char *str, char *dict[], int n);
bool read_sentence(char *noun_suffixes[], int noun_suffixes_len,
                   char *verb_suffixes[], int verb_suffixes_len,
                   char *adj_suffixes[], int adj_suffixes_len,
                   int *num_of_nouns, int *num_of_verbs, int *num_of_adjs);
void print_stats(int num_of_nouns, int num_of_verbs, int num_of_adjs );


/* Additional functions of your choice */
void lett_conv(char *str);
int binary_search(char *str, char *dict[], int n);
void elem_romover(char *str);
void str_swap(char *str);


int main()
{
    char *noun_suffixes[] = {"msi", "re", "sci", "ssen", "tnem", "tsi"};
    char *verb_suffixes[] = {"de", "eta", "ezi", "gni", "yfi"};
    char *adj_suffixes[] = {"elba", "evi", "hsi", "la", "luf", "suo"};
    int noun_suffixes_len= NOUN_LENGTH;
    int verb_suffixes_len= VERB_LENGTH;//* to  change!!!!
    int adj_suffixes_len=  ADJ_LENGTH;
    int num_of_nouns=0,num_of_verbs =0, num_of_adjs=0;
    printf("Enter text to analyze:\n");
    read_sentence( noun_suffixes,noun_suffixes_len,
                   verb_suffixes,verb_suffixes_len,
                   adj_suffixes,adj_suffixes_len,
                   &num_of_nouns,&num_of_verbs,&num_of_adjs );

    return 0;
}




void print_stats(int num_of_nouns, int num_of_verbs, int num_of_adjs )
{
    printf("The sentence had %d special nouns, %d special verbs and %d special adjectives.\n",
           num_of_nouns, num_of_verbs, num_of_adjs);
    return;
}


bool is_suffix_in_dict(char *str, char *dict[], int n)
{
  if (binary_search(str,dict,n) == -1)
    return false;
  else
    return true;

}

//converting capital letters to small letters
void lett_conv(char *str)
{
    int length= strlen(str);
    for(int i=0; i<length; i++)
    {
        if(str[i]>=CAP_A && str[i]<=CAP_Z)
            str[i]=str[i]+MAX_LENGTH;
    }
}

// binary search for strings.
int binary_search(char *str, char *dict[], int n)
{
    int low= 0;
    int high= n-1;
    int mid;
    while(low<=high)
    {
        mid = (low + high) / TWO;
        int suff_len=strlen(dict[mid]);
        if ( strncmp(str,dict[mid],suff_len) <0 )
              high = mid - 1;
        else if (strncmp(str,dict[mid],suff_len) >0)
              low = mid + 1;
        else return 0;

    }
return -1;
}

//removing digits which are not letters
void elem_romover(char *str)
{
    int length=strlen(str);
    for(int i=0; i<length && str[i]!= SPACE ;i++)
    {
        if( (str[i]<SM_A || str[i]>SM_Z) && str[i]!= DOT )
        {
            int j;
            for(j=0; j < length-i-1 ;j++)
            {
                str[i+j] = str[i+j+1];
            }
             str[i+j]= SPACE;
             i=0;
        }
    }
}

void str_swap(char *str)
{
    int length= strlen(str);
    char dest [MAX_LENGTH];
    strcpy(dest,str);
    for(int i=0; i < length/TWO ;i++)
    {
       if(str[length-1] !='.')
       {
           str[i]= dest[length-1-i];
           str[length -1-i]= dest [i];
       }
       else
       {
           str[i]= dest[length-TWO-i];
           str[length -TWO-i]= dest [i];
       }

    }
}


bool read_sentence( char *noun_suffixes[], int noun_suffixes_len,
 char *verb_suffixes[], int verb_suffixes_len,
 char *adj_suffixes[], int adj_suffixes_len,
 int *num_of_nouns, int *num_of_verbs, int *num_of_adjs )
{
 int tot_nouns= *num_of_nouns;
 int tot_verbs= *num_of_verbs;
 int tot_adjs= *num_of_adjs;
 char str [MAX_LENGTH];

  // initiate str
  str[0]= BA_ZERO;

  while( scanf("%s",str) != EOF )
  {
      lett_conv(str);
      str_swap(str);
      elem_romover(str);
      if( is_suffix_in_dict(str,noun_suffixes,noun_suffixes_len) )
           tot_nouns++;
      if( is_suffix_in_dict(str,verb_suffixes,verb_suffixes_len) )
           tot_verbs++;
      if( is_suffix_in_dict(str,adj_suffixes,adj_suffixes_len) )
           tot_adjs++;

      int length= strlen(str);
      for(int i=0;i<length;i++)
      {
          if(str[i]== DOT)
          {
            print_stats(tot_nouns,tot_verbs,tot_adjs);
            tot_nouns=0;
            tot_verbs=0;
            tot_adjs=0;
          }
      }
  }
return true;
}








