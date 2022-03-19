class Line : public Polygon 
{
    public:
        Line(const Point p[2]) : Polygon(p, 2) {}
}

class Rectangle : public Polygon
{
    public:
        Rectangle(const Point p[4]) : polygon(p ,4) {}
}

class PolygonGroup : public Rectangle
{
    public:
        void addPolygon(Polygon* p);
        PolygonGroup& operator += (const Point& p)
        
        void draw() const override
        {
            Rectangle::draw();

            for (int i = 0; i < polygons.size(); i++)
            {
                polygons[i]->draw();
            }
        }

    private:
        std::vector<Polygon*> polygons;

}