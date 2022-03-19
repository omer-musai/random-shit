#include <stdio.h>

int main()
{
    //declare variables
    char key_letter, letter;
    int letter_counter = 0;

    //prompt the user for key letter
    printf("Enter letter to count:\n");

    scanf("%c", &key_letter);

    //check if the char is actuall letter with ascii values
    if (key_letter < 65 || (key_letter > 90 && key_letter < 97)  || key_letter > 122)
    {
        return 0;
    }

    //prompt the user for char sequence
    printf("Enter the char sequence:\n");
    do
    {
        scanf("%c", &letter);
        // count the key letter (lowercase equal uppercase and vice versa) 
        if ((letter == key_letter) || ((letter == key_letter + 32) && (letter > 96) && (letter < 123)) || ((letter == key_letter - 32) && (letter > 64) && (letter < 91)))
        {
            letter_counter++;
        }
    }
    while(letter != '#');   

    //print result
    printf("The letter appeared %d times\n", letter_counter);

    //end
    return 0;
}