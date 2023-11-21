#include "Palkia.h"

#include <string>
#include "../Pokemon.h"
#include "../Skill.h"
#include "../Element.h"

using namespace std;

Palkia::Palkia(string _name) : Pokemon(_name)
{
    specieName = "Palkia";
    pokemonElement = Element::WATER;
    maxHP = 90;
    currentHP = maxHP;

    Skill Hydro_Pump("Hydro Pump", Element::WATER, 12, 10);
    Skill Earth_Power("Earth Power", Element::GROUND, 15, 10);
    Skill Surf("Surf", Element::WATER, 13, 10);
    Skill Spatial_Rend("Spatial Rend", Element::NORMAL, 30, 10);

    skills.push_back(Hydro_Pump);
    skills.push_back(Earth_Power);
    skills.push_back(Surf);
    skills.push_back(Spatial_Rend);
}