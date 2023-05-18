#ifndef NIINJA_HPP
#define NIINJA_HPP

#include "Character.hpp"
#include <string>

using namespace std;

namespace ariel{

    class Ninja : public Character
    {
        public:
            int agility;

        // public:
            Ninja(string name, Point location) : Character(std::move(name), location) ,agility(0){};
            void move(Character *other);
            void attack(Character *other) override {slash(other);}
            void slash(Character *other);
            int getAgility() const {return agility;}
            string getRole() override {return "Ninja";}
            string print() override;

            ~Ninja() override = default;
            Ninja(const Ninja&) = default;  // Copy constructor
            Ninja& operator=(const Ninja&) = default;  // Copy assignment operator
            Ninja(Ninja&&) = default;  // Move constructor
            Ninja& operator=(Ninja&&) = default;  // Move assignment operator
    };
    
}

#endif