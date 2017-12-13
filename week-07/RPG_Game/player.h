#ifndef PLAYER_H
#define PLAYER_H

#include "character.h"


class Player : public Character
{
    public:
        Player(string _name, int _type, int _hp, int _attack, Armor _armor);
    private:
};

#endif // PLAYER_H
