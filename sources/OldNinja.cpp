#include "OldNinja.hpp"

using namespace std;

namespace ariel{

    OldNinja::OldNinja(string name, Point location) : Ninja(name, location)
    {
        this->agility = 8;
        this->health = 150;
    }

    OldNinja::~OldNinja()
    {
        // cout << "OldNinja destructor" << endl;
    }
    
}