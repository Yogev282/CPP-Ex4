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
        other->hit(40);
    }
    else if (this->isAlive() && this->distance(other) > 1)
    {
        this->move(other);
    }
    else{
        throw "Character is dead";
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

OldNinja::~OldNinja()
{
    // cout << "OldNinja destructor" << endl;
}

TrainedNinja::TrainedNinja(string name, Point location) : Ninja(name, location)
{
    this->agility = 12;
    this->health = 120;
}

TrainedNinja::~TrainedNinja()
{
    // cout << "TrainedNinja destructor" << endl;
}

YoungNinja::YoungNinja(string name, Point location) : Ninja(name, location)
{
    this->agility = 14;
    this->health = 100;
}

YoungNinja::~YoungNinja()
{
    // cout << "YoungNinja destructor" << endl;
}