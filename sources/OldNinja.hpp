#ifndef OLDNINJA_HPP
#define OLDNINJA_HPP

#include "Ninja.hpp"
#include <string>

using namespace std;

namespace ariel{

    class OldNinja : public Ninja
    {
        public:
            OldNinja(string name, Point location);
            // ~OldNinja() override;

        
            // OldNinja(const OldNinja&) = default;  // Copy constructor
            // OldNinja& operator=(const OldNinja&) = default;  // Copy assignment operator
            // OldNinja(OldNinja&&) = default;  // Move constructor
            // OldNinja& operator=(OldNinja&&) = default;  // Move assignment operator
    };
    
}

#endif
