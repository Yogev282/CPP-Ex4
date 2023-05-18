#ifndef SMARTTEAM_HPP
#define SMARTTEAM_HPP

#include "Team.hpp"

using namespace std;

namespace ariel{

    class SmartTeam : public Team
    {
        public:
            SmartTeam(Character *leader);
            void add(Character *member);
    };

}

#endif