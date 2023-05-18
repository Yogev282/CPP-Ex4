#include "Point.hpp"
#include <math.h>
#include <string>
#include <iostream>
#include <limits>

using namespace std;

namespace ariel{


    double Point::distance(Point pnt)
    {
        return sqrt(pow(_x - pnt._x, 2) + pow(_y - pnt._y, 2));
    }

    void Point::print()
    {
        cout << "(" << _x << "," << _y << ")";
    }

    string Point::toString()
    {
        return "(" + to_string(_x) + "," + to_string(_y) + ")";
    }

    Point Point::moveTowards( Point& pnt1, Point& pnt2, double distance)
    {
        if(distance < 0)
        {
            throw invalid_argument("Distance cannot be negative");
        }

        double x1 = pnt1.getX();
        double y1 = pnt1.getY();
        double x2 = pnt2.getX();
        double y2 = pnt2.getY();
        double x3 = x1 + (distance * (x2 - x1) / pnt1.distance(pnt2));
        double y3 = y1 + (distance * (y2 - y1) / pnt1.distance(pnt2));
        return Point(x3, y3);
    }

}
