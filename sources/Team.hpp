#ifndef TEAM_HPP
#define TEAM_HPP

#include "Point.hpp"
#include "Character.hpp"
#include "OldNinja.hpp"
#include "YoungNinja.hpp"
#include "TrainedNinja.hpp"
#include "Cowboy.hpp"
#include <string>
#include <stdexcept>

const int TEAM_CAPACITY = 10;

using namespace std;

namespace ariel
{

    class Team
    {
        public:
            Character *(*members);
            Character *leader;
            int capacity = TEAM_CAPACITY;
            int currSize;


        // public:
            Team(Character *leader);
            virtual ~Team();
            virtual void add(Character *member);
            void attack(Team *other);
            Character* findEnemy(Team *other);
            int stillAlive();
            Character* getLeader() const {return leader;}
            void sort();
            void print();

            
            Team(const Team&) = default;  // Copy constructor
            Team& operator=(const Team&) = default;  // Copy assignment operator
            Team(Team&&) = default;  // Move constructor
            Team& operator=(Team&&) = default;  // Move assignment operator
        
    };

}

#endif