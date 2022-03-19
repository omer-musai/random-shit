#include <stdio.h>

int main()
{
//declare variables
double x = 0;
double ing_sum= 0;
double final_weight = 0;
int scanvalue = 0;
int purity = 0;
int ing_counter = 0;

//prompt Walter for ingredients
printf("Welcome, please enter the weights of each ingredient:\n");

//calculate the number of ingredients, purity and the sum of ingredients weight.
do
{
    scanvalue = scanf("%lf", &x);
    if ((x >= 0) && scanvalue == 1)
    {
      ing_sum += x;
      purity += 10;
      ing_counter++;
    }  
    else if (scanvalue != 1)
    {
        return 0;
    }  
}
while(x >= 0);

//require between 3 to 10 ingredients
if (ing_counter < 3)
{
    printf("Not enough ingredients.\n");
    return 0;
}
if (ing_counter > 10)
{
    printf("Too many ingredients.\n");
    return 0;
}

//calculate the average weight
final_weight = (ing_sum / ing_counter);

//print result
printf("The final product weighs %.3lf pounds and is %d percent pure.\n", final_weight, purity);

//end
return 0;
}