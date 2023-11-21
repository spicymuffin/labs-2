#ifndef SKILL_H
#define SKILL_H

#include <vector>
#include <string>

#include "Element.h"

class Skill
{
public:
    Skill(string _name, int _skillElement, int _baseDamage, int _maxTries, int _triesLeft = -1);

private:
    string name;
    int skillElement;
    int baseDamage;
    int maxTries;
    int triesLeft;
};

#endif