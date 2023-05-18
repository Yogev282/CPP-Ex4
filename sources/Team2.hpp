#ifndef TEAM2_HPP
#define TEAM2_HPP

#include "Team.hpp"

using namespace std;

namespace ariel{
   
    class Team2 : public Team
    {
        private:
            Character *leader;
            Character *member;
            
        public:
            Team2(Character *leader) : Team(leader) {};
            void add(Character *member) override 
            {
                if(currSize < capacity)
                {
                    if(member->inTeam)
                    {
                        throw runtime_error("Character is already in a team");
                    }
                    if(!member->isAlive())
                    {
                        throw runtime_error("Character is dead");
                    }
                    members[currSize] = member;
                    currSize++;
                }
                else
                {
                    throw runtime_error("Team is full");
                }
            }
        
    };

}

#endif