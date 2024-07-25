#include <stdio.h>
#include <stdlib.h>

typedef struct ContRef{
void *p;
int cont;
}ContRef;

#define MAX 100
#define atrib2(v1, v2) atribnew((void**)&(v1), (v2))

static ContRef ponteiros[MAX];
static int count = 0;

static int find(void* p){
int i;
  for (i=0; i<count; i++){
    if (ponteiros[i].p == p){
      return i;
    }
  }
}

void mostraCont(void *p){
  int i = find(p);
  printf("\nContagem de ponteiros: %d. \n", ponteiros[i].cont);
}

static void addPont(void* p){
  if (count < MAX){
    ponteiros[count].p = p;
    ponteiros[count].cont = 1;
    count++;
  }
}

void* malloc2(size_t size){
  void* p = malloc(size);
  addPont(p);
  return p;
}

void atribnew(void** v1, void* v2){
  int i = find(*v1);
  if (ponteiros[i].cont - 1 == 0){
    free(ponteiros[i].p);
    ponteiros[i] = ponteiros[count - 1];
    count--;
  } else{
    ponteiros[i].cont--;
  }

  if (v2 != NULL){
    i = find(v2);
    ponteiros[i].cont++;
  }

  *v1 = v2;
}

void free_ponteiros(){
  int i;
  for(i=0;i<count;i++){
    free(ponteiros[i].p);
  }
}
