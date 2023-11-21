#include "Element.h"

#include <vector>
#include <string>

using namespace std;

const int Element::UNDEFINED = -1;
const int Element::NORMAL = 0;
const int Element::GROUND = 1;
const int Element::ELECTRIC = 2;
const int Element::WATER = 3;
const int Element::GLASS = 4;
const int Element::FIRE = 5;

const int Element::EFFECTIVE_ATK = +0;
const int Element::SUPER_EFFECTIVE_ATK = +5;
const int Element::NOT_VERY_EFFECTIVE_ATK = -3;

int Element::effectivenessLookupTable[6][6] = {{EFFECTIVE_ATK, EFFECTIVE_ATK, EFFECTIVE_ATK, EFFECTIVE_ATK, EFFECTIVE_ATK, EFFECTIVE_ATK},
                                               {EFFECTIVE_ATK, EFFECTIVE_ATK, SUPER_EFFECTIVE_ATK, EFFECTIVE_ATK, NOT_VERY_EFFECTIVE_ATK, SUPER_EFFECTIVE_ATK},
                                               {EFFECTIVE_ATK, NOT_VERY_EFFECTIVE_ATK, NOT_VERY_EFFECTIVE_ATK, SUPER_EFFECTIVE_ATK, NOT_VERY_EFFECTIVE_ATK, EFFECTIVE_ATK},
                                               {EFFECTIVE_ATK, SUPER_EFFECTIVE_ATK, EFFECTIVE_ATK, NOT_VERY_EFFECTIVE_ATK, NOT_VERY_EFFECTIVE_ATK, SUPER_EFFECTIVE_ATK},
                                               {EFFECTIVE_ATK, NOT_VERY_EFFECTIVE_ATK, EFFECTIVE_ATK, SUPER_EFFECTIVE_ATK, NOT_VERY_EFFECTIVE_ATK, NOT_VERY_EFFECTIVE_ATK},
                                               {EFFECTIVE_ATK, EFFECTIVE_ATK, EFFECTIVE_ATK, NOT_VERY_EFFECTIVE_ATK, SUPER_EFFECTIVE_ATK, NOT_VERY_EFFECTIVE_ATK}};

int Element::getAtkEffectiveness(int attackElement, int defenceElement)
{
    return effectivenessLookupTable[attackElement][defenceElement];
}

string Element::getElementName(int element)
{
    switch (element)
    {
    case UNDEFINED:
        return "undefined";
        break;
    case NORMAL:
        return "normal";
    case GROUND:
        return "ground";
    case ELECTRIC:
        return "electric";
    case WATER:
        return "water";
    case GLASS:
        return "glass";
    case FIRE:
        return "fire";
    default:
        return "undefined";
        break;
    }
}