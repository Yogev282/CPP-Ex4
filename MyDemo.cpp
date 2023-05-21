#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <cassert>
using namespace std;

#include "sources/Team.hpp" //no need for other includes except SmartTeam.hpp
#include "sources/SmartTeam.hpp"

using namespace ariel;

int main()
{

    SmartTeam team(new Cowboy("Tom", Point(100,100)));
    team.add(new YoungNinja("Yogi", Point(1,0)));
    team.add(new TrainedNinja("Hikari", Point(3,3)));
    team.add(new Cowboy("Jerry", Point(0,1)));

    Team team2(new OldNinja("sushi", Point(0,0)));
    team2.add(new YoungNinja("Yogi", Point(3,2)));
    team2.add(new TrainedNinja("Hikari", Point(50,50)));

    team.attack(&team2);

    team2.print();

}