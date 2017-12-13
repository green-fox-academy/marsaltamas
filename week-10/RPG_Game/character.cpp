#include "character.h"
#include <time.h>
#include <stdlib.h>

Character::Character(string _name, int _type, int _hp, int _attack, Armor _armor)
{
    name_ = _name;
    type_ = _type;
    hp_ = _hp;
    attack_ = _attack;
    deffense_ = _armor.get_armor_value();

}

//attacking method which takes a character class and decreases its health
//value with (current character class attack - input character class defense),
//if the output is minus, then our health is decreased
//set the attacking method to have 50% chanse to count our attack value twice,
//(2xcurrent attack - input defense) before calculating the final health points.

void Character::attack(Character& _enemy)
{
    srand((time(0)));
    int rand_num = rand()  % 2;
    int attack_in_this_round = attack_;

    if (rand_num)
        attack_in_this_round *= 2;

    int damage = attack_in_this_round - _enemy.deffense_;

    if (damage >= 0)
        _enemy.set_hp(_enemy.get_hp() - damage);
    else
        set_hp(get_hp() + damage);

}

int Character::get_hp()
{
    return hp_;
}

void Character::set_hp(int _new_hp)
{
    hp_ = _new_hp;
}

 int Character::get_armor()
 {
     return armor_.get_armor_value();
 }

int Character::get_deffense()
{
    return deffense_;
}
