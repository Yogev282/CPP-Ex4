#include "Team.hpp"
#include <limits>

using namespace std;
using namespace ariel;

Team::Team(Character *leader)
{
    this->leader = leader;
    this->ninjas = new Ninja *[10];
    this->cowboys = new Cowboy *[10];
    leader->inTeam = true;
    if(leader->role == "Ninja")
    {
        this->ninjas[0] = (Ninja *)leader;
        this->currSizeN = 1;
        this->currSizeC = 0;
    }
    else
    {
        this->cowboys[0] = (Cowboy *)leader;
        this->currSizeC = 1;
        this->currSizeN = 0;
    }
}

Team::~Team()
{
    for (int i = 0; i < this->currSizeN; i++)
    {
        delete this->ninjas[i];
    }
    delete[] this->ninjas;

    for (int i = 0; i < this->currSizeC; i++)
    {
        delete this->cowboys[i];
    }
    delete[] this->cowboys;
}

void Team::add(Ninja *member)
{
    if(stillAlive() == this->capacity)
    {
        throw "Team is full";
    }
    if(member->inTeam)
    {
        throw "Character is already in a team";
    }

    this->ninjas[this->currSizeN] = member;
    this->currSizeN++;
    member->inTeam = true;
}

void Team::add(Cowboy *member)
{
    if(stillAlive() == this->capacity)
    {
        throw "Team is full";
    }
    if(member->inTeam)
    {
        throw "Character is already in a team";
    }

    this->cowboys[this->currSizeC] = member;
    this->currSizeC++;
    member->inTeam = true;
}


void Team::attack(Team *other)
{
    if(!this->leader->isAlive())
    {
        int min = std::numeric_limits<int>::max();
        Character *newLeader;
        // find new leader
        for(int i = 0; i < this->currSizeN; i++)
        {
            if(this->ninjas[i]->isAlive())
            {
                if(this->ninjas[i]->distance(this->leader) < min)
                {
                    min = this->ninjas[i]->distance(this->leader);
                    newLeader = this->ninjas[i];
                }
            }
        }
        for(int i = 0; i < this->currSizeC; i++)
        {
            if(this->cowboys[i]->isAlive())
            {
                if(this->cowboys[i]->distance(this->leader) < min)
                {
                    min = this->cowboys[i]->distance(this->leader);
                    newLeader = this->cowboys[i];
                }
            }
        }
    }
    

    // find closest enemy to the leader
    if(other->stillAlive() == 0)
    {
        return ;
    }
    Character *closestEnemy = findEnemy(other);

    // attack
    if(this->currSizeN > 0){
        for(int i = 0; i < this->currSizeN; i++)
        {
            if(this->ninjas[i]->isAlive())
            {
                if(!closestEnemy->isAlive()){
                    if(other->stillAlive() == 0)
                    {
                        throw "Enemy team are all dead";
                    }
                    else
                    {
                        closestEnemy = findEnemy(other);
                    }
                }
                this->ninjas[i]->slash(closestEnemy);
            }
        }
    }
    if(this->currSizeC > 0){
        for(int i = 0; i < this->currSizeC; i++)
        {
            if(this->cowboys[i]->isAlive())
            {
                if(!closestEnemy->isAlive()){
                    if(other->stillAlive() == 0)
                    {
                        throw "Enemy team are all dead";
                    }
                    else
                    {
                        closestEnemy = findEnemy(other);
                    }
                }
                this->cowboys[i]->shoot(closestEnemy);
            }
        }
    }
}

Character* Team::findEnemy(Team *other)
{
    int min = std::numeric_limits<int>::max();
    Character *closestEnemy;
    if(this -> currSizeN > 0){
        for(int i = 0; i < other->currSizeN; i++)
        {
            if(other->ninjas[i]->isAlive())
            {
                if(other->ninjas[i]->distance(other->leader) < min)
                {
                    min = other->ninjas[i]->distance(other->leader);
                    closestEnemy = other->ninjas[i];
                }
            }
        }
    }
    if(this -> currSizeC > 0){
        for(int i = 0; i < other->currSizeC; i++)
        {
            if(other->cowboys[i]->isAlive())
            {
                if(other->cowboys[i]->distance(other->leader) < min)
                {
                    min = other->cowboys[i]->distance(other->leader);
                    closestEnemy = other->cowboys[i];
                }
            }
        }
    }

    return closestEnemy;
}

int Team::stillAlive()
{
    int counter = 0;
    if(this->currSizeN > 0){
        for(int i = 0; i < this->currSizeN; i++)
        {
            if(this->ninjas[i]->isAlive())
            {
                counter++;
            }
        }
    }
    if(this->currSizeC > 0){
        for(int i = 0; i < this->currSizeC; i++)
        {
            if(this->cowboys[i]->isAlive())
            {
                
                counter++;
            }
        }
    }
    return counter;
}

void Team::print()
{   
    string printer = "";
    if(this->currSizeC > 0){
        for(int i = 0; i < this->currSizeN; i++)
        {
            printer += this->cowboys[i]->print() +  " *** ";
        }
    }
    if(this->currSizeN > 0){
        for(int i = 0; i < this->currSizeN; i++)
        {
            printer += this->ninjas[i]->print() +  " *** ";
        }
    }
    printf("%s\n", printer.c_str());
}