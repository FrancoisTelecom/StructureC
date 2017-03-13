#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct noeud {
  int BalancedFactor, value, deep;
  struct noeud *keyG, *keyD, *keyP ;
} noeud;


int isPremier(int val); //la valeur qui va être étudier
//void CreateTtree(noeud* Nnoeud);


int main(int argc, char const *argv[]) {
  int val = 4;
  noeud *monNoeud = malloc(sizeof(noeud));

  //printf(monNoeud->BalancedFactor);
  int tab[] = {1,8,8,78,24,46};
  printf("Hello World\n");
  printf("%d\n",isPremier(7));
  return 0;
}

int isPremier(int val){
  int T = 0;
  int i = 2;
  while((i<=val) && (T == 0)){
    float tmp = val % i;
    if ((tmp == 0) && (val != i)) T=1;
    i++;
  }
  if (T==0) return T ; //T = 0 --> nb Premier
  else return T; // T = 1 -->nb non premier
}
