#include <iostream>

std::string uncensored(std::string cens_str, std::string vowels);

int main()
{
    std::string cens_str, vowels;

    std::cout << "enter censored string and vowels: ";
    std::cin >> cens_str >> vowels;

    std::cout << uncensored(cens_str, vowels);
    return 0;
}

std::string uncensored(std::string cens_str, std::string vowels)
{
    int counter = 0;

    for(int i=0; i < cens_str.size(); i++)
    {
        if (cens_str[i] == '*')
        {
            cens_str[i] = vowels[counter];
            counter++;
        }
    }
    return cens_str;
}