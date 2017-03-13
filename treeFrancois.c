#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct noeud {
  int BalancedFactor, value, deep;
  struct noeud *keyG, *keyD, *keyP ;
} noeud;


int isPremier(int val); //la valeur qui va être étudier
int recherche(noeud *monNoeud, int value);


int main(int argc, char const *argv[]) {
  int val = 4;
  noeud *monNoeud = malloc(sizeof(noeud));
  monNoeud->value = 30;
  printf("%d\n",recherche(monNoeud, 30));
  int tab[] = {1,8,8,78,24,46};
  printf("Hello World\n");
  printf("%d\n",isPremier(7));
  free(monNoeud);
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
  else return T; // T = 1 -->nb non-premier
}


int recherche(noeud *monNoeud, int value)
{
    while(monNoeud)
    {
        if(value == monNoeud->value) return value;
        if(value > monNoeud->value ) monNoeud = monNoeud->keyD;
        else monNoeud = monNoeud->keyG;
    }
    return 0;
}
