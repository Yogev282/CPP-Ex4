#ifndef SMARTTEAM_HPP
#define SMARTTEAM_HPP

#include "Team.hpp"
#include <iostream>

using namespace std;

namespace ariel{

    class SmartTeam : public Team
    {
        public:
            SmartTeam(Character *leader) : Team(leader) {};
            void attack(Team *other) override;
            Character* findEnemy(Team *other) override;
    };

}

#endif