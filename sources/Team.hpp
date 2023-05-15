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
        Ninja *(*ninjas);
        Cowboy *(*cowboys);
        Character *leader;
        int capacity = 10;
        int currSizeN;
        int currSizeC;


    public:
        Team(Character *leader);
        ~Team();
        void add(Ninja *member);
        void add(Cowboy *member);
        void attack(Team *other);
        Character* findEnemy(Team *other);
        int stillAlive();
        Character* getLeader(){return leader;}
        void print();
        
    };


    // class Team2 : public Team
    // {
    //     public:
    //         Team2(Character *leader);
    //         void add(Character *member);
       
    // };


    // class SmartTeam : public Team
    // {
    //     public:
    //         SmartTeam(Character *leader);
    //         void add(Character *member);
    // };

}


#endif