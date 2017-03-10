#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int isPremier(int val){
  printf("lancement de la fonction isPremier");
  char chaine[100];
  int T = 0;
  for (int i = 2; i<val ;i++) {
    printf("%s\n",i );
    if (val%i == 0 ) {
      if (val == i) {
        T = 1 ;
      }
    }
  //sprintf(chaine,"nb premier", val);
  }
  if (T == 1) return val;
  else return 2;
}

int main(int argc, char const *argv[]) {
  int tab[5] = {1,8,8,78,24,46};
  printf("Hello World\n");
  isPremier(7);
  return 0;
}
