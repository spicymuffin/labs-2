#include "Pokemon.h"

#include <string>

using namespace std;

Pokemon::Pokemon(string _name)
{
    name = _name;
    specieName = "undefined specie";
    pokemonElement = Element::UNDEFINED;
    currentHP = -1;
    maxHP = -1;
}

Pokemon::Pokemon(string _name, string _specieName, int _pokemonElement, int _currentHP, int _maxHP)
{
    name = _name;
    specieName = _specieName;
    pokemonElement = _pokemonElement;
    currentHP = _currentHP;
    maxHP = _maxHP;
}

Pokemon::Pokemon(string _name, string _specieName, int _pokemonElement, int _currentHP, int _maxHP, vector<Skill> &_skills)
{
    name = _name;
    specieName = _specieName;
    pokemonElement = _pokemonElement;
    currentHP = _currentHP;
    maxHP = _maxHP;
    skills = _skills;
}

string Pokemon::getName() const
{
    return name;
}

int Pokemon::getSkillCnt() const
{
    return skills.size();
}

string Pokemon::getSpecieName() const
{
    return specieName;
}

int Pokemon::getPokemonElement() const
{
    return pokemonElement;
}
int Pokemon::getCurrentHP() const
{
    return currentHP;
}

Skill *Pokemon::getSkill(int skillIndex)
{
    return &skills[skillIndex];
}

int Pokemon::takeDamage(int damage)
{
    currentHP -= damage;
    return currentHP;
}