#ifndef EEVEE_H
#define EEVEE_H

#include <vector>
#include <string>

#include "../Element.h"
#include "../Skill.h"
#include "../Pokemon.h"

using namespace std;

class Eevee : public Pokemon
{
public:
    Eevee(string _name);
};

#endif