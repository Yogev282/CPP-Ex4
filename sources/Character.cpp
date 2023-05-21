#include "Character.hpp"
#include <cmath>

using namespace std;

namespace ariel{

    bool Character::isAlive()
    {
        return this->health > 0;
    }

    // uses the distance function from Point
    double Character::distance(Character *other)
    {
        return this->location.distance(other->location);
    }

    void Character::hit(int damage)
    {
        // damage must be 10 by shooting or 40 by slashing
        if(damage != 10 && damage != 40)
        {
            throw invalid_argument("damage must be an integer");
        }
        
        this->health -= damage;
        // health can't be negative
        if(this->health < 0)
        {
            this->health = 0;
        }
    }

    // compare characters by their roles, uses to sort the members in the team
    int Character::compare(Character *other)
    {
        if(this-> getRole() == "Cowboy" && other->getRole() == "Ninja")
        {
            return -1;
        }
        else if(this-> getRole() == "Ninja" && other->getRole() == "Cowboy")
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    
}

