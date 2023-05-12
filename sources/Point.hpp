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
        static Point* points[];
        static int count;
        Point(double x, double y);
        double distance(Point p);
        void print();
        string toString();
        double getX(){return _x;}
        double getY(){return _y;}
        void setX(double x){_x = x;}
        void setY(double y){_y = y;}
        friend Point moveTowards(Point &p1, Point &p2, double distance);


};

#endif