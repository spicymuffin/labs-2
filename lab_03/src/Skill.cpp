#include "Skill.h"

#include <string>

using namespace std;

Skill::Skill(string _name, int _skillElement, int _baseDamage, int _maxTries, int _triesLeft)
{
    name = _name;
    skillElement = _skillElement;
    baseDamage = _baseDamage;
    maxTries = _maxTries;

    if (_triesLeft == -1)
    {
        _triesLeft = _maxTries;
    }
}