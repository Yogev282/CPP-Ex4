#include "YoungNinja.hpp"

using namespace std;

namespace ariel{

    YoungNinja::YoungNinja(string name, Point location) : Ninja(name, location)
    {
        this->agility = 14;
        this->health = 100;
    }

    // YoungNinja::~YoungNinja()
    // {
    //     // cout << "YoungNinja destructor" << endl;
    // }

}