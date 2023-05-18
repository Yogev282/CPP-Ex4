#ifndef TRAINEDNINJA_HPP
#define TRAINEDNINJA_HPP

#include "Ninja.hpp"
#include <string>

using namespace std;

namespace ariel{

    class TrainedNinja : public Ninja
    {
        public:
            TrainedNinja(string name, Point location);
            ~TrainedNinja() override;

        
        TrainedNinja(const TrainedNinja&) = default;  // Copy constructor
        TrainedNinja& operator=(const TrainedNinja&) = default;  // Copy assignment operator
        TrainedNinja(TrainedNinja&&) = default;  // Move constructor
        TrainedNinja& operator=(TrainedNinja&&) = default;  // Move assignment operator
    };

}

#endif
