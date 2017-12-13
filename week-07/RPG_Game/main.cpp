#include <iostream>
#include <string>
#include "character.h"

    //RPG Game lite

    //create 2 instances of the character class and fill their base stats from their constructor
    //make them attack each other with the attack method from the character class
    //after each round print both the attacker, and the attacked character health
    //make them fight each other until one of them has a health point lower or equal 0
    //print the winner and offer a new game

    //dont forget to use private variables, and get/set methods, and also place out_of_range
    //character class into a seperate file

using namespace std;

int main()
{
    Armor player_armor(9);
    Armor monster_armor(8);

    Character player("player", PLAYER, 10, 10, player_armor);
    Character monster("monster", MONSTER, 10, 10, monster_armor);

    cout << "player hp: " << player.get_hp() << endl;
    cout << "monster hp: " << monster.get_hp() << endl;

    int round = 1;

    while (1) {

    cout << "round " << round++ << ": " << endl;
    player.attack(monster);
    cout << "player hp: " << player.get_hp() << endl;
    cout << "monster hp: " << monster.get_hp() << endl;

    if (!(player.get_hp() > 1 && monster.get_hp() > 1))
        break;

    monster.attack(player);
    cout << "player hp: " << player.get_hp() << endl;
    cout << "monster hp: " << monster.get_hp() << endl;

     if (!(player.get_hp() > 1 && monster.get_hp() > 1))
        break;
    }

    return 0;
}
