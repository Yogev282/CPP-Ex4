#ifndef POINT_HPP
#define POINT_HPP

#include <string>

using namespace std;

class Point
{
    private:
        double _x;
        double _y;
        

    public:
        // static const Point* points[];
        // static const int count;
        Point(double x_point, double y_point);
        double distance(Point pnt);
        void print();
        string toString();
        double getX() const {return _x;}
        double getY() const {return _y;}
        void setX(double x_point){_x = x_point;}
        void setY(double y_point){_y = y_point;}
        friend Point moveTowards(Point &pnt1, Point &pnt2, double distance);


};

#endif