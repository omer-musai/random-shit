
#include <iostream>
#define NUMS 5

int main()
{
    int numbers[NUMS] = {0};
    int sum=0, average =0;
    std::cout<<"enter five numbers: \n";
    
    for(int i=0; i < NUMS; i++)
    {
        std::cin>>numbers[i];
        sum += numbers[i];
    }
    
    average = sum/NUMS;
    
    std::cout<<"the sum is: "<<sum<<"\n";
    std::cout<<"the average is: "<<average<<"\n";
    
    return 0;
    
    
}