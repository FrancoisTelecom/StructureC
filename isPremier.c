#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

int main(int argc, char const *argv[]) {
  //int tab[5] = {1,8,8,78,24,46};
  printf("Hello World\n");
  printf("%d\n",isPremier(7));
  return 0;
}
