#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "Point.hpp"
#include <string>
#include <stdbool.h>

using namespace std;

class Character
{

    public:
        string name;
        int health;
        Point location;

    // public:
        string role;
        bool inTeam = false;
        Character(string name, Point location) : name(std::move(name)), location(location), health(0){};
        virtual ~Character() = default;
        bool isAlive();
        double distance(Character *other);
        void hit(int damage);
        string getName() const {return name;}
        Point getLocation() const {return location;}
        void setLocation(Point location) {this->location = location;}
        int getHealth() const {return health;}
        virtual string print() = 0;

        Character(const Character&) = default;  // Copy constructor
        Character& operator=(const Character&) = default;  // Copy assignment operator
        Character(Character&&) = default;  // Move constructor
        Character& operator=(Character&&) = default;  // Move assignment operator
        
};

#endif