// Create a Human class which is a base class for
// SuperHuman and AquaHuman
// Create a virtual function in Human class called travelling()
// It should print out different ways to travel
// For example: Human is walking. SuperHuman is flying. AquaHuman is riding with dolphins

#include "human.h"
#include "superhuman.h"
#include "aquahuman.h"

void move_human(Human *h[], int size)
{
    for (int i = 0; i < size; ++i) {
        h[i]->travel();
    }
}

int main()
{
    SuperHuman *sh = new SuperHuman;
    AquaHuman *ah = new AquaHuman;
    Human *h[] = {sh, ah};

    move_human(h, 2);

    return 0;
}
