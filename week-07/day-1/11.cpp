#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <iomanip>

// Write catch blocks for each possibly thrown exception.
// In each catch block write out what the exception's type was. And what the exceptions value was.

using namespace std;

int main()
{
	srand(time(NULL)); // This initializes the random generator.

	int rnd = 0;

	for (int i=0; i<20; i++) {
		rnd = rand() % 6; // generate a random number in the range [0, 4]
		try {
			switch (rnd) {
				case 0:
					throw 3.2f;
					break;
				case 1:
					throw double(43.56);
					break;
				case 3:
					throw "Abrakadabra";
					break;
				case 4:
					throw false;
					break;
				default:
					throw 12;
					break;
			}
		} catch (float f) {
            cout << "Exception type FLOAT with value of: " << f << "." << endl;
		} catch (double d) {
            cout << "Exception type DOUBLE with value of: " << d << "." << endl;
		} catch (char const *cs) {
            cout << "Exception type CHCAR CONST with value of: " << cs << "." << endl;
		} catch (bool b) {
            cout << boolalpha << "Exception type BOOL with value of: " << b << "." << endl;
		}  catch (int i) {
            cout << "Exception type INT with value of: " << i << "." << endl;
		}
	}

	return 0;
}
