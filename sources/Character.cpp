#include "Character.hpp"

using namespace std;


Character::Character(string name, Point location) : name(name), location(location)
{
}

bool Character::isAlive()
{
    return false;
}

double Character::distance(Character *other)
{
    return 0;
}

void Character::hit(int damage)
{
}

string Character::getName()
{
    return "";
}

Point Character::getLocation()
{
    return Point(0, 0);
}

int Character::getHealth()
{
    return 0;
}

string Character::print()
{
    return "";
}

