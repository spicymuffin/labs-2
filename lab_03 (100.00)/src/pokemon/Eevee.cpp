#include "Eevee.h"

#include <string>
#include "../Pokemon.h"
#include "../Skill.h"
#include "../Element.h"

using namespace std;

Eevee::Eevee(string _name) : Pokemon(_name)
{
    specieName = "Eevee";
    pokemonElement = Element::NORMAL;
    maxHP = 55;
    currentHP = maxHP;

    Skill Tackle("Tackle", Element::NORMAL, 4, 5);
    Skill Sand_Attack("Sand Attack", Element::GROUND, 8, 3);
    Skill Bite("Bite", Element::NORMAL, 12, 3);
    Skill Rain_Dance("Rain Dance", Element::WATER, 15, 1);

    skills.push_back(Tackle);
    skills.push_back(Sand_Attack);
    skills.push_back(Bite);
    skills.push_back(Rain_Dance);
}