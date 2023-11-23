#include "Charmander.h"

#include <string>
#include "../Pokemon.h"
#include "../Skill.h"
#include "../Element.h"

using namespace std;

Charmander::Charmander(string _name) : Pokemon(_name)
{
    specieName = "Charmander";
    pokemonElement = Element::FIRE;
    maxHP = 39;
    currentHP = maxHP;

    Skill Tackle("Tackle", Element::NORMAL, 4, 5);
    Skill Flamethrower("Flamethrower", Element::FIRE, 11, 5);
    Skill Dig("Dig", Element::GROUND, 7, 5);
    Skill Heat_Wave("Heat Wave", Element::FIRE, 14, 5);

    skills.push_back(Tackle);
    skills.push_back(Flamethrower);
    skills.push_back(Dig);
    skills.push_back(Heat_Wave);
}