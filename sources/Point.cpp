#include "Point.hpp"
#include <math.h>
#include <string>
#include <iostream>
#include <limits>

using namespace std;

namespace ariel{


    double Point::distance(Point pnt)
    {   
        // sqrt((x1-x2)^2 + (y1-y2)^2)
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
        // distance cannot be negative
        if(distance < 0)
        {
            throw invalid_argument("Distance cannot be negative");
        }
        // if distance is bigger than the distance between the points, return the second point
        else if(distance > pnt1.distance(pnt2))
        {
            return Point(pnt2.getX(), pnt2.getY());
        }

        // github.com/erich666/GraphicsGems/blob/master/gems/NearestPoint.c
        double x1 = pnt1.getX();
        double y1 = pnt1.getY();
        double x2 = pnt2.getX();
        double y2 = pnt2.getY();
        double x3 = x1 + (distance * (x2 - x1) / pnt1.distance(pnt2));
        double y3 = y1 + (distance * (y2 - y1) / pnt1.distance(pnt2));
        return Point(x3, y3);
    }

}
