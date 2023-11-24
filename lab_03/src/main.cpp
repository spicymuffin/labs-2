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

// class for renderer. renderer handles stuff related to output
class Renderer
{
public:
    Renderer(int _width)
    {
        width = _width;
    }

    int getWidth() const
    {
        return width;
    }

    string stringifyPokemonBaseData(Pokemon *pokemon, bool turn)
    {
        return pokemon->getSpecieName() + (turn ? " (*)" : "") +
               "\nType: " + Element::getElementName(pokemon->getPokemonElement()) +
               "\nHP: " + to_string(pokemon->getCurrentHP());
    }

    string stringifyPokemonSkillData(Pokemon *pokemon)
    {
        string result = "";
        for (int i = 0; i < pokemon->getSkillCnt(); ++i)
        {
            Skill *skillptr = pokemon->getSkill(i);
            result += "(" + to_string(i) + ") " + skillptr->getName() + "\n";
            result += "    - Type: " + Element::getElementName(skillptr->getSkillElement()) + "\n";
            result += "    - Damage: " + to_string(skillptr->getBaseDamage()) + "\n";
            result += "    - Count: " + to_string(skillptr->getTriesLeft()) + "(" + to_string(skillptr->getMaxTries()) + ")" + "\n";
        }
        result.pop_back();
        return result;
    }

    vector<string> splitByNewlines(string content)
    {
        vector<string> result;

        string tmp;
        for (int i = 0; i < static_cast<int>(content.size()); ++i)
        {
            if (content[i] != '\n')
            {
                tmp += content[i];
            }
            else
            {
                result.push_back(tmp);
                tmp = "";
            }
        }
        result.push_back(tmp);
        return result;
    }

    vector<string> generateCell(string content, int cellWidth, int contentOffset)
    {
        vector<string> cell;

        vector<string> contentSplit = splitByNewlines(content);

        cell.push_back(genereateHorLine(cellWidth));
        for (int i = 0; i < static_cast<int>(contentSplit.size()); ++i)
        {
            string line = "|";
            for (int j = 0; j < contentOffset; ++j)
            {
                line += " ";
            }
            line += contentSplit[i];
            for (int k = line.size(); k < cellWidth - 1; ++k)
            {
                line += " ";
            }
            line += "|";
            cell.push_back(line);
        }
        cell.push_back(genereateHorLine(cellWidth));
        return cell;
    }

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

    void renderCell(const vector<string> &cell)
    {
        for (int i = 0; i < static_cast<int>(cell.size()); ++i)
        {
            cout << cell[i] << endl;
        }
    }

    void concatCells(const vector<string> &cell, vector<string> &canvas, int x, int y)
    {
        for (int i = static_cast<int>(canvas.size()) - 1; i < y + static_cast<int>(cell.size()) - 1; ++i) // we need to populate
        {
            canvas.push_back("");
        }

        for (int i = 0; i < static_cast<int>(cell.size()); ++i)
        {
            for (int j = static_cast<int>(canvas[y + i].size()) - 1; j < x + static_cast<int>(cell[i].size()) - 1; ++j)
            {
                canvas[y + i] += " ";
            }
            for (int j = 0; j < static_cast<int>(cell[i].size()); ++j)
            {
                canvas[y + i][j + x] = cell[i][j];
            }
        }
    }

    string generateHeader()
    {
        return ID + " OOP Computer Science";
    }

private:
    int width;
};

class Player
{
public:
    Player()
    {
        selectedPokemon = NULL;
    }

    Player(Pokemon *_selectedPokemon)
    {
        selectedPokemon = _selectedPokemon;
    }

    Pokemon *getPokemon()
    {
        return selectedPokemon;
    }

    bool getTurn() const
    {
        return turn;
    }

    void setTurn(bool _turn)
    {
        turn = _turn;
    }

private:
    Pokemon *selectedPokemon;
    bool turn = false;
};

int main(int argc, char *argv[])
{
    // create pokemons (names in case we need a battle between two pokemons of the same type)
    // i know we dont need it but still....
    Pikachu pikachu("pikachu1");
    Dratini dratini("dratini1");
    Eevee eevee("eevee1");
    Charmander charmander("charmander1");
    Palkia palkia("palkia1");

    Pokemon *pokemon_arr[5] = {&pikachu, &dratini, &eevee, &charmander, &palkia};

    // players' selctions (defauts to pikachu and dratini for debugging purposes)
    int selection0 = 0;
    int selection1 = 1;

    cout << "Choose a Pokemon(0~4): ";
    cin >> selection0;
    cout << "Choose another Pokemon(0~4): ";
    cin >> selection1;

    if (selection0 == selection1)
    {
        cout << "You have to choose Pokemons different from each other." << endl;
        return -1; // exit
    }

    // declare players
    Player player0(pokemon_arr[selection0]), player1(pokemon_arr[selection1]);

    // players array
    Player *players[2] = {&player0,
                          &player1};

    // initialize renderer
    Renderer mr(63);

    int turn = 0;
    while (player0.getPokemon()->getCurrentHP() > 0 && player1.getPokemon()->getCurrentHP() > 0)
    {
        // set attacker and defender player
        Player *attacker = players[(turn % 2)];
        Player *defender = players[(turn + 1) % 2];

        // set turns
        attacker->setTurn(true);
        defender->setTurn(false);

        // generate cells
        vector<string> headerCell = mr.generateCell(mr.generateHeader(), mr.getWidth(), 1);
        vector<string> cell0 = mr.generateCell(mr.stringifyPokemonBaseData(player0.getPokemon(), player0.getTurn()), (mr.getWidth() / 2) + 1, 1);
        vector<string> cell1 = mr.generateCell(mr.stringifyPokemonBaseData(player1.getPokemon(), player1.getTurn()), (mr.getWidth() / 2) + 1, 1);
        vector<string> cell2 = mr.generateCell(mr.stringifyPokemonSkillData(player0.getPokemon()), (mr.getWidth() / 2) + 1, 1);
        vector<string> cell3 = mr.generateCell(mr.stringifyPokemonSkillData(player1.getPokemon()), (mr.getWidth() / 2) + 1, 1);

        // concatinate cells
        int headerCellHeight = static_cast<int>(headerCell.size());
        mr.concatCells(cell0, headerCell, 0, headerCellHeight - 1);
        mr.concatCells(cell1, headerCell, mr.getWidth() / 2, headerCellHeight - 1);

        int baseDataCellHeight = static_cast<int>(headerCell.size());
        mr.concatCells(cell2, headerCell, 0, baseDataCellHeight - 1);
        mr.concatCells(cell3, headerCell, mr.getWidth() / 2, baseDataCellHeight - 1);

        // render concatinated cells (table)
        mr.renderCell(headerCell);

        // get input
        int atkSelction = -1;
        cout << "Choose a skill(0~3): ";
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
            cout << attacker->getPokemon()->getSpecieName() << " failed to perform " << attacker->getPokemon()->getSkill(atkSelction)->getName() << endl;
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
    cout << "Match Result: " << winner->getPokemon()->getSpecieName() << " defeats " << loser->getPokemon()->getSpecieName() << endl;
}