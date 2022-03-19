#include <iostream>


std::string doubleSwap(std::string str,  char a, char b);

int main()
{
    char a ,b;
    std::string str;
    std::cout << "Enter your string and letters to swap: ";
    std::cin >> str >> a >> b;

    std::cout << doubleSwap(str, a, b);
    return 0;
}

std::string doubleSwap(std::string str,  char a, char b)
{
    for(int i =0; i < str.size(); i++)
    {
        if (str[i] == a)
        {
            str[i] = b;
        }
        else if (str[i] == b)
        {
            str[i] = a;
        }
    }
    return str;
}

