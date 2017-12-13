#include "armor.h"

Armor::Armor(int _value)
{
    armor_value_ = _value;
}

void Armor::set_armor_value(int _value)
{
    armor_value_ = _value;

}
int Armor::get_armor_value()
{
    return armor_value_;
}
