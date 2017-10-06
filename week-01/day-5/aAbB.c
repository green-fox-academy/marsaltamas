#include <stdio.h>
#include <stdlib.h>

//writing ABC with loop like this : aAbBcC...zZ

int main()
{

    for (int i = 97; i < 123; i++){

        printf("%c%c\n", i, i-32);


    }

	return 0;
}
