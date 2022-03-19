
#include "myfirstclass.hpp"

int main()
{
    Cat cat1,cat2;
    cat1.setName("Hatul");
    cat2.setName("Shimshon");
    cat1.setBreed("whoTheFuckKnowsBreedsOfCats");
    cat2.setBreed("same as cat1");
    cat1.setAge(3);
    cat2.setAge(1);

    cat1.printInfo();
    std::cout<<"\n";
    cat2.printInfo();
    return 0;
}
