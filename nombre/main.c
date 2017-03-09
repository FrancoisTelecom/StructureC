#include <stdio.h>
#include <stdlib.h>
void viderBuffer()
{
    int c = 0;
    while (c != '\n' && c != EOF)
    {
        c = getchar();
    }
}

int lire(char *chaine, int longueur)
{
    char *positionEntree = NULL;

    if (fgets(chaine, longueur, stdin) != NULL)
    {
        positionEntree = strchr(chaine, '\n');
        if (positionEntree != NULL)
        {
            *positionEntree = '\0';
        }
        else
        {
            viderBuffer();
        }
        return strtol(chaine, NULL, 10);
    }
    else
    {
        viderBuffer();
        return 0;
    }
}

int main()
{
    printf("Menu Principal\n");
    char nombreTexte[10] = {0};
    int n=0;
    do{
        printf("Selection d'une action\n");
        printf("1 - Insertion\n");
        printf("2 - delete\n");
        printf("3 - recherche\n");
        printf("4 - Sortir\n");
           n = lire(nombreTexte,10);
switch (n)
{
case 1:
  printf("appel fonction incertion\n");
  break;
case 2:
  printf("appel fonction delete!");
  break;
case 3:
  printf("appel fonction recherche!");
  break;
case 4:
  printf("Salut !");
  break;
default:
  printf("erreur");
  break;
}

    }while(n!=4);
    return 0;
}
