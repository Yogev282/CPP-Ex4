#include "Cowboy.hpp"
#include <string>

using namespace std;


Cowboy::Cowboy(string name, Point location) : Character(name, location)
{
    this -> ammo = 6;
    this -> health = 110;
}

Cowboy::~Cowboy()
{
    // cout << "Cowboy destructor" << endl;
}

void Cowboy::shoot(Character *other)
{
    if ( this->isAlive() && this->ammo > 0 )
    {
        this->ammo--;
        other->hit(10);
    }
    else if( this->isAlive() && this->ammo == 0 )
    {
        this->reload();
    }
    else
    {
        throw "Character is dead";
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