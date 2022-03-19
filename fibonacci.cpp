#include <iostream>

int fibonacci(int n);

int main()
{
    int n;
    std::cin >> n;
    std::cout << fibonacci(n);
}



int fibonacci(int n)
{
    if (n == 2)
    {
        return 1;
    }
    if (n == 1)
    {
        return 1;
    }
    return fibonacci(n-1) + fibonacci(n-2);
}