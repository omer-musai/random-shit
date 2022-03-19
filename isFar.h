

class isFar
{
    private:
        double distance;

    public:
        isFar(double d) : distance(d){}
        bool operator()(const Point& point) const
        {
            return point.distance(Point(0,0)) > this->distance;
        }
};

namespace mtm {
template <class T>
class stack {
public:
 explicit stack(int max_size = 100);
 stack(const Stack& s);
 ~stack();
 stack& operator=(const Stack&);
 void push(const T& t);
 void pop();
 T& top();
 const T& top() const;
 int getSize() const;

 friend ostream& operator<<(ostream& os, const stack& s)
 {
     genericPrint(s.array, s.array + s.getSize(), os);
     return os;
 } 

 class Exception : public std::exception {};
 class Full : public Exception {};
 class Empty : public Exception {};
};
}

namespace mtm{

template <class T>
class ConditionalStack : public stack<T> {

    public:
        ConditionalStack(int max_size = 100) : stack<T>(max_size){}
        template<predicate Pred>
        void popConditional(Pred pred)
        {
            while(this->getsize() > 0 && !pred(this->top()))
            {
                this->pop();
            }
            if(this->getSize() == 0)
            {
               throw NotFound(); 
            }
            
        }

        class NotFound : public stack<T>::Exeption 
        {
            const char* what() const override
            {
                return "Not Found";
            }
        };
};



try{
    s.popConditional(isFar(15);)
} catch (const ConditonalStack<Point>::NotFound& e){
    std::cout << e.what();
}

}

template(class iterator)
void genericPrint(iterator begin, iterator end, ostream& os)
{
    iterator first = begin;
    os << "[";
    for (iterator current = begin; current != end; current++)
    {
        if(current != first)
        {
            os << ", ";
        }
        os << *current;
    }
    os << "]";
}


