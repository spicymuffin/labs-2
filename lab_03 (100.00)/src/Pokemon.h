#ifndef POKEMON_H
#define POKEMON_H

#include <vector>
#include <string>

#include "Element.h"
#include "Skill.h"

using namespace std;

class Pokemon
{
public:
    Pokemon(string _name);
    Pokemon(string _name, string _specieName, int _pokemonElement, int _currentHP, int _maxHP);
    Pokemon(string _name, string _specieName, int _pokemonElement, int _currentHP, int _maxHP, vector<Skill> &_skills);
    string getName() const;
    string getSpecieName() const;
    int getPokemonElement() const;
    int getCurrentHP() const;
    Skill *getSkill(int skillIndex);
    int takeDamage(int damage);
    int getSkillCnt() const;

protected:
    string name;
    string specieName;
    int pokemonElement;
    int currentHP;
    int maxHP;
    vector<Skill> skills;
};

#endif