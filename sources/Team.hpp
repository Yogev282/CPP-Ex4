#ifndef TEAM_HPP
#define TEAM_HPP

#include "Point.hpp"
#include "Character.hpp"
#include "Ninjas.hpp"
#include "Cowboy.hpp"
#include <string>

const int TEAM_CAPACITY = 10;

using namespace std;

namespace ariel
{
    class Team
    {
    public:
        Ninja *(*ninjas);
        Cowboy *(*cowboys);
        Character *leader;
        int capacity = TEAM_CAPACITY;
        int currSizeN;
        int currSizeC;


    // public:
        Team(Character *leader);
        virtual ~Team();
        void add(Ninja *member);
        void add(Cowboy *member);
        void attack(Team *other);
        Character* findEnemy(Team *other);
        int stillAlive();
        Character* getLeader() const {return leader;}
        void print();

        
        Team(const Team&) = default;  // Copy constructor
        Team& operator=(const Team&) = default;  // Copy assignment operator
        Team(Team&&) = default;  // Move constructor
        Team& operator=(Team&&) = default;  // Move assignment operator
        
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