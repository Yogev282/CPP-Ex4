#ifndef TEAM_HPP
#define TEAM_HPP

#include "Point.hpp"
#include "Character.hpp"
#include "Ninjas.hpp"
#include "Cowboy.hpp"
#include <string>

using namespace std;

namespace ariel
{
    class Team
    {
    protected:
        Character *(*members);
        Character *leader;
        int currSize;
        int capacity = 10;

    public:
        Team(Character *leader);
        ~Team();
        virtual void add(Character *member);
        void attack(Team *other);
        int stillAlive();
        Character* getLeader();
        void print();
    };


    class Team2 : public Team
    {
        void add(Character *member);
    };


    class SmartTeam : public Team
    {
        void add(Character *member);
    };

}


#endif