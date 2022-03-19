#include <vector>
#include <stdio.h>
#include <string.h>


template<class T>
class Polynomial
{
    private:

        int degree;
        std::vector<T> indeterminats;
        std::vector<T> coefficients;

    public:
        Polynomial() = default;
        Polynomial(const Polynomial&)= default;
        ~Polynomial() = default;
        Polynomial& operator=(const Polynomial&) = default;


        Polynomial(const char*);







}