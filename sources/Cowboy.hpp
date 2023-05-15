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

    public:
        string role = "Cowboy";
        Cowboy(string name, Point location);
        void shoot(Character *other);
        bool hasbullets();
        void reload();
        string print();
};

#endif