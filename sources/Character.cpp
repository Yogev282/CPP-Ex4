#include "Character.hpp"
#include <cmath>

using namespace std;

namespace ariel{

    bool Character::isAlive()
    {
        return this->health > 0;
    }

    double Character::distance(Character *other)
    {
        return this->location.distance(other->location);
    }

    void Character::hit(int damage)
    {
        if(damage != 10 && damage != 40)
        {
            throw invalid_argument("damage must be an integer");
        }
        
        this->health -= damage;
        if(this->health < 0)
        {
            this->health = 0;
        }
    }

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

