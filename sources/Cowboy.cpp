#include "Cowboy.hpp"
#include <string>

using namespace std;


Cowboy::Cowboy(string name, Point location) : Character(name, location)
{
    this -> ammo = 6;
    this -> health = 110;
}

void Cowboy::shoot(Character *other)
{
    if (this->ammo > 0 && this->isAlive())
    {
        this->ammo--;
        other->hit(10);
    }
}

bool Cowboy::hasbullets()
{
    return this->ammo > 0;
}

void Cowboy::reload()
{
    this->ammo = 6;
}

string Cowboy::print()
{
    string printer = "";
    if (this->isAlive())
    {
        printer = "C - " + this->name + ", " + to_string(this->health) + " HP, at " + this->location.toString();
    }
    else
    {
        printer = "C - (" + this->name + "), DEAD";
    }
    return printer;
}