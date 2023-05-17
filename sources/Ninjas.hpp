#ifndef NIINJAS_HPP
#define NIINJAS_HPP

#include "Character.hpp"
#include <string>

using namespace std;

class Ninja : public Character
{
    public:
        int agility;

    // public:
        string role = "Ninja";
        Ninja(string name, Point location) : Character(std::move(name), location) ,agility(0){};
        void move(Character *other);
        void slash(Character *other);
        int getAgility() const {return agility;}
        string print() override;

        ~Ninja() override = default;
        Ninja(const Ninja&) = default;  // Copy constructor
        Ninja& operator=(const Ninja&) = default;  // Copy assignment operator
        Ninja(Ninja&&) = default;  // Move constructor
        Ninja& operator=(Ninja&&) = default;  // Move assignment operator
};



class OldNinja : public Ninja
{
    public:
        OldNinja(string name, Point location);
        ~OldNinja() override;

    
    OldNinja(const OldNinja&) = default;  // Copy constructor
    OldNinja& operator=(const OldNinja&) = default;  // Copy assignment operator
    OldNinja(OldNinja&&) = default;  // Move constructor
    OldNinja& operator=(OldNinja&&) = default;  // Move assignment operator
};



class TrainedNinja : public Ninja
{
    public:
        TrainedNinja(string name, Point location);
        ~TrainedNinja() override;

    
    TrainedNinja(const TrainedNinja&) = default;  // Copy constructor
    TrainedNinja& operator=(const TrainedNinja&) = default;  // Copy assignment operator
    TrainedNinja(TrainedNinja&&) = default;  // Move constructor
    TrainedNinja& operator=(TrainedNinja&&) = default;  // Move assignment operator
};



class YoungNinja : public Ninja
{
    public:
        YoungNinja(string name, Point location);
        ~YoungNinja() override;


    YoungNinja(const YoungNinja&) = default;  // Copy constructor
    YoungNinja& operator=(const YoungNinja&) = default;  // Copy assignment operator
    YoungNinja(YoungNinja&&) = default;  // Move constructor
    YoungNinja& operator=(YoungNinja&&) = default;  // Move assignment operator

};



#endif