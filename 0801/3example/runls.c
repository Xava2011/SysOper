/* demonstracja u�ycia "execl()" do uruchomienia "ls"
 */
#include <unistd.h>

main() {
  printf("Zaraz wykonam ls ... \n");

  execl("/bin/ls", "ls", "-l", (char *) 0);
  
  /* Je�eli execl() nie powiod�a si�, to wykonamy nast�puj�ce 
     komendy */
  perror("execl: b��d w wywo�aniu \"ls -l\"");
  exit(1);
}


