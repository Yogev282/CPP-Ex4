#include "TrainedNinja.hpp"

using namespace std;

namespace ariel{

    TrainedNinja::TrainedNinja(string name, Point location) : Ninja(name, location)
    {
        this->agility = 12;
        this->health = 120;
    }

    TrainedNinja::~TrainedNinja()
    {
        // cout << "TrainedNinja destructor" << endl;
    }

}