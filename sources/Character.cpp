#include "Character.hpp"

using namespace std;


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
    this->health -= damage;
}


