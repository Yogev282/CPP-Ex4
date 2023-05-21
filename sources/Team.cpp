#include "Team.hpp"
#include <limits>

using namespace std;

namespace ariel{

    Team::Team(Character *leader)
    {
        if(leader->inTeam)
        {

            throw runtime_error("Character is already in a team");
        }
        this->leader = leader;
        this->members = new Character*[TEAM_CAPACITY]; 
        this->capacity = TEAM_CAPACITY;
        this->currSize = 1;
        this->members[0] = leader;
        // mark leader as in team
        leader->inTeam = true;
    }
  
    
    Team::~Team()
    {
        for(int i = 0; i < this->currSize; i++)
        {
            // delete all members
            delete this->members[i];
        }
        // delete the array
        delete[] this->members; 
    }

    void Team::add(Character *member)
    {
        // max size of team is 10
        if(this->currSize == this->capacity)
        {
            throw runtime_error("Team is full");
        }
        // check if member is already in a team
        if(member->inTeam)
        {
            throw runtime_error("Character is already in a team");
        }
        // check if member is alive
        if(!member->isAlive())
        {
            throw runtime_error("Character is dead");
        }
        this->members[this->currSize++] = member;
        member->inTeam = true; // mark member as in team
        this->sort(); // sort the members by their roles
    }

    void Team::attack(Team *other)
    {
        // check if there are alive members in the team
        if(this->stillAlive() == 0)
        {
            throw runtime_error("Team is dead");
        }
        // if leader is dead, find new leader by distance from the old leader
        if(!this->leader->isAlive())
        {
            int min = std::numeric_limits<int>::max();
            Character *newLeader;
            // find new leader
            for(int i = 0; i < this->currSize; i++)
            {
                if(this->members[i]->isAlive())
                {
                    if(this->members[i]->distance(this->leader) < min)
                    {
                        min = this->members[i]->distance(this->leader);
                        newLeader = this->members[i];
                    }
                }
            }
            this->leader = newLeader;
        }

        if(other == nullptr)
        {
            throw invalid_argument("nullptr");
        }
        

        // find closest enemy to the leader
        if(other->stillAlive() == 0)
        {
            throw runtime_error("Enemy team are all dead");
        }
        Character *closestEnemy = this->findEnemy(other);

        // attack
        
        for(int i = 0; i < this->currSize; i++)
        {
            if(this->members[i]->isAlive())
            {
                if(!closestEnemy->isAlive()){
                    if(other->stillAlive() == 0)
                    {
                        return; // enemy team is dead
                    }
                    else
                    {
                        closestEnemy = this->findEnemy(other);
                    }
                }
                // if the member is a ninja and the enemy is far, move to the enemy
                if(this->members[i]->getRole() == "Ninja" && this->members[i]->distance(closestEnemy) > 1)
                {
                    ((Ninja*)this->members[i])->move(closestEnemy);
                }
                else
                {
                    this->members[i]->attack(closestEnemy);
                }
            }
        }
    
    }

    Character* Team::findEnemy(Team *other)
    {
        int min = std::numeric_limits<int>::max();
        Character *closestEnemy;
        
        for(int i = 0; i < other->currSize; i++)
        {
            if(other->members[i]->isAlive())
            {
                if(other->members[i]->distance(this->leader) < min)
                {
                    min = other->members[i]->distance(this->leader);
                    closestEnemy = other->members[i];
                }
            }
        }
        
        return closestEnemy;
    }

    int Team::stillAlive()
    {
        int counter = 0;
        for(int i = 0; i < this->currSize; i++)
        {
            if(this->members[i]->isAlive())
            {
                counter++;
            }
        }
        return counter;
    }

    void Team::print()
    {   
        string printer = "";
        if(this->currSize > 0){
            for(int i = 0; i < this->currSize; i++)
            {
                printer += this->members[i]->print() +  "\n";
            }
        }
        printf("%s\n", printer.c_str());
    }

    // sort the members by their roles with bubble sort
    void Team::sort(){
        for(int i = 0; i < this->currSize ; i++ ){
            for(int j = i + 1; j < this->currSize ; j++ ){
                if(this->members[i]->compare(this->members[j]) == 1){
                    Character *temp = this->members[i];
                    this->members[i] = this->members[j];
                    this->members[j] = temp;
                }
            }
        }
    }
}