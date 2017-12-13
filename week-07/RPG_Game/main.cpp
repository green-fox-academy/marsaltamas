#include <iostream>
#include <string>
#include "character.h"
#include "player.h"

    //RPG Game lite

    //create 2 instances of the character class and fill their base stats from their constructor
    //make them attack each other with the attack method from the character class
    //after each round print both the attacker, and the attacked character health
    //make them fight each other until one of them has a health point lower or equal 0
    //print the winner and offer a new game

    //dont forget to use private variables, and get/set methods, and also place out_of_range
    //character class into a seperate file

using namespace std;

void fight(Character c1, Character c2);

int main()
{
    Armor player_armor(9);
    Armor monster_armor(8);

    Character player("player", PLAYER, 10, 10, player_armor);
    Character monster("monster", MONSTER, 10, 10, monster_armor);

    fight(player, monster);

    cout << ":::::::::::::::::::::::::::::::::::" << endl;

    Player pl("player class", PLAYER, 10, 10, player_armor);
    Character monster2("monster2", MONSTER, 10, 10, monster_armor);

    fight(pl, monster2);

    cout << ":::::::::::::::::::::::::::::::::::" << endl;

    Player pl1("player1 class", PLAYER, 10, 10, player_armor);
    Player pl2("player2 class", PLAYER, 10, 10, player_armor);

    fight(pl1, pl2);

    return 0;
}

void fight(Character c1, Character c2)
{
    int round = 1;
    while (1) {

    cout << "round " << round++ << ": " << endl;
    c1.attack(c2);
    cout << "c1 hp: " << c1.get_hp() << endl;
    cout << "c2 hp: " << c2.get_hp() << endl;

    if (!(c1.get_hp() > 0 && c2.get_hp() > 0))
        break;

    c2.attack(c1);
    cout << "c1 hp: " << c1.get_hp() << endl;
    cout << "c2 hp: " << c2.get_hp() << endl;

    if (!(c1.get_hp() > 0 && c2.get_hp() > 0))
        break;
    }
}
