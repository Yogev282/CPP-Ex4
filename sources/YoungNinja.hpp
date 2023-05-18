#ifndef YOUNGNINJA_HPP
#define YOUNGNINJA_HPP

#include "Ninja.hpp"
#include <string>

using namespace std;

namespace ariel{

    class YoungNinja : public Ninja
    {
        public:
            YoungNinja(string name, Point location);
            ~YoungNinja() override;

        
        YoungNinja(const YoungNinja&) = default;  // Copy constructor
        YoungNinja& operator=(const YoungNinja&) = default;  // Copy assignment operator
        YoungNinja(YoungNinja&&) = default;  // Move constructor
        YoungNinja& operator=(YoungNinja&&) = default;  // Move assignment operator
    };

}

#endif
