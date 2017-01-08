/* demonstracja operacji na zmiennych �rodowiska
 */
#include <unistd.h>
#include <stdio.h>

// wska�nik do �rodowiska w funkcji main
// elementami tablicy s� pary: NAZWA=WARTO��
// ostatnim elementem tablicy jest NULL
extern char **environ;

int main(int argc, char **argv) {

  // argumenty wywo�ania (znane z C)
  if( argc == 1 ) 
    printf("Brak parametr�w wywo�ania\n");
  else {
    printf("Argumenty:\t");
    while( --argc > 0) 
      printf("%s\t", *++argv);
    printf("\n");
  }
  // putenv() i getenv()
  putenv("QQ=to tylko test");
  printf("\n Pobra�em QQ   = %s\n", getenv("QQ"));
  printf("\n Pobra�em USER = %s\n", getenv("USER"));
  printf("\n");

  // lista zmiennych �rodowiska
  while(*environ)
    printf("%s\n", *environ++);
  
  // co tu si� stanie
  printf("\n Pobra�em USER = %s\n", getenv("USER"));

  return 0;
}
