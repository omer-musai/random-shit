#include <iostream>
#include <string>
#include <sstream>


int main()
{
    float int_length=0, int_width=0;
    std::string length, width;
    //get length of the room
    std::cout << "enter length of the room: \n";
    std::getline(std::cin, length);

    //get width of the room
    std::cout << "enter width of the room: \n";
    std::getline(std::cin, width);
    
    std::stringstream(length)>> int_length;
    std::stringstream(width)>> int_width;

    float area = int_length * int_width;
    std::cout << "the area of the room is: " << area;
    return 0;
}
