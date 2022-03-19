
template<class T>
class Point
{
    private:
        std::vector<T> coordinates;
        int dim;

    public:
        Point(int dim);
        Point(const std::vector<T>& coordinates, int size);
        int getDim() const;
        Point& operator=(const Point&);
        std::ostream& print(ostream& os) const;
        T norm() const;
        T& operator[](int index) const;
        ~Point() = default;
        Point(const Point&) = default;
};

template<class T>
std::ostream& Point::print(ostream& os) const
{
    for (T cor : coordinates)
    {
        os << cor << " ";
    }
    return os;
}

template<class T>
std::ostream& operator<<(std::ostream& os, const Point<T>& point)
{
    return point.print(os);
}


class invalidDimExeption : public std::exeption {};

template<class T>
Point<T>& Point::operator=(const Point<T>& point)
{
    if (this->dim  != point.dim)
    {
        throw invalidDimExeption();
    }
    this->coordinates = pont.coordinates;
    return *this; 
}

template<class T>
class Sphere
{
    private:
        Point<T> center;
        T radius;

    public:
        Sphere(const Point<T>& center, const T& radius);
        Sphere& operator=(const Sphere& sphere);
        ostream& printSphere(ostream& os) const;
        Sphere& operator*(T r);
        ~Sphere() = default;
        Sphere(const Sphere&) = default;

};

template<class T>
ostream& Sphere<T>::printSphere(ostream& os) const
{
    os << "R = rad, ctr = (" << this->center << "")]"";
    return os;
}

template<class T>
ostream& operator<<(ostream& os, const Sphere<T>& s)
{
    return s.printSphere(os);
}

template<class T>
Sphere& operator=(const Sphere& s)
{
    if (this->center.getDim() != s.center.getDim())
    {
        throw invalidDimExeption();
    }
    this->center = s.center;
    this->radius = s.radius;
    return *this;
}