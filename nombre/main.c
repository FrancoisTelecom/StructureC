#include <stdio.h>
#include <stdlib.h>
typedef struct {
    int valeur;
} Key;

typedef struct Noeud {
    int BalancedFactor; //ici ou dans key
    Key key;
   struct Noeud *keyG;
   struct Noeud *keyD;
   struct Noeud *keyP;
} Noeud;

void viderBuffer()
{
    int c = 0;
    while (c != '\n' && c != EOF)
    {
        c = getchar();
    }
}

Noeud* creerNoeud( int valeur,Noeud *kg, Noeud *kd, Noeud *kp) {
    Noeud *newnoeud = (Noeud*)malloc(sizeof(Noeud));
newnoeud->keyD=kd;
newnoeud->keyG=kg;
newnoeud->keyP=kp;
newnoeud->key.valeur=valeur;
    return newnoeud;
}

Noeud* creeArbre(){
Noeud *noeud = (Noeud*)malloc(sizeof(Noeud));
noeud=creerNoeud((int)NULL,NULL,NULL,NULL);
return noeud;
}


void insertion(Noeud *noeud,int valeur){
if(noeud->key.valeur==(int)NULL && noeud->keyP==NULL){
noeud->key.valeur=valeur;
}
else{
    if(noeud->key.valeur!=(int)NULL){
        if(valeur>noeud->key.valeur){
                if(noeud->keyD!=NULL){
                        insertion(noeud->keyD,valeur);
                }
                else{
                    creerNoeud(valeur,NULL,NULL,noeud);
                }
        }
        else if(valeur<noeud->key.valeur){
                if(noeud->keyG!=NULL){
                        insertion(noeud->keyG,valeur);
                }
                else{
                    creerNoeud(valeur,NULL,NULL,noeud);
                }
        }
    }
    else{
        printf("erreur 101");
    }
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
    Noeud* racine;
    racine=creeArbre();
    char nombreTexte[10] = {0};
    int n=0,valUtilisateur=0;
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
  insertion(racine,valUtilisateur);
  break;
case 2:
  printf("appel fonction delete!\n");
  break;
case 3:
  printf("appel fonction recherche!\n");
  break;
case 4:
  printf("Salut !\n");
  break;
default:
  printf("erreur\n");
  break;
}

    }while(n!=4);
    return 0;
}
