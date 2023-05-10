#include "Ninjas.hpp"


Ninja::Ninja(string name, Point location) : Character(name, location)
{
}

void Ninja::move(Character *other)
{
}

void Ninja::slash(Character *other)
{
}

int Ninja::getAgility()
{
    return 0;
}

string Ninja::print()
{
    return "";
}

OldNinja::OldNinja(string name, Point location) : Ninja(name, location)
{
}

TrainedNinja::TrainedNinja(string name, Point location) : Ninja(name, location)
{
}

YountNinja::YountNinja(string name, Point location) : Ninja(name, location)
{
}