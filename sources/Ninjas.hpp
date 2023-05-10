#ifndef NIINJAS_HPP
#define NIINJAS_HPP

#include "Character.hpp"
#include <string>

using namespace std;

class Ninja : public Character
{
    private:
        int agility;
        string performance;

    public:
        Ninja(string name, Point location);
        void move(Character *other);
        void slash(Character *other);
        int getAgility();
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



class YountNinja : public Ninja
{
    public:
        YountNinja(string name, Point location);
};



#endif