/**
 * @file main.cpp
 * @author Luigi Cussigh (luigicussigh59@gmail.com)
 * @brief a VERY overkill assignment 3 submission
 * @version 0.1
 * @date 2023-11-23
 */

#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <cstdlib>

using namespace std;

#pragma region class declarations

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

#pragma region pokemon declarations
class Charmander : public Pokemon
{
public:
    Charmander(string _name);
};

class Dratini : public Pokemon
{
public:
    Dratini(string _name);
};

class Eevee : public Pokemon
{
public:
    Eevee(string _name);
};

class Palkia : public Pokemon
{
public:
    Palkia(string _name);
};

class Pikachu : public Pokemon
{
public:
    Pikachu(string _name);
};
#pragma endregion

#pragma endregion

#pragma region class implementations

#pragma region Skill
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

#pragma endregion

#pragma region Pokemon
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
#pragma endregion

#pragma region Element
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
        return "Normal";
    case GROUND:
        return "Ground";
    case ELECTRIC:
        return "Electric";
    case WATER:
        return "Water";
    case GLASS:
        return "Glass";
    case FIRE:
        return "Fire";
    default:
        return "undefined";
        break;
    }
}
#pragma endregion

#pragma region pokemons
#pragma region Charmander
Charmander::Charmander(string _name) : Pokemon(_name)
{
    specieName = "Charmander";
    pokemonElement = Element::FIRE;
    maxHP = 39;
    currentHP = maxHP;

    Skill Tackle("Tackle", Element::NORMAL, 4, 5);
    Skill Flamethrower("Flamethrower", Element::FIRE, 11, 5);
    Skill Dig("Dig", Element::GROUND, 7, 5);
    Skill Heat_Wave("Heat Wave", Element::FIRE, 14, 5);

    skills.push_back(Tackle);
    skills.push_back(Flamethrower);
    skills.push_back(Dig);
    skills.push_back(Heat_Wave);
}
#pragma endregion
#pragma region Dratini
Dratini::Dratini(string _name) : Pokemon(_name)
{
    specieName = "Dratini";
    pokemonElement = Element::WATER;
    maxHP = 41;
    currentHP = maxHP;

    Skill Wrap("Wrap", Element::NORMAL, 4, 10);
    Skill Aqua_Tail("Aqua Tail", Element::WATER, 3, 5);
    Skill Pulse("Pulse", Element::WATER, 13, 2);
    Skill Hyper_Beam("Hyper Beam", Element::NORMAL, 20, 1);

    skills.push_back(Wrap);
    skills.push_back(Aqua_Tail);
    skills.push_back(Pulse);
    skills.push_back(Hyper_Beam);
}
#pragma endregion
#pragma region Eevee
Eevee::Eevee(string _name) : Pokemon(_name)
{
    specieName = "Eevee";
    pokemonElement = Element::NORMAL;
    maxHP = 55;
    currentHP = maxHP;

    Skill Tackle("Tackle", Element::NORMAL, 4, 5);
    Skill Sand_Attack("Sand Attack", Element::GROUND, 8, 3);
    Skill Bite("Bite", Element::NORMAL, 12, 3);
    Skill Rain_Dance("Rain Dance", Element::WATER, 15, 1);

    skills.push_back(Tackle);
    skills.push_back(Sand_Attack);
    skills.push_back(Bite);
    skills.push_back(Rain_Dance);
}
#pragma endregion
#pragma region Palkia
Palkia::Palkia(string _name) : Pokemon(_name)
{
    specieName = "Palkia";
    pokemonElement = Element::WATER;
    maxHP = 90;
    currentHP = maxHP;

    Skill Hydro_Pump("Hydro Pump", Element::WATER, 12, 10);
    Skill Earth_Power("Earth Power", Element::GROUND, 15, 10);
    Skill Surf("Surf", Element::WATER, 13, 10);
    Skill Spatial_Rend("Spatial Rend", Element::NORMAL, 30, 10);

    skills.push_back(Hydro_Pump);
    skills.push_back(Earth_Power);
    skills.push_back(Surf);
    skills.push_back(Spatial_Rend);
}
#pragma endregion
#pragma region Pikachu
Pikachu::Pikachu(string _name) : Pokemon(_name)
{
    specieName = "Pikachu";
    pokemonElement = Element::ELECTRIC;
    maxHP = 35;
    currentHP = maxHP;

    Skill Tackle("Tackle", Element::NORMAL, 4, 5);
    Skill Glass_Knot("Glass Knot", Element::GLASS, 8, 5);
    Skill Thunderbolt("Thunderbolt", Element::ELECTRIC, 10, 5);
    Skill Megabolt("Megabolt", Element::ELECTRIC, 15, 3);

    skills.push_back(Tackle);
    skills.push_back(Glass_Knot);
    skills.push_back(Thunderbolt);
    skills.push_back(Megabolt);
}
#pragma endregion

