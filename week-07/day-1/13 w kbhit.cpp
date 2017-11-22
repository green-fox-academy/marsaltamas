#include <cstddef>
#include <ctime>
#include <iostream>
#include <conio.h>

bool get_input ( char *buffer, std::size_t size, int timeout )
{
  std::time_t start = std::time ( 0 );
  std::size_t n = 0;

  for ( ; ; ) {
    if ( n == 0 && std::difftime ( std::time ( 0 ), start ) >= timeout )
      return false;

    if ( kbhit() ) {
      if ( n == size - 1 )
        break;

      char ch = (int)getche();

      if ( ch == '\r' ) {
        buffer[n++] = '\n';
        break;
      }
      else
        buffer[n++] = ch;
    }
  }

  buffer[n] = '\0';

  return true;
}

int main()
{
  char buffer[512] = {0};

  if ( !get_input ( buffer, 512, 5 ) ) {
    std::cout<<"Input timed out\n";
    buffer[0] = '\n';
  }

  std::cout<<"input: \""<< buffer <<"\"\n";
}

//https://stackoverflow.com/questions/421860/capture-characters-from-standard-input-without-waiting-for-enter-to-be-pressed
//https://www.computerhope.com/forum/index.php?topic=104972.0
