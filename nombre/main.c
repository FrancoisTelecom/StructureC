#include <stdio.h>
#include <stdlib.h>
#define LENGHT_MAX 2
typedef struct {
    int element[LENGHT_MAX];
    int ispremier;//0= non | 1= oui
} Key;

typedef struct Noeud {
    int BalancedFactor;
    Key key;
   struct Noeud *keyG;
   struct Noeud *keyD;
   struct Noeud *keyM;
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
Noeud *initialisation(){
       Noeud* racine1 = (Noeud*)malloc(sizeof(Noeud));
racine1->keyG=NULL;
racine1->keyM=NULL;
racine1->keyP=NULL;
racine1->key.element[0]=4;
racine1->key.element[1]=0;
racine1->key.ispremier=0;

   Noeud* noeud1 = (Noeud*)malloc(sizeof(Noeud));
noeud1->keyG=NULL;
noeud1->keyD=NULL;
noeud1->keyM=NULL;
noeud1->key.element[0]=2;
noeud1->key.element[1]=0;
noeud1->key.ispremier=0;
noeud1->keyP=racine1;
racine1->keyG=noeud1;

     Noeud* Feuille1 = (Noeud*)malloc(sizeof(Noeud));
Feuille1->keyG=NULL;
Feuille1->keyD=NULL;
Feuille1->keyM=NULL;
Feuille1->key.element[0]=1;
Feuille1->key.element[1]=0;
Feuille1->key.ispremier=0;
Feuille1->keyP=noeud1;
noeud1->keyG=Feuille1;

     Noeud* Feuille2 = (Noeud*)malloc(sizeof(Noeud));
Feuille2->keyG=NULL;
Feuille2->keyD=NULL;
Feuille2->keyM=NULL;
Feuille2->key.element[0]=3;
Feuille2->key.element[1]=0;
Feuille2->key.ispremier=0;
Feuille2->keyP=noeud1;
noeud1->keyD=Feuille2;

   Noeud* noeud2 = (Noeud*)malloc(sizeof(Noeud));
noeud2->keyG=NULL;
noeud2->keyD=NULL;
noeud2->keyM=NULL;
noeud2->key.element[0]=6;
noeud2->key.element[1]=8;
noeud2->key.ispremier=0;
noeud2->keyP=racine1;
racine1->keyD=noeud2;

     Noeud* Feuille3 = (Noeud*)malloc(sizeof(Noeud));
Feuille3->keyG=NULL;
Feuille3->keyD=NULL;
Feuille3->keyM=NULL;
Feuille3->key.element[0]=5;
Feuille3->key.element[1]=0;
Feuille3->key.ispremier=0;
Feuille3->keyP=noeud2;
noeud2->keyG=Feuille3;

     Noeud* Feuille4 = (Noeud*)malloc(sizeof(Noeud));
Feuille4->keyG=NULL;
Feuille4->keyD=NULL;
Feuille4->keyM=NULL;
Feuille4->key.element[0]=7;
Feuille4->key.element[1]=0;
Feuille4->key.ispremier=0;
Feuille4->keyP=noeud2;
noeud2->keyM=Feuille4;

     Noeud* Feuille5 = (Noeud*)malloc(sizeof(Noeud));
Feuille5->keyG=NULL;
Feuille5->keyD=NULL;
Feuille5->keyM=NULL;
Feuille5->key.element[0]=9;
Feuille5->key.element[1]=10;
Feuille5->key.ispremier=0;
Feuille5->keyP=noeud2;
noeud2->keyD=Feuille5;
    return racine1;
}

Noeud* creerFeuille( int valeur,Noeud *kg, Noeud *kd, Noeud *kp) {
    Noeud *newnoeud = (Noeud*)malloc(sizeof(Noeud));
newnoeud->keyD=kd;
newnoeud->keyG=kg;
newnoeud->keyP=kp;
newnoeud->key.element[0]=valeur;

    return newnoeud;
}


void insertion(Noeud *noeud,int valeur){

}

int rechercherDansNoeud(Noeud *noeud, int valeur){
int i=0;

for (i=0;i<LENGHT_MAX ;i++ )
{
 if(noeud->key.element[i]==valeur){return valeur;}
}

return 0;
}

int recherche(Noeud *racine,int cle){
int cleRecherche=0,pgpp=0,i=0,nombre=1;
if(racine->key.element[0]==0){return cleRecherche;}
else{
    if(cle<racine->key.element[0] && racine->keyG!=NULL)
    {
       return recherche(racine->keyG,cle);
    }
    else{
    while(racine->key.element[LENGHT_MAX-nombre]==0){nombre++;}
    printf("ici %d et %d\n",racine->key.element[0],racine->key.element[1]);
        if(cle>racine->key.element[LENGHT_MAX-nombre] && racine->keyD!=NULL ){

            return recherche(racine->keyD,cle);
        }
        else{
             pgpp =rechercherDansNoeud(racine,cle);
             if(pgpp!=0){

                return pgpp;
             }
             else{
                for (i=0;i<LENGHT_MAX ;i++ )
                {
                    if(racine->key.element[i]< cle && cle <racine->key.element[i+1] ){
                      return  recherche(racine->keyM,cle);
                    }
                }

             }
        }
    }
}
return 0;
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
    racine=initialisation();

    char nombreTexte[10] = {0};
    int n=0,valUtilisateur=0,x=0;
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
  printf("Quel cle recherche!\n");
   x = lire(nombreTexte,10);
   if(x>0){
        x=recherche(racine,x);
        if(x==0){printf("La cle n'est pas la\n");}
        else{printf("La cle est %d\n",x);}
   }
  else{ printf("Le nombre est incorecte\n");}
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

