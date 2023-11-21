#include "Dratini.h"

#include <string>
#include "../Pokemon.h"
#include "../Skill.h"
#include "../Element.h"

using namespace std;

Dratini::Dratini(string _name) : Pokemon(_name)
{
    specieName = "Dratini";
    pokemonElement = Element::WATER;
    maxHP = 41;
    currentHP = maxHP;

    Skill Wrap("Wrap", Element::NORMAL, 4, 10);
    Skill Aqua_Tail("Aqua Tail", Element::WATER, 3, 5);
    Skill Pulse("Pulse", Element::WATER, 13, 2);
    Skill Hyper_Beam("Hyper Beam", Element::NORMAL, 20, 1);

    skills.push_back(Wrap);
    skills.push_back(Aqua_Tail);
    skills.push_back(Pulse);
    skills.push_back(Hyper_Beam);
}