#pragma endregion
#pragma endregion

// student ID
const string ID = "2023148006";
const string NAME = "Luigi Cussigh";
const string DEPARTMENT = "Computer Science";

/**
 * @brief
 * represents renderers. renderers handle stuff related to output
 */
class Renderer
{
public:
    /**
     * @brief
     * construct a new Renderer object
     * @param _width
     * table's width
     */
    Renderer(int _width)
    {
        width = _width;
    }

    /**
     * @brief
     * get the table's width
     * @return int
     * table's width
     */
    int getWidth() const
    {
        return width;
    }

    /**
     * @brief
     * get pokemon's basic data as a string (doesnt end with a newline)
     * @param pokemon pointer to the pokemon, the data of which is required
     * @param turn places "(*)" if set to true
     * @return string pokemon's stringified basic data
     */
    string stringifyPokemonBaseData(Pokemon *pokemon, bool turn)
    {
        // self-explanatory
        return pokemon->getSpecieName() + (turn ? " (*)" : "") +
               "\nType: " + Element::getElementName(pokemon->getPokemonElement()) +
               "\nHP: " + to_string(pokemon->getCurrentHP());
    }

    /**
     * @brief
     * get pokemon's skill data as a string (doesnt end with a newline)
     * @param pokemon pointer to the pokemon, the data of which is required
     * @return string pokemon's stringified skill data
     */
    string stringifyPokemonSkillData(Pokemon *pokemon)
    {
        string result = "";
        // repeat for no. of skills
        for (int i = 0; i < pokemon->getSkillCnt(); ++i)
        {
            Skill *skillptr = pokemon->getSkill(i);
            result += "(" + to_string(i) + ") " + skillptr->getName() + "\n";
            result += "    - Type: " + Element::getElementName(skillptr->getSkillElement()) + "\n";
            result += "    - Damage: " + to_string(skillptr->getBaseDamage()) + "\n";
            result += "    - Count: " + to_string(skillptr->getTriesLeft()) + "(" + to_string(skillptr->getMaxTries()) + ")" + "\n";
        }
        // remove last \n
        result.pop_back();
        return result;
    }

    /**
     * @brief
     * splits a string into a vector of strings by newlines
     * @param content the string, which requires splitting
     * @return vector<string> the resulting vector of strings
     */
    vector<string> splitByNewlines(string content)
    {
        vector<string> result;

        string tmp;
        // cycle through string
        for (int i = 0; i < static_cast<int>(content.size()); ++i)
        {
            // if \n not encountered then add to content
            if (content[i] != '\n')
            {
                tmp += content[i];
            }
            // \n encountered, store line, ignoring \n
            else
            {
                result.push_back(tmp);
                tmp = "";
            }
        }
        // add to vector
        result.push_back(tmp);
        return result;
    }

    /**
     * @brief
     * generate a cell (vector of strings)
     * (cell means singular rectangle of a table)
     * @param content cell's content (determines cell height)
     * @param cellWidth cell's width
     * @param contentOffset content's left-side offset
     * @return vector<string> resulting cell
     */
    vector<string> generateCell(string content, int cellWidth, int contentOffset)
    {
        vector<string> cell;

        vector<string> contentSplit = splitByNewlines(content);

        // place horizontal line first
        cell.push_back(genereateHorLine(cellWidth));
        // add contetns of the cell to the vector
        for (int i = 0; i < static_cast<int>(contentSplit.size()); ++i)
        {
            // start with table boundary
            string line = "|";

            // add offset
            for (int j = 0; j < contentOffset; ++j)
            {
                line += " ";
            }

            // concat content with the line
            line += contentSplit[i];

            // add spaces to match width
            for (int k = line.size(); k < cellWidth - 1; ++k)
            {
                line += " ";
            }

            // end with table boundary
            line += "|";

            // add to cell
            cell.push_back(line);
        }
        // finish with a horizontal line as well
        cell.push_back(genereateHorLine(cellWidth));
        return cell;
    }

