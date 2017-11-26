#include "functions.h"

/* todo:
    move tdb vector to private
    move packed_data_line_vector to private
    format date, and keep the old struct format with timestamp as time_t
    insert try-catch to packed_data_line_vector()
    user packed_data_line_() builder to add timestamp to store struct
    implement avg() with istream input tokenization
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
