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

class Renderer
{
public:
    Renderer(int _width)
    {
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

    int selection0 = -1;
    int selection1 = -1;

    cout << "Choose a Pokemon(0~4): ";
    cin >> selection0;
    cout << "Choose another Pokemon(0~4): ";
    cin >> selection1;

    if (selection0 == selection1)
    {
        cout << "You have to choose Pokemons different from each other." << endl;
        return -1; // exit
    }

    Player player0(&pokemon_arr[selection0]), player1(&pokemon_arr[selection1]);

    Player players[2] = {player0,
                         player1};

    int turn = 0;
    while (player0.getPokemon()->getCurrentHP() <= 0 || player1.getPokemon()->getCurrentHP() <= 0)
    {
        // render table

        int atkSelction = -1;
        cout << "Choose a skill(0~3): " << endl;
        cin >> atkSelction;

        // process, update
        players[turn].getPokemon()->;
        // display attack results

        turn++;
    }
}