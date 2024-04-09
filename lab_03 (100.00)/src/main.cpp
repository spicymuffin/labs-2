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

#include "Element.h"
#include "Pokemon.h"
#include "Skill.h"

#include "pokemon/Charmander.h"
#include "pokemon/Dratini.h"
#include "pokemon/Eevee.h"
#include "pokemon/Palkia.h"
#include "pokemon/Pikachu.h"

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