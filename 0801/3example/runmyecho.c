/* demonstracja przekazywania parametr�w do komendy wywo�ywanej 
   z execvp() */

#include <unistd.h>

main() {

  // argumenty polecenia myecho
  char * const argin[] = {"myecho", "pierwszy", "drugi", "...", (char *)0};

  execvp("./myecho", argin);
  
  /* Je�eli execvp() nie powiod�a si�, to wykonamy nast�puj�ce 
     komendy */
  perror("execvp: b��d w wywo�aniu \"./myecho\"");
  exit(1);
}

