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
        Cowboy(string name, Point location);
        void shoot(Character *other);
        bool hasboolets();
        void reload();
        string print();
};

#endif