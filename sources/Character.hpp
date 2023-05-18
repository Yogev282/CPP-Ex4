#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "Point.hpp"
#include <string>
#include <stdbool.h>
#include <stdexcept>

using namespace std;

namespace ariel{

    class Character
    {

        public:
            string name;
            int health;
            Point location;

        // public:
            bool inTeam = false;
            Character(string name, Point location) : name(std::move(name)), location(location), health(0){};
            virtual ~Character() = default;
            bool isAlive();
            double distance(Character *other);
            virtual void attack(Character *other) = 0;
            void hit(int damage);
            string getName() const {return name;}
            Point getLocation() const {return location;}
            void setLocation(Point location) {this->location = location;}
            int getHealth() const {return health;}
            virtual string getRole() = 0;
            int compare(Character *other);
            virtual string print() = 0;

            Character(const Character&) = default;  // Copy constructor
            Character& operator=(const Character&) = default;  // Copy assignment operator
            Character(Character&&) = default;  // Move constructor
            Character& operator=(Character&&) = default;  // Move assignment operator
            
    };

}

#endif