#include "doctest.h"
#include <stdexcept>
#include "sources/Point.hpp"
#include "sources/Character.hpp"
#include "sources/Team.hpp"
#include "sources/Team2.hpp"
#include "sources/Cowboy.hpp"
#include "sources/Ninja.hpp"
#include <math.h>

using namespace std;
using namespace ariel;


TEST_CASE("Distance between points") {
    Point a(17.6, -2.2),b(-15, 33);
    CHECK(a.distance(b) == b.distance(a));
    Point c(0, 0), d(1, 1);
    CHECK(c.distance(d) == sqrt(2));
    CHECK(d.distance(c) == sqrt(2));
    CHECK(c.distance(c) == 0);
}

TEST_CASE("if range > 1 , ninja should miss"){
    OldNinja *ninja = new OldNinja("ninja", Point(0, 0));
    Cowboy *cowboy = new Cowboy("cowboy", Point(0, 2));
    CHECK(cowboy->getHealth() == 110);
    ninja->slash(cowboy);
    CHECK(cowboy->getHealth() == 110);

}


TEST_CASE("Character") {
    Point a(0, 0), b(1, 1), c(2, 2), d(3, 3);

    YoungNinja *yNinja = new YoungNinja("young", a);
    TrainedNinja *tNinja = new TrainedNinja("trained", b);
    OldNinja *oNinja = new OldNinja("old", c);
    Cowboy *cowboy = new Cowboy("cowboy", d);
    
    // checking all character intial values
    CHECK(yNinja->isAlive());
    CHECK(tNinja->isAlive());
    CHECK(oNinja->isAlive());

    CHECK(yNinja->getAgility() > tNinja->getAgility());
    CHECK(yNinja->getAgility() > oNinja->getAgility());
    CHECK(tNinja->getAgility() > oNinja->getAgility());

    CHECK(yNinja->getHealth() < tNinja->getHealth());
    CHECK(yNinja->getHealth() < oNinja->getHealth());
    CHECK(tNinja->getHealth() < oNinja->getHealth());
    CHECK(cowboy->getHealth() < yNinja->getHealth());

    CHECK(yNinja->distance(tNinja) == tNinja->distance(yNinja));
    CHECK(yNinja->distance(oNinja) == oNinja->distance(yNinja));
    CHECK(tNinja->distance(oNinja) == oNinja->distance(tNinja));
    CHECK(yNinja->distance(cowboy) == cowboy->distance(yNinja));

    CHECK(yNinja->distance(tNinja) == tNinja->distance(oNinja));
    CHECK(yNinja->distance(tNinja) == oNinja->distance(cowboy));

    Point e(0, 0), f(1, 0);
    YoungNinja *young = new YoungNinja("young", e);
    Cowboy *cboy = new Cowboy("cowboy", f);

    CHECK(cboy->isAlive());

    int health = young->getHealth();
    cboy->shoot(young);
    CHECK(young->getHealth() == health - 10);
    for(int i = 0; i < 3; i++){
        young->slash(cboy);
    }
    CHECK(cboy->getHealth() == 0);
    CHECK(!cboy->isAlive());
}   


TEST_CASE("Teams"){
    Point a(0, 0), b(1, 1), c(2, 2), d(3, 3);

    YoungNinja *yNinja = new YoungNinja("young", d);
    TrainedNinja *tNinja = new TrainedNinja("trained", b);
    OldNinja *oNinja = new OldNinja("old", c);
    Cowboy *cowboy = new Cowboy("cowboy", a);

    Team teamA(yNinja);
    Team teamB(cowboy);

    teamB.add(tNinja);
    teamB.add(oNinja);

    // cant add character to a same team twice or to 2 teams
    CHECK_THROWS(teamA.add(yNinja));
    CHECK_THROWS(teamB.add(yNinja));

    teamA.attack(&teamB);
    CHECK(!cowboy->isAlive());
    CHECK(teamB.stillAlive() == 2);
    CHECK(teamA.stillAlive() == 1);
    // teamB changed leader to the closest character to the old leader
    CHECK(teamB.getLeader() == tNinja);
    CHECK(teamA.getLeader() == yNinja);

}

TEST_CASE("Character attack himself"){
    Cowboy *cowboy = new Cowboy("cowboy", Point(0, 0));
    CHECK_THROWS(cowboy->shoot(cowboy));

    YoungNinja *yNinja = new YoungNinja("young", Point(0, 0));
    CHECK_THROWS(yNinja->slash(yNinja));
}

TEST_CASE("Team attack himself"){
    YoungNinja *yNinja = new YoungNinja("young", Point(0, 0));
    Team teamA(yNinja);
    CHECK_THROWS(teamA.attack(&teamA));
}

TEST_CASE("more than 10 in a team shouldnt throw"){
    YoungNinja *yNinja1 = new YoungNinja("young", Point(0, 0));
    YoungNinja *yNinja2 = new YoungNinja("young", Point(0, 0));
    YoungNinja *yNinja3 = new YoungNinja("young", Point(0, 0));
    YoungNinja *yNinja4 = new YoungNinja("young", Point(0, 0));
    YoungNinja *yNinja5 = new YoungNinja("young", Point(0, 0));
    YoungNinja *yNinja6 = new YoungNinja("young", Point(0, 0));
    YoungNinja *yNinja7 = new YoungNinja("young", Point(0, 0));
    YoungNinja *yNinja8 = new YoungNinja("young", Point(0, 0));
    YoungNinja *yNinja9 = new YoungNinja("young", Point(0, 0));
    YoungNinja *yNinja10 = new YoungNinja("young", Point(0, 0));
    YoungNinja *yNinja11 = new YoungNinja("young", Point(0, 0));

    Team teamA(yNinja1);
    teamA.add(yNinja2);
    teamA.add(yNinja3);
    teamA.add(yNinja4);
    teamA.add(yNinja5);
    teamA.add(yNinja6);
    teamA.add(yNinja7);
    teamA.add(yNinja8);
    teamA.add(yNinja9);
    teamA.add(yNinja10);
    CHECK_NOTHROW(teamA.add(yNinja11));
}