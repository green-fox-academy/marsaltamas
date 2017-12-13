#ifndef CHARACTER_H
#define CHARACTER_H

#define PLAYER 1
#define MONSTER 2

#include <string>
#include <iostream>
#include "armor.h"

using namespace std;

    //Create a Character class with the following preferences:
    //name
    //character type (player/monster)
    //health point value
    //attack value
    //defense value

class Character
{
    public:
        Character(string _name, int _type, int _hp, int _attack, Armor _armor);
        void attack(Character& _enemy);
        int get_hp();
        void set_hp(int _new_hp);
        int get_armor();
        int get_deffense();
    private:
        string name_;
        int type_;
        int hp_;
        int attack_;
        int deffense_;
        Armor armor_;

};

#endif // CHARACTER_H
