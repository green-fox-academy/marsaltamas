#ifndef ARMOR_H
#define ARMOR_H


class Armor
{
    public:
        Armor(){};
        Armor(int _value);
        void set_armor_value(int _value);
        int get_armor_value();
    private:
        int armor_value_;
};

#endif // ARMOR_H
