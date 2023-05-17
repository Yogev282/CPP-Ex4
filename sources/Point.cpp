#include "Point.hpp"
#include <math.h>
#include <string>
#include <iostream>
#include <limits>


using namespace std;

// int Point::count = 0;
// Point* Point::points[std::numeric_limits<int>::max()];

Point::Point(double x_point, double y_point) : _x(x_point), _y(y_point)
{
//    points[count++] = this;
}

double Point::distance(Point pnt)
{
    // return sqrt(pow(_x - p._x, 2) + pow(_y - p._y, 2));
    return 0;
}

void Point::print()
{
    // cout << "(" << _x << "," << _y << ")";
}

string Point::toString()
{
    // return "(" + to_string(_x) + "," + to_string(_y) + ")";
    return "";
}

Point moveTowards(Point &pnt1, Point &pnt2, double distance)
{
    // // array of points
    // Point* tmp[Point::count];
    
    // for (int i = 0; i < Point::count; i++)
    // {
    //     tmp[i] = Point::points[i];
    // }
    // // sort array by distance from p2 by bubble sort
    // for (int i = 0; i < Point::count; i++)
    // {
    //     for (int j = i + 1; j < Point::count; j++)
    //     {
    //         if (p2.distance(*tmp[i]) > p2.distance(*tmp[j]))
    //         {
    //             Point* temp = tmp[i];
    //             tmp[i] = tmp[j];
    //             tmp[j] = temp;
    //         }
    //     }
    // }

    // // find the closest point to p2 that p.distance(p1) < distance
    // for (int i = 0; i < Point::count; i++)
    // {
    //     if (p1.distance(*tmp[i]) < distance)
    //     {
    //         if(tmp[i] == &p1 || tmp[i] == &p2)
    //         {
    //             continue;
    //         }
           
    //         return *tmp[i];

    //     }
    // }
    // // if there is no point that p.distance(p1) < distance return p1
    // return p1;
    return Point(0,0);
}

