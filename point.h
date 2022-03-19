template<class T>
class Point
{
    private:
        int dim;
        std::vector<T> coordinates;


    public:
        Point(int dim);
        Point(T arr[], int size);
        int getDem() const;
        Point& operator= (const Point&);
        friend ostream& operator<< (ostream& os, const Point& point);

        Point& operator+= (const Point&);
        void setDem();
}



ostream& operator<< (ostream& os, const Point& point)
{
    for (int i = 0; i < point.coordinates.size(); i++)
    {
        std::cout<<point.coordinates[i]<<' ';
    }
}