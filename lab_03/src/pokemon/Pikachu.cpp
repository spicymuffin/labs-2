#include "Pikachu.h"

#include <string>
#include "../Pokemon.h"
#include "../Skill.h"
#include "../Element.h"

using namespace std;

Pikachu::Pikachu(string _name) : Pokemon(_name)
{
    specieName = "Pikachu";
    pokemonElement = Element::ELECTRIC;
    maxHP = 35;
    currentHP = maxHP;

    Skill Tackle("Tackle", Element::NORMAL, 4, 5);
    Skill Glass_Knot("Glass Knot", Element::GLASS, 8, 5);
    Skill Thunderbolt("Thunderbolt", Element::ELECTRIC, 10, 5);
    Skill Megabolt("Megabolt", Element::ELECTRIC, 15, 3);

    skills.push_back(Tackle);
    skills.push_back(Glass_Knot);
    skills.push_back(Thunderbolt);
    skills.push_back(Megabolt);
}