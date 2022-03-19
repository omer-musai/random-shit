template<class T>
class CBtree
{
    private:
        T* tree;
        int size;

    public:
        CBtree(int size = 0) : size(size){
            tree = new T[size];
        }
        CBtree(Const CBtree&) = default;

        ~CBtree(){
            delete[] tree;
        }
        CBtree& operator=(CBtree&) = default;
        void operator>>(T&);
        const T& max() const
        {
            T max = tree[0];
            for (int i =0; i < size; i++)
            {
                if(max < tree[i])
                {
                    max = tree[i];
                }
            }
            return max;
        }
        CBtree& operator<<(const T& node)
        {
            for (int i = 0; i < size; i++)
            {
                if (node == tree[i])
                {
                    throw TreeExeption();
                }
                if(!tree[i])
                {
                    tree[i] = node;
                    return *this;
                }
            }
            T* t = new T[2 * size];
                for (int i =0; i < size: i++)
                {
                    t[i] = tree[i];
                }
                delete[] tree;
                this->tree = t;
                t[size] = node;
                this->size = 2*size;
                return *this;
        }
        friend ostream& operator<<(ostream& os, const CBtree& t);

        class TreeExeption : public std::exeption
        {
            public:
                virtual const string& what() =  0;
        }
}

template<class T>
ostream& operator<<(ostream& os, const CBtree<T>& t)
{
    int i=0;
    while(t.tree[i])
    {
        os << tree[i] << '\n';
        i++;
    }
    return os;
}

template<class T>
class CBsortedTree : public CBtree<T>
{

}