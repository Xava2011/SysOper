/* program echuj�cy argumenty wiersza polece�
 */

main(int argc, char **argv) {

  while(--argc > 0)
    printf("%s ", *++argv);
  printf("\n");
}
