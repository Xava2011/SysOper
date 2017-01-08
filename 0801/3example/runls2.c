/* demonstracja u�ycia "execv()" do uruchomienia "ls"
 */
#include <unistd.h>

main() {

  // argumenty zadane jako wska�nik do listy napis�w
  char * const av[] = {"ls", "-li", (char *)0};

  printf("Zaraz wykonam ls ... \n");

  execv("/bin/ls", av);
  
  /* Je�eli execv() nie powiod�a si�, to wykonamy nast�puj�ce 
     komendy */
  perror("execv: b��d w wywo�aniu \"ls -l\"");
  exit(1);
}

/* Reszta funkcji rodziny exec() jest podobna 
   i zapoznanie si� ze sposobem ich u�ycia jest zadaniem domowym */


