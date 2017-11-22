#include "atmmachine.h"

int main()
{
    ATMMachine am;
    am.boot();
    am.run();
    am.quit_routine();
    return 0;
}
