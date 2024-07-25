#include "contref.h"

int main(){
  int *v = malloc2(sizeof(int));
  int *w = malloc2(sizeof(int));
  char *c = malloc2(sizeof(char));
  char *d = malloc2(sizeof(char));
  *v = 10;
  *w = 20;
  printf("v = %d, w = %d\n", *v, *w);
  mostraCont(v);
  atrib2(v, w);
  mostraCont(v);
  printf("\nv = %d, w = %d\n", *v, *w);
  atrib2(v, NULL);
  mostraCont(w);
  if(v==NULL){
    printf("\nv = null.\n");
  }
  printf("\n");

  *c = 'a';
  *d = 'b';
  printf("c = %c, d = %c\n", *c, *d);
  mostraCont(c);
  atrib2(c, d);
  mostraCont(c);
  printf("\nc = %c, d = %c\n", *c, *d);
  atrib2(c, NULL);
  mostraCont(d);
  if(c==NULL){
    printf("\nc = null.");
  }
  free_ponteiros();
  return 0;
} 
