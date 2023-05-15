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
        string role;
        bool inTeam = false;
        Character(string name, Point location) : name(name), location(location){};
        bool isAlive();
        double distance(Character *other);
        void hit(int damage);
        string getName(){return name;}
        Point getLocation(){return location;}
        void setLocation(Point location){this->location = location;}
        int getHealth(){return health;}
        virtual string print() = 0;
        
};

#endif