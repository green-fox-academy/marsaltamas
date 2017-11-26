#include "functions.h"

/* todo:
    move tdb vector to private
 */

using namespace std;

int main()
{
    vector<string> command_vector = init_command_vector();
    TemperatureDatabase *tdb = new TemperatureDatabase();


    print_port_info();
    print_menu();

    run(command_vector, tdb);

    delete tdb;

    return 0;
}
