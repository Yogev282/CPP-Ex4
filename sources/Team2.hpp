#ifndef TEAM2_HPP
#define TEAM2_HPP

#include "Team.hpp"

using namespace std;

namespace ariel{
   
    class Team2 : public Team
    {
        public:
            Team2(Character *leader) : Team(leader) {};
            void add(Character *member) override
            {
                if(currSize < capacity)
                {   
                    if(member->inTeam) // check if member is already in a team
                    {
                        throw runtime_error("Character is already in a team");
                    }
                    if(!member->isAlive()) // check if member is alive
                    {
                        throw runtime_error("Character is dead");
                    }
                    members[currSize] = member;
                    currSize++;
                }
                else // team is full
                {
                    throw runtime_error("Team is full");
                }
            }
        
    };

}

#endif