#include "Skill.h"

#include <string>

using namespace std;

Skill::Skill(string _name, int _skillElement, int _baseDamage, int _maxTries)
{
    name = _name;
    skillElement = _skillElement;
    baseDamage = _baseDamage;
    maxTries = _maxTries;
    triesLeft = _maxTries;
}

int Skill::useSkill(int defenderElement)
{
    triesLeft--;
    return baseDamage + Element::getAtkEffectiveness(skillElement, defenderElement);
}

string Skill::getEffectivenessTypeName(int defenderElement) const
{
    int effectivenessModifier = Element::getAtkEffectiveness(skillElement, defenderElement);
    if (effectivenessModifier == Element::EFFECTIVE_ATK)
    {
        return "effective";
    }
    else if (effectivenessModifier == Element::SUPER_EFFECTIVE_ATK)
    {
        return "super effective";
    }
    else if (effectivenessModifier == Element::NOT_VERY_EFFECTIVE_ATK)
    {
        return "not very effective";
    }
    else
    {
        __throw_runtime_error("effectiveness modifier unrecognized");
        exit(-1);
    }
}

string Skill::getName() const
{
    return name;
}

int Skill::getSkillElement() const
{
    return skillElement;
}

int Skill::getBaseDamage() const
{
    return baseDamage;
}

int Skill::getMaxTries() const
{
    return maxTries;
}

int Skill::getTriesLeft() const
{
    return triesLeft;
}
