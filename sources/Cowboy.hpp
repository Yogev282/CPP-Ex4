#ifndef COWBOY_HPP
#define COWBOY_HPP

#include "Point.hpp"
#include "Character.hpp"
#include <string>

using namespace std;

namespace ariel{

    class Cowboy : public Character
    {
        private:
            int ammo;

        public:
            Cowboy(string name, Point location);
            ~Cowboy() override;
            void attack(Character *other) override {shoot(other);}
            void shoot(Character *other);
            bool hasboolets();
            void reload();
            string getRole() override {return "Cowboy";}
            string print() override;

            Cowboy(const Cowboy&) = default;  // Copy constructor
            Cowboy& operator=(const Cowboy&) = default;  // Copy assignment operator
            Cowboy(Cowboy&&) = default;  // Move constructor
            Cowboy& operator=(Cowboy&&) = default;  // Move assignment operator
    };

}

#endif