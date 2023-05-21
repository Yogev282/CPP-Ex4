#include "Cowboy.hpp"
#include <string>

using namespace std;

namespace ariel{

    Cowboy::Cowboy(string name, Point location) : Character(name, location)
    {
        this -> ammo = 6;
        this -> health = 110;
    }

    void Cowboy::shoot(Character *other)
    {
        if(!other->isAlive())
        {
            throw runtime_error("Character is dead");
        }
        if(other == nullptr)
        {
            throw invalid_argument("nullptr");
        }
        if(other == this)
        {
            throw runtime_error("Character cannot attack itself");
        }

        if ( this->isAlive() && this->ammo > 0 )
        {
            this->ammo--;
            other->hit(10);
        }
        // if no ammo, reload
        else if( this->isAlive() && this->ammo == 0 )
        {
            this->reload();
        }
        else
        { // this->isAlive() == false
            throw runtime_error("Character is dead");
        }
    }

    bool Cowboy::hasboolets()
    {
        return this->ammo > 0;
    }

    void Cowboy::reload()
    {
        if(!this->isAlive())
        {
            throw runtime_error("Character is dead");
        }
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

}