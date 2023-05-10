#include "Cowboy.hpp"
#include <string>

using namespace std;


Cowboy::Cowboy(string name, Point location) : Character(name, location)
{
}

void Cowboy::shoot(Character *other)
{
}

bool Cowboy::hasboolets()
{
    return false;
}

void Cowboy::reload()
{
}

string Cowboy::print()
{
    return "";
}