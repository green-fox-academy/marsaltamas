#include <iostream>
#include <string>

using namespace std;

//Create Animal class
//Every animal has a hunger value, which is a whole number
//Every animal has a thirst value, which is a whole number
//when creating a new animal object these values are created with the default 50 value
//Every animal can eat() which decreases their hunger by one
//Every animal can drink() which decreases their thirst by one
//Every animal can play() which increases both by one

class Animal {
    public:
        Animal()
        {
            hunger_ = 50;
            thirst_ = 50;
        }

        void eat()
        {
            hunger_--;
        }

        void drink()
        {
            thirst_++;
        }

        void play()
        {
            hunger_++;
            thirst_++;
        }

        void dispaly()
        {
            cout << "hunger: " << hunger_ << endl;
            cout << "thirst: " << thirst_ << endl;
        }

    private:
        int hunger_;
        int thirst_;


};

int main()
{
    Animal a;

    a.dispaly();
    a.drink();
    a.dispaly();
    a.eat();
    a.dispaly();
    a.play();
    a.dispaly();

    return 0;
}
