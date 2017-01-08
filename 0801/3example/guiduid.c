/* program przedstawia spos�b pobierania identyfikator�w 
   u�ytkownika procesu i grupy proces�w
   istniej� te� funkcje ustawiaj�ce te warto�ci dla bie��cego procesu,
   jednak trzeba mie� odp. uprawniwnia
*/

#include <sys/types.h>
#include <unistd.h>

main() {
  uid_t uid = getuid(),     // rzeczywisty user-id
       euid = geteuid();    // efektywny user-id
  gid_t gid = getgid(),     // rzeczywisty group-id
       egid = geteuid();    // efektywny group-id

  printf("UID = %d\t EUID = %d\t GID = %d\t EGID = %d \n",uid, euid, gid, egid);
}
