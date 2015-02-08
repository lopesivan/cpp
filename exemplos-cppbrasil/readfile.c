#include <stdlib.h>
#include <stdio.h>

/*****************************************************************************
 *                                                                           *
 *  --------------------------------- main --------------------------------- *
 *                                                                           *
 *****************************************************************************/

int
main (int argc, char *argv[])
{

  FILE *fp;
  char *fild1,
       *fild2,
       *fild3,
       *fild4;

  if((fp=fopen("./diario_de_aula.txt", "r")) == NULL) {
    printf("Cannot open file.\n");
    exit(1);
  };

  fild1 = (char*) malloc ((size_t) (80) * sizeof (char));
  if (!fild1) {
    fprintf(stderr, "!!ERROR!!");
  }

  fild2 = (char*) malloc ((size_t) (4) * sizeof (char));
  if (!fild2) {
    fprintf(stderr, "!!ERROR!!");
  }

  fild3 = (char*) malloc ((size_t) (4) * sizeof (char));
  if (!fild3) {
    fprintf(stderr, "!!ERROR!!");
  }

  fild4 = (char*) malloc ((size_t) (4) * sizeof (char));
  if (!fild4) {
    fprintf(stderr, "!!ERROR!!");
  }

  fscanf(fp,
         "%[^|\n]%*[ |]%[^|\n]%*[|]%[^|\n]%*[|]%[^|\n]|%*[\n]",
         fild1,
         fild2,
         fild3,
         fild4
  );

  printf("campo: %s\n", fild1);
  printf("campo: %s\n", fild2);
  printf("campo: %s\n", fild3);
  printf("campo: %s\n", fild4);

  free(fild1);
  free(fild2);
  free(fild3);
  free(fild4);

  return EXIT_SUCCESS;
}

