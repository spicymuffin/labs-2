#ifndef SKILL_H
#define SKILL_H

#include <vector>
#include <string>

#include "Element.h"

class Skill
{
public:
    Skill(string _name, int _skillElement, int _baseDamage, int _maxTries);
    int useSkill(int defenderElement);
    string getName() const;
    int getSkillElement() const;
    int getBaseDamage() const;
    int getMaxTries() const;
    int getTriesLeft() const;
    string getEffectivenessTypeName(int defenderElement) const;

private:
    string name;
    int skillElement;
    int baseDamage;
    int maxTries;
    int triesLeft;
};

#endif