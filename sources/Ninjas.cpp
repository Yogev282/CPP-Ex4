#include "Ninjas.hpp" 
#include "Point.hpp"
#include <string>
#include <cmath>

using namespace std;

void Ninja::move(Character *other)
{
    double dx = this-> getLocation().getX() - other->getLocation().getX();
    double dy = this-> getLocation().getY() - other->getLocation().getY();
    double distanceAB = sqrt(dx * dx + dy * dy);

    if(this->agility <= distanceAB)
    {
        double ratio = this->agility / distanceAB;
        this->setLocation(Point(this->location.getX() + dx * ratio, this->location.getY() + dy * ratio));
    }
    else
    {
        this->setLocation(other->getLocation());
    }
}

void Ninja::slash(Character *other)
{
    if(this->isAlive() && this->distance(other) <= 1)
    {
        other->hit(30);
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

OldNinja::OldNinja(string name, Point location) : Ninja(name, location)
{
    this->agility = 8;
    this->health = 150;
}

TrainedNinja::TrainedNinja(string name, Point location) : Ninja(name, location)
{
    this->agility = 12;
    this->health = 120;
}

YountNinja::YountNinja(string name, Point location) : Ninja(name, location)
{
    this->agility = 14;
    this->health = 100;
}