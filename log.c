#include <stdio.h>

int main()
{
int number = 0;
printf("number: \n");
scanf("%d", &number);
int counter = 0;

int tmp = number;

while (tmp > 1)
{
    tmp = tmp / 2;
    counter++;
}
printf("log2(%d) = %d\n" ,number, counter);

}