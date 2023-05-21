
#include "SmartTeam.hpp"
#include "Team.hpp"
#include <string>
#include <iostream>

using namespace std;

namespace ariel
{
    // attacking by the user's choice
    void SmartTeam::attack(Team *other)
    {
        cout << "Team positions are: " << endl;
        this->print();
        cout << "Other team positions are: " << endl;
        other->print();

        for(int i = 0; i < this->currSize; i++)
        {
            cout << "Attacking with " << this->members[i]->getName() << endl;
            cout << "Enemy to attack is: (enter a name)" << endl;
            Character *enemy = this->findEnemy(other);
            this->members[i]->attack(enemy);
        }
    }

    // get an character from enemy team to attack by a name from the user
    Character* SmartTeam::findEnemy(Team *other)
    {
    
        string name;
        cin >> name;

        while(true)
        {
            for(int i = 0; i < other->currSize; i++)
            {
                if(other->members[i]->getName() == name)
                {
                    return other->members[i];
                }
            }
            cout << "Enemy not found, please enter a valid name" << endl;
            cin >> name;
        }
    }

}