    /**
     * @brief
     * generates a table's horizontal line
     * @param length length of the line
     * @return string resulting line
     */
    string genereateHorLine(int length)
    {
        string result = "";
        result += "+";
        for (int i = 0; i < length - 2; ++i)
        {
            result += "-";
        }
        result += "+";
        return result;
    }

    /**
     * @brief
     * renders cell to terminal
     * @param cell cell that needs to be rendered
     */
    void renderCell(const vector<string> &cell)
    {
        // cycle through vector and cout each line
        for (int i = 0; i < static_cast<int>(cell.size()); ++i)
        {
            cout << cell[i] << endl;
        }
    }

    /**
     * @brief
     * concatinate cells into one
     * @param addedCell the cell that is added to targetCell
     * @param targetCell the cell that receives addedCell
     * @param x x coordinate of the left top corner of the addedCell's target destination
     * @param y y coordinate of the left top corner of the addedCell's target destination
     */
    void concatCells(const vector<string> &addedCell, vector<string> &targetCell, int x, int y)
    {
        // we need to populate the vector to accomodate the added cell's y coordinates
        for (int i = static_cast<int>(targetCell.size()) - 1; i < y + static_cast<int>(addedCell.size()) - 1; ++i)
        {
            targetCell.push_back("");
        }

        // for each line in added cell
        for (int i = 0; i < static_cast<int>(addedCell.size()); ++i)
        {
            // poulate line at coordinates from length of line to y + length of target line length to accomodate targetCell's line
            for (int j = static_cast<int>(targetCell[y + i].size()) - 1; j < x + static_cast<int>(addedCell[i].size()) - 1; ++j)
            {
                targetCell[y + i] += " ";
            }

            // replace spaces of targetCell with offset (y,x) with the contents of the added cell
            for (int j = 0; j < static_cast<int>(addedCell[i].size()); ++j)
            {
                targetCell[y + i][j + x] = addedCell[i][j];
            }
        }
    }

    /**
     * @brief
     * generate the contents of the table's header
     * @return string the contents of the header
     */
    string generateHeader()
    {
        return ID + " " + NAME + " " + DEPARTMENT;
    }

private:
    int width;
};

/**
 * @brief
 * represents a player. holds data that is relevant to the player.
 */
class Player
{
public:
    /**
     * @brief
     * construct a new Player object
     */
    Player()
    {
        selectedPokemon = NULL;
    }
    /**
     * @brief
     * construct a new Player object
     * @param _selectedPokemon
     * pointer to the player's pokemon
     */
    Player(Pokemon *_selectedPokemon)
    {
        selectedPokemon = _selectedPokemon;
    }

    // get pointer to player's pokemon
    Pokemon *getPokemon()
    {
        return selectedPokemon;
    }

    // get wether wether it's this player's turn
    bool getTurn() const
    {
        return turn;
    }

    // sets player's turn
    void setTurn(bool _turn)
    {
        turn = _turn;
    }

private:
    // player's pokemon
    Pokemon *selectedPokemon;
    // player's turn
    bool turn = false;
};

