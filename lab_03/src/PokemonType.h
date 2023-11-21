#ifndef POKEMONTYPE_H
#define POKEMONTYPE_H

#include <vector>
#include <string>

using namespace std;

class PokemonType
{
public:
    static const int NORMAL = 0;
    static const int GROUND = 0;
    static const int ELECTRIC = 0;
    static const int WATER = 0;
    static const int GLASS = 0;
    static const int FIRE = 0;

    static const int EFFECTIVE_ATK = +0;
    static const int SUPER_EFFECTIVE_ATK = +5;
    static const int NOT_VERY_EFFECTIVE_ATK = -3;

    static int getEffectiveness();

private:
    // first index - attack, second - defence
    int effectivenessLookupTable[6][6] = {{EFFECTIVE_ATK, EFFECTIVE_ATK, EFFECTIVE_ATK, EFFECTIVE_ATK, EFFECTIVE_ATK, EFFECTIVE_ATK},
                                          {EFFECTIVE_ATK, EFFECTIVE_ATK, SUPER_EFFECTIVE_ATK, EFFECTIVE_ATK, NOT_VERY_EFFECTIVE_ATK, SUPER_EFFECTIVE_ATK},
                                          {EFFECTIVE_ATK, NOT_VERY_EFFECTIVE_ATK, NOT_VERY_EFFECTIVE_ATK, SUPER_EFFECTIVE_ATK, NOT_VERY_EFFECTIVE_ATK, EFFECTIVE_ATK},
                                          {EFFECTIVE_ATK, SUPER_EFFECTIVE_ATK, EFFECTIVE_ATK, NOT_VERY_EFFECTIVE_ATK, NOT_VERY_EFFECTIVE_ATK, SUPER_EFFECTIVE_ATK},
                                          {EFFECTIVE_ATK, NOT_VERY_EFFECTIVE_ATK, EFFECTIVE_ATK, SUPER_EFFECTIVE_ATK, NOT_VERY_EFFECTIVE_ATK, NOT_VERY_EFFECTIVE_ATK},
                                          {EFFECTIVE_ATK, EFFECTIVE_ATK, EFFECTIVE_ATK, NOT_VERY_EFFECTIVE_ATK, SUPER_EFFECTIVE_ATK, NOT_VERY_EFFECTIVE_ATK}};
};

#endif