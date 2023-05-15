#ifndef NIINJAS_HPP
#define NIINJAS_HPP

#include "Character.hpp"
#include <string>

using namespace std;

class Ninja : public Character
{
    protected:
        int agility;

    public:
        string role = "Ninja";
        Ninja(string name, Point location) : Character(name, location){};
        void move(Character *other);
        void slash(Character *other);
        int getAgility(){return agility;}
        string print();
};



class OldNinja : public Ninja
{
    public:
        OldNinja(string name, Point location);
};



class TrainedNinja : public Ninja
{
    public:
        TrainedNinja(string name, Point location);
};



class YoungNinja : public Ninja
{
    public:
        YoungNinja(string name, Point location);
};



#endif