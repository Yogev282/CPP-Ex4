#ifndef POINT_HPP
#define POINT_HPP

class Point
{
    private:
        double _x;
        double _y;

    public:
        Point(double x, double y);
        double distance(Point p);
        void print();
        friend void moveTowards(Point &p1, Point &p2, double distance);


};

#endif