#ifndef CHARMANDER_H
#define CHARMANDER_H

#include <vector>
#include <string>

#include "../Element.h"
#include "../Skill.h"
#include "../Pokemon.h"

using namespace std;

class Charmander : public Pokemon
{
public:
    Charmander(string _name);
};

#endif