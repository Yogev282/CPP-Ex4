#include "Ninja.hpp" 
#include "Point.hpp"
#include <string>
#include <cmath>

using namespace std;

namespace ariel{

    void Ninja::move(Character *other)
    {
        if(!this->isAlive())
        {
            throw "Character is dead";
        }
        else
        {
            this->location = Point::moveTowards(this->location, other->location, this->agility);
        }
    }

    void Ninja::slash(Character *other)
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
     
        if(this->isAlive() && this->distance(other) <= 1)
        {
            other->hit(40);
        }
        else if (this->isAlive() && this->distance(other) > 1)
        {
            this->move(other);
        }
        else{
            throw runtime_error("Character is dead");
        }
    }

    string Ninja::print()
    {
        string printer = "";
        if (this->isAlive())
        {
            printer = "N - " + this->name + ", " + to_string(this->health) + " HP, at " + this->location.toString();
        }
        else
        {
            printer = "N - (" + this->name + "), DEAD";
        }
        return printer;
    }
    
}