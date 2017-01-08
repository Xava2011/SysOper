/* pokazuje obs�ug� wsp�lnych plik�w przez procesy
   zak�adamy, �e "data" jest plikiem o najmniej 20 znakach
*/
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>

int fatal(char *s) {
  perror(s);
  exit(1);
}

// drukuje pozycj� pliku i zawarto�� bufora
int printpos(const char *string, int filedes, char *buf) {
  off_t pos;
  // badamy pozycj� w pliku przez wykorzystanie wyniku funkcji 
  // lseek z przesuni�ciem o 0 bajt�w od aktualnej pozycji
  if((pos = lseek(filedes, 0, SEEK_CUR)) == -1)
    fatal("B��D: niepowodzenie lseek");
  printf("%s:%ld:%s\n", string, pos, buf);
}

// program g��wny
main() {
  int fd;       // deskryptor pliku
  pid_t pid;    // ID procesu
  char buf[10]; // bufor dla danych pliku
 
  if((fd = open("data", O_RDONLY)) == -1) 
    fatal("B��D: otwarcie pliku");
  
  read(fd, buf, 10); // czytamy 10 znak�w

  printpos("PRZED: fork()", fd, buf);

  // tworzymy potomka
  switch(pid = fork()) {
  case -1: // b��d
    fatal("B��D: niepowodzenie w fork");
    break;
  case 0: // proces potomny
    printpos("POTOMNY: przed read", fd, buf);
    read(fd, buf, 10); // czytamy 10 znak�w
    printpos("POTOMNY: po read", fd, buf);
    break;
  default: // proces rodzicielski
    wait((int *)0); // o tym potem
    printpos("RODZICIELSKI: po wait", fd, buf);
  }
}
/*
  Zadanie: Sprawd�, co dzieje si� wewn�trz procesu rodzicielskiego, 
           je�li proces potomny zamknie deskryptor pliku dziedziczony 
	   za po�rednictwem fork()?
	   Czy dla procesu rodzicielskiego plik ten pozostanie otwarty,
	   czy te� zostanie zamkni�ty?
*/
  