int main(int argc, char *argv[])
{
    // create pokemons (names in case we need a battle between two pokemons of the same type)
    // we dont actually need this but eh its fun i guess
    Pikachu pikachu("pikachu1");
    Dratini dratini("dratini1");
    Eevee eevee("eevee1");
    Charmander charmander("charmander1");
    Palkia palkia("palkia1");

    Pokemon *pokemon_arr[5] = {&pikachu, &dratini, &eevee, &charmander, &palkia};

    // players' selctions (defauts to pikachu and dratini for debugging purposes)
    int selection0 = 0;
    int selection1 = 1;

    // get user input
    cout << "Choose a Pokemon(0~4): ";
    cin >> selection0;
    cout << "Choose another Pokemon(0~4): ";
    cin >> selection1;

    // check whether the selection is the same or not
    if (selection0 == selection1)
    {
        cout << "You have to choose Pokemons different from each other." << endl;
        return -1; // exit
    }

    // declare players
    Player player0(pokemon_arr[selection0]), player1(pokemon_arr[selection1]);

    // pointers players array (we need this to access players by index)
    Player *players[2] = {&player0,
                          &player1};

    // initialize renderer
    Renderer rndr(63);

    // keeps track of turn (used to determine which player's turn it is)
    int turn = 0;

    // run until either of the pokemons is defeated
    while (player0.getPokemon()->getCurrentHP() > 0 && player1.getPokemon()->getCurrentHP() > 0)
    {
        // set pointers to attacker and defender player
        Player *attacker = players[(turn % 2)];
        Player *defender = players[(turn + 1) % 2];

        // set turns
        attacker->setTurn(true);
        defender->setTurn(false);

        // generate cells
        vector<string> headerCell = rndr.generateCell(rndr.generateHeader(), rndr.getWidth(), 1);
        vector<string> cell0 = rndr.generateCell(rndr.stringifyPokemonBaseData(player0.getPokemon(), player0.getTurn()), (rndr.getWidth() / 2) + 1, 1);
        vector<string> cell1 = rndr.generateCell(rndr.stringifyPokemonBaseData(player1.getPokemon(), player1.getTurn()), (rndr.getWidth() / 2) + 1, 1);
        vector<string> cell2 = rndr.generateCell(rndr.stringifyPokemonSkillData(player0.getPokemon()), (rndr.getWidth() / 2) + 1, 1);
        vector<string> cell3 = rndr.generateCell(rndr.stringifyPokemonSkillData(player1.getPokemon()), (rndr.getWidth() / 2) + 1, 1);

        // concatinate cells
        int headerCellHeight = static_cast<int>(headerCell.size());
        rndr.concatCells(cell0, headerCell, 0, headerCellHeight - 1);
        rndr.concatCells(cell1, headerCell, rndr.getWidth() / 2, headerCellHeight - 1);

        int baseDataCellHeight = static_cast<int>(headerCell.size());
        rndr.concatCells(cell2, headerCell, 0, baseDataCellHeight - 1);
        rndr.concatCells(cell3, headerCell, rndr.getWidth() / 2, baseDataCellHeight - 1);

        // render concatinated cells (table)
        rndr.renderCell(headerCell);

        // get skill select input
        int atkSelction = -1;
        cout << "Choose a skill (0~3): ";
        cin >> atkSelction;

        // check if can use attack
        if (attacker->getPokemon()->getSkill(atkSelction)->getTriesLeft() > 0)
        {
            // attack process, update
            int dmg = attacker->getPokemon()->getSkill(atkSelction)->useSkill(defender->getPokemon()->getPokemonElement());
            defender->getPokemon()->takeDamage(dmg);

            // display attack effectiveness
            cout << attacker->getPokemon()->getSpecieName() << " used " << attacker->getPokemon()->getSkill(atkSelction)->getName() << "." << endl;
            cout << "The attack was " << attacker->getPokemon()->getSkill(atkSelction)->getEffectivenessTypeName(defender->getPokemon()->getPokemonElement()) << "." << endl;
            cout << endl;
        }
        else
        {
            cout << attacker->getPokemon()->getSpecieName() << " failed to perform " << attacker->getPokemon()->getSkill(atkSelction)->getName() << "." << endl;
            cout << endl;
        }

        // next turn
        turn++;
    }

    // pointers to winner and loser
    Player *winner, *loser;

    // determine winner and loser
    if (player0.getPokemon()->getCurrentHP() <= 0)
    {
        winner = &player1;
        loser = &player0;
    }
    else
    {
        winner = &player0;
        loser = &player1;
    }

    // display match results
    cout << "===============================================================" << endl;
    // no endline for some reason...
    cout << "Match Result: " << winner->getPokemon()->getSpecieName() << " defeats " << loser->getPokemon()->getSpecieName();
}