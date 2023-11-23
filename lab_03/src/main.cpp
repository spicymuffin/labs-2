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

const string ID = "2023148006";

class Renderer
{
public:
    Renderer(int _width)
    {
        width = _width;
    }

    string stringifyPokemonBaseData(Pokemon *pokemon, bool turn)
    {
        return pokemon->getSpecieName() +
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

    vector<string> generateCanvas(int width, int height)
    {
        vector<string> canvas;
        for (int i = 0; i < height; ++i)
        {
            string line = "";
            for (int j = 0; j < width; ++j)
            {
                line += " ";
            }
            canvas.push_back(line);
        }
        return canvas;
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
    Player(Pokemon *_selectedPokemon)
    {
        selectedPokemon = _selectedPokemon;
    }

    Pokemon *getPokemon()
    {
        return selectedPokemon;
    }

private:
    Pokemon *selectedPokemon;
};

int main(int argc, char *argv[])
{
    // create pokemons
    Pikachu pikachu("pikachu1");
    Dratini dratini("dratini1");
    Eevee eevee("eevee1");
    Charmander charmander("charmander1");
    Palkia palkia("palkia1");

    Pokemon pokemon_arr[5] = {pikachu, dratini, eevee, charmander, palkia};

    int selection0 = 0;
    int selection1 = 1;

    cout << "Choose a Pokemon(0~4): ";
    // cin >> selection0;
    cout << "Choose another Pokemon(0~4): ";
    // cin >> selection1;

    if (selection0 == selection1)
    {
        cout << "You have to choose Pokemons different from each other." << endl;
        return -1; // exit
    }

    Player player0(&pokemon_arr[selection0]), player1(&pokemon_arr[selection1]);

    Player players[2] = {player0,
                         player1};

    // initialize renderer
    Renderer mr(63);

    int turn = 0;
    while (player0.getPokemon()->getCurrentHP() > 0 && player1.getPokemon()->getCurrentHP() > 0)
    {
        // render table
        // cout << mr.stringifyPokemonBaseData(defender->getPokemon(), false);
        // cout << mr.stringifyPokemonSkillData(attacker->getPokemon());

        vector<string> headerCell = mr.generateCell(mr.generateHeader(), 63, 1);
        vector<string> cell0 = mr.generateCell(mr.stringifyPokemonBaseData(player0.getPokemon(), false), 32, 1);
        vector<string> cell1 = mr.generateCell(mr.stringifyPokemonBaseData(player1.getPokemon(), false), 32, 1);
        vector<string> cell2 = mr.generateCell(mr.stringifyPokemonSkillData(player0.getPokemon()), 32, 1);
        vector<string> cell3 = mr.generateCell(mr.stringifyPokemonSkillData(player1.getPokemon()), 32, 1);
        mr.concatCells(cell0, headerCell, 0, 2);
        mr.concatCells(cell1, headerCell, 31, 2);
        mr.concatCells(cell2, headerCell, 0, 6);
        mr.concatCells(cell3, headerCell, 31, 6);

        mr.renderCell(headerCell);

        int atkSelction = -1;
        cout << "Choose a skill(0~3): " << endl;
        cin >> atkSelction;

        Player *attacker = &players[(turn % 2)];
        Player *defender = &players[(turn + 1) % 2];

        // attack process, update
        int dmg = attacker->getPokemon()->getSkill(atkSelction)->useSkill(defender->getPokemon()->getPokemonElement());
        defender->getPokemon()->takeDamage(dmg);

        cout << attacker->getPokemon()->getSpecieName() << " used " << attacker->getPokemon()->getSkill(atkSelction)->getName() << "." << endl;
        cout << "The attack was " << attacker->getPokemon()->getSkill(atkSelction)->getEffectivenessTypeName(defender->getPokemon()->getPokemonElement()) << "." << endl;
        cout << endl;

        turn++;
    }

    Player *winner, *loser;

    // determine winner and loser

    cout << "===============================================================" << endl;
    cout << "Match Result: " << winner->getPokemon()->getSpecieName() << " defeats " << loser->getPokemon()->getSpecieName();
}