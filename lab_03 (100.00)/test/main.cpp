#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
using namespace std;

// made Skill class
class Skill
{
private:
    string name;
    int type;
    int damage;
    int maxTry;
    int cTry;

public:
    Skill(string, int, int, int, int);
    string getName();
    int getType();
    int getDmg();
    int getMaxtry();
    void setCtry(int cTry);
    int getCtry();

    bool Usage()
    {
        if (cTry <= 0)
        {
            return false;
        }

        cTry -= 1;
        return true;
    }
};

Skill::Skill(string name, int type, int damage, int maxTry, int cTry)
{
    this->name = name;
    this->type = type;
    this->damage = damage;
    this->maxTry = maxTry;
    this->cTry = maxTry;
}

string Skill::getName()
{
    return this->name;
}
int Skill::getType()
{
    return this->type;
}
int Skill::getDmg()
{
    return this->damage;
}
int Skill::getMaxtry()
{
    return this->maxTry;
}
void Skill::setCtry(int cTry)
{
    this->cTry = cTry;
}
int Skill::getCtry()
{
    return this->cTry;
}
#define skillCount 4

class Pokemon
{
private:
    string name;
    int type;
    int maxHP;
    int cHP;
    vector<Skill> skills;

public:
    Pokemon(string, int, int, int, vector<Skill>);
    string getName();
    int getType();
    int getMaxhp();
    void setChp(int cHP);
    int getChp();
    vector<Skill> *getSkills();

    bool Damage(int damage)
    {
        cHP -= damage;
        return cHP > 0;
    }
};

Pokemon::Pokemon(string name, int type, int maxHP, int cHP, vector<Skill> skills)
{
    this->name = name;
    this->type = type;
    this->maxHP = maxHP;
    this->cHP = cHP;
    this->skills = skills;
}

string Pokemon::getName()
{
    return this->name;
}
int Pokemon::getType()
{
    return this->type;
}
int Pokemon::getMaxhp()
{
    return this->maxHP;
}
void Pokemon::setChp(int cHP)
{
    this->cHP = cHP;
}
int Pokemon::getChp()
{
    return this->cHP;
}
vector<Skill> *Pokemon::getSkills()
{
    return &skills;
}

const int typeNormal = 0;
const int typeGround = 1;
const int typeElectric = 2;
const int typeWater = 3;
const int typeGlass = 4;
const int typeFire = 5;

const int skillEffective = 0;
const int skillSuperEffective = 1;
const int skillNotEffective = 2;

int SkillEffectEval(int offense, int defense);
class Pokemon;
class Skill;

int Effectiveness(int offense, int defense)
{
    int table[6][6] = {
        {skillEffective, skillEffective, skillEffective, skillEffective, skillEffective, skillEffective},
        {skillEffective, skillEffective, skillSuperEffective, skillEffective, skillNotEffective, skillSuperEffective},
        {skillEffective, skillNotEffective, skillNotEffective, skillSuperEffective, skillNotEffective, skillEffective},
        {skillEffective, skillSuperEffective, skillEffective, skillNotEffective, skillNotEffective, skillSuperEffective},
        {skillEffective, skillNotEffective, skillEffective, skillSuperEffective, skillNotEffective, skillNotEffective},
        {skillEffective, skillEffective, skillEffective, skillNotEffective, skillSuperEffective, skillNotEffective}};
    return table[offense][defense];
}

Pokemon pokemonSpec[] = {
    Pokemon("Pikachu", typeElectric, 35, 35, {Skill("Tackle", typeNormal, 4, 5, 5), Skill("Glass Knot", typeGlass, 8, 5, 5), Skill("Thunderbolt", typeElectric, 10, 5, 5), Skill("Megabolt", typeElectric, 15, 3, 3)}),
    Pokemon("Dratini", typeWater, 41, 41, {Skill("Wrap", typeNormal, 4, 10, 10), Skill("Aqua Tail", typeWater, 3, 5, 5), Skill("Water Pulse", typeWater, 13, 2, 2), Skill("Hyper Beam", typeNormal, 20, 1, 1)}),
    Pokemon("Eevee", typeNormal, 55, 55, {Skill("Tackle", typeNormal, 4, 5, 5), Skill("Sand Attack", typeGround, 8, 3, 3), Skill("Bite", typeNormal, 12, 3, 3), Skill("Rain Dance", typeWater, 15, 1, 1)}),
    Pokemon("Charmander", typeFire, 39, 39, {Skill("Tackle", typeNormal, 4, 5, 5), Skill("Flamethrower", typeFire, 11, 5, 5), Skill("Dig", typeNormal, 7, 5, 5), Skill("Heat Wave", typeWater, 14, 5, 5)}),
    Pokemon("Palkia", typeWater, 90, 90, {Skill("Hydro Pump", typeWater, 12, 10, 10), Skill("Earth Power", typeGround, 15, 10, 10), Skill("Surf", typeWater, 13, 10, 10), Skill("Spatial Rend", typeNormal, 30, 10, 10)}),
};

