#ifndef COWBOY_HPP
#define COWBOY_HPP

#include "Point.hpp"
#include "Character.hpp"
#include <string>

using namespace std;

class Cowboy : public Character
{
    private:
        int ammo;
        string role = "Cowboy";

    public:
        Cowboy(string name, Point location);
        ~Cowboy() override;
        void shoot(Character *other);
        bool hasbullets();
        void reload();
        string print() override;

        Cowboy(const Cowboy&) = default;  // Copy constructor
        Cowboy& operator=(const Cowboy&) = default;  // Copy assignment operator
        Cowboy(Cowboy&&) = default;  // Move constructor
        Cowboy& operator=(Cowboy&&) = default;  // Move assignment operator
};

#endif