#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "Point.hpp"
#include <string>
#include <stdbool.h>

using namespace std;

class Character
{

protected:
    string name;
    int health;
    Point location;

public:
    Character(string name, Point location);
    bool isAlive();
    double distance(Character *other);
    void hit(int damage);
    string getName();
    Point getLocation();
    int getHealth();
    virtual string print() = 0;
    


};

#endif