void battlePage(Pokemon &left, Pokemon &right, bool player1)
{
    string typeStr[] = {"Normal", "Ground", "Electric", "Water", "Glass", "Fire"};

    cout << "+" << string(61, '-') << "+" << endl
         << "| " << setw(59) << std::left << "2023148083 Huh Jaeho Computer Science"
         << " |" << endl
         << "+" << string(61, '-') << "+" << endl
         << "| " << setw(28) << std::left << (left.getName() + (player1 ? " (*)" : "")) << " | " << setw(28) << std::left
         << (right.getName() + (!player1 ? " (*)" : "")) << " |" << endl
         << "| " << setw(28) << std::left << ("Type: " + typeStr[left.getType()]) << " | " << setw(28) << std::left
         << ("Type: " + typeStr[right.getType()]) << " |" << endl
         << "| " << setw(28) << std::left << ("HP: " + to_string(left.getChp())) << " | " << setw(28) << std::left
         << ("HP: " + to_string(right.getChp())) << " |" << endl
         << "+" << string(61, '-') << "+" << endl;

    for (int i = 0; i < skillCount; ++i)
    {
        cout << "| (" << i << ") " << setw(24) << std::left << (*(left.getSkills()))[i].getName() << " | (" << i << ") " << setw(24) << std::left
             << (*(right.getSkills()))[i].getName() << " |" << endl
             << "| " << setw(28) << std::left << ("    - Type: " + typeStr[(*(left.getSkills()))[i].getType()]) << " | " << setw(28) << std::left
             << ("    - Type: " + typeStr[(*(right.getSkills()))[i].getType()]) << " |" << endl
             << "| " << setw(28) << std::left << ("    - Damage: " + to_string((*(left.getSkills()))[i].getDmg())) << " | " << setw(28)
             << std::left << ("    - Damage: " + to_string((*(right.getSkills()))[i].getDmg())) << " |" << endl
             << "| " << setw(28) << std::left
             << ("    - Count: " + to_string((*(left.getSkills()))[i].getCtry()) + "(" + to_string((*(left.getSkills()))[i].getMaxtry()) + ")") << " | " << setw(28)
             << std::left
             << ("    - Count: " + to_string((*(right.getSkills()))[i].getCtry()) + "(" + to_string((*(right.getSkills()))[i].getMaxtry()) + ")")
             << " |" << endl;
    }
    cout << "+" << string(61, '-') << "+" << endl;
}

int main(int argc, char *argv[])
{
    int player1PokeNo, player2PokeNo;
    cout << "Choose a Pokemon(0~4): ";
    cin >> player1PokeNo;
    cout << "Choose another Pokemon(0~4): ";
    cin >> player2PokeNo;

    if (player1PokeNo == player2PokeNo)
    {
        cout << "You have to choose Pokemons different from each other." << endl;
        return 0;
    }

    Pokemon player1pokemon = pokemonSpec[player1PokeNo], player2pokemon = pokemonSpec[player2PokeNo];
    Pokemon *offender, *defender;
    bool player1 = true;

    int skillIndex;
    Skill *offense;
    int effect;
    int calcDamage;

    for (;; player1 = !player1)
    {
        offender = &(player1 ? player1pokemon : player2pokemon);
        defender = &(player1 ? player2pokemon : player1pokemon);

        battlePage(player1pokemon, player2pokemon, player1);

        cout << "Choose a skill(0~3): ";
        cin >> skillIndex;

        offense = &((*(offender->getSkills()))[skillIndex]);
        effect = Effectiveness(offense->getType(), defender->getType());

        if (!(offense->Usage()))
        {
            cout << offender->getName() << " failed to perform " << offense->getName() << "." << endl
                 << endl;
            continue;
        }

        cout << offender->getName() << " used " << offense->getName() << "." << endl;

        switch (effect)
        {
        case skillSuperEffective:
            cout << "The attack was super effective." << endl
                 << endl;
            calcDamage = offense->getDmg() + 5;
            break;

        case skillEffective:
            cout << "The attack was effective." << endl
                 << endl;
            calcDamage = offense->getDmg();
            break;

        case skillNotEffective:
            cout << "The attack was not very effective." << endl
                 << endl;
            calcDamage = offense->getDmg() - 3;
            break;

        default:
            break;
        }

        if (!defender->Damage(calcDamage))
        {
            cout << string(63, '=') << endl
                 << "Match Result: " << offender->getName() << " defeats " << defender->getName() << endl;
            break;
        }
    }

    return 0;
}