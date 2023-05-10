#include "doctest.h"
#include <stdexcept>
#include "sources/Point.hpp"
#include "sources/Character.hpp"
#include "sources/Team.hpp"
#include "sources/Cowboy.hpp"
#include "sources/Ninjas.hpp"
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


TEST_CASE("Character") {
    Point a(0, 0), b(1, 1), c(2, 2), d(3, 3);

    YountNinja *yNinja = new YountNinja("young", a);
    TrainedNinja *tNinja = new TrainedNinja("trained", b);
    OldNinja *oNinja = new OldNinja("old", c);
    Cowboy *cowboy = new Cowboy("cowboy", d);
    
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
    YountNinja *young = new YountNinja("young", e);
    Cowboy *cboy = new Cowboy("cowboy", f);

    CHECK(cboy->isAlive());

    int health = young->getHealth();
    cboy->shoot(young);
    CHECK(young->getHealth() == health - 10);
    young->slash(cboy);
    CHECK(cboy->getHealth() == 0);
    CHECK(!cboy->isAlive());
}   


TEST_CASE("Teams"){
    Point a(0, 0), b(1, 1), c(2, 2), d(3, 3);

    YountNinja *yNinja = new YountNinja("young", d);
    TrainedNinja *tNinja = new TrainedNinja("trained", b);
    OldNinja *oNinja = new OldNinja("old", c);
    Cowboy *cowboy = new Cowboy("cowboy", a);

    Team teamA(yNinja);
    Team teamB(cowboy);

    teamB.add(tNinja);
    teamB.add(oNinja);
    CHECK_THROWS(teamA.add(yNinja));
    CHECK_THROWS(teamB.add(yNinja));

    teamA.attack(&teamB);
    CHECK(!cowboy->isAlive());
    CHECK(teamB.stillAlive() == 2);
    CHECK(teamA.stillAlive() == 1);
    CHECK(teamB.getLeader() == tNinja);
    CHECK(teamA.getLeader() == yNinja);

}
