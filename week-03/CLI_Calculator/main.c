#include "declarations.h"

    /* TODO
    - separate to .h files
    - limit int range - nums over 2 bill not working properly + inndicate it in help
     */

/*
OPERATION PROCESS

1. open screen
2. operation prompt to ask for and store user input, and if enter was hit, it calls for input_processor
3. input processor processes input string received from stdin from the user
4. input processor evaluates input to call the proper function
5. called function receives parameters to process and to print the result at expected screen location
6. control passed back to operation_promt

*/

int main()
{
    open_screen();
    return 0;
}
