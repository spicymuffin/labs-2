#ifndef ELEMENT_H
#define ELEMENT_H

#include <vector>
#include <string>

using namespace std;

class Element
{
public:
    static const int UNDEFINED;
    static const int NORMAL;
    static const int GROUND;
    static const int ELECTRIC;
    static const int WATER;
    static const int GLASS;
    static const int FIRE;

    static const int EFFECTIVE_ATK;
    static const int SUPER_EFFECTIVE_ATK;
    static const int NOT_VERY_EFFECTIVE_ATK;

    static int getAtkEffectiveness(int attackElement, int defenceElement);

    static string getElementName(int element);

private:
    // first index - attack, second - defence
    static int effectivenessLookupTable[6][6];
};

#endif