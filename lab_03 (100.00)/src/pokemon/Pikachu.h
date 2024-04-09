#ifndef PIKACHU_H
#define PIKACHU_H

#include <vector>
#include <string>

#include "../Element.h"
#include "../Skill.h"
#include "../Pokemon.h"

using namespace std;

class Pikachu : public Pokemon
{
public:
    Pikachu(string _name);
};

#endif