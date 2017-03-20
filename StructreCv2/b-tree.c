#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "struct.c"//la structure de noeud


Noeud *initialisation();//crée un arbre de base
void insertion(Noeud *noeud,int valeur);
Noeud* creerFeuille( int valeur,Noeud *kfg, Noeud *kfd, Noeud *kp,  Noeud *kvd,  Noeud *kvg);//liée à insertion
void viderBuffer();// vide la menu
int lire(char *chaine, int longueur);// permet de faire un menu
int recherche(Noeud *noeud, int cle);//fonction recherche dans l'arbre
void buildTreeGraphic();//construction en ligne de commande de l'arbre
void menu(Noeud *racine ,int valUtilisateur);//menu

int main()
{
	//int valUtilisateur = 3;
    printf("Menu Principal\n");
    int val = 9;
    Noeud* racine;
    racine=initialisation();
    //menu(racine ,valUtilisateur);
    int r = recherche(racine,val) ;
    if (r ==0) printf("Valeur non trouvé");
    if (r ==2) printf("Valeur trouvé !");
    free(racine);
    return 0;
}

Noeud *initialisation(){
	Noeud* racine1 = (Noeud*)malloc(sizeof(Noeud));
	racine1->keyP=NULL;
	racine1->keyfilsG=NULL;
	racine1->keyfilsD=NULL;
	racine1->keyValG=NULL;
	racine1->keyValD=NULL;
	racine1->element=4;

	Noeud* noeud1 = (Noeud*)malloc(sizeof(Noeud)); //1er noeud de droite
   	noeud1->keyP=racine1;
   	noeud1->keyfilsG=NULL;
   	noeud1->keyfilsD=NULL;
   	noeud1->keyValG=NULL;
   	noeud1->keyValD=NULL;
   	noeud1->element=2;
   	racine1->keyfilsG=noeud1;

   	Noeud* feuille1 = (Noeud*)malloc(sizeof(Noeud)); //1er feuille de gauche
   	feuille1->keyP=noeud1;
   	feuille1->keyfilsG=NULL;
   	feuille1->keyfilsD=NULL;
   	feuille1->keyValG=NULL;
   	feuille1->keyValD=NULL;
   	feuille1->element=1;
   	noeud1->keyfilsG=feuille1;

   	Noeud* feuille2 = (Noeud*)malloc(sizeof(Noeud)); //2eme feuille de droite
   	feuille2->keyP=noeud1;
   	feuille2->keyfilsG=NULL;
   	feuille2->keyfilsD=NULL;
   	feuille2->keyValG=NULL;
   	feuille2->keyValD=NULL;
   	feuille2->element=3;
   	noeud1->keyfilsD=feuille2;

   	Noeud* noeud2 = (Noeud*)malloc(sizeof(Noeud)); //1er feuille de gauche
   	noeud2->keyP=racine1;
   	noeud2->keyfilsG=NULL;
   	noeud2->keyfilsD=NULL;
   	noeud2->keyValG=NULL;
   	noeud2->keyValD=NULL;
   	noeud2->element=6;
   	racine1->keyfilsD=noeud2;

   	Noeud* noeud2_5 = (Noeud*)malloc(sizeof(Noeud)); //1er feuille de gauche
   	noeud2_5->keyP=racine1;
   	noeud2_5->keyfilsG=NULL;
   	noeud2_5->keyfilsD=NULL;
   	noeud2_5->keyValG=noeud2;
   	noeud2->keyValD=noeud2_5;
   	noeud2_5->keyValD=NULL;
   	noeud2_5->element=8;
   	racine1->keyfilsD=noeud2;

   	Noeud* feuille3 = (Noeud*)malloc(sizeof(Noeud)); //3eme feuille
   	feuille3->keyP=noeud2;
   	feuille3->keyfilsG=NULL;
   	feuille3->keyfilsD=NULL;
   	feuille3->keyValG=NULL;
   	feuille3->keyValD=NULL;
   	feuille3->element=5;
   	noeud2->keyfilsG=feuille3;

 	Noeud* feuille4 = (Noeud*)malloc(sizeof(Noeud)); //7eme feuille
 	feuille4->keyP=noeud2;
 	feuille4->keyfilsG=NULL;
 	feuille4->keyfilsD=NULL;
 	feuille4->keyValG=NULL;
 	feuille4->keyValD=NULL;
 	feuille4->element=7;
 	noeud2->keyfilsD=feuille4;

 	Noeud* feuille5 = (Noeud*)malloc(sizeof(Noeud)); //3eme feuille
 	feuille5->keyP=noeud2_5;
 	feuille5->keyfilsG=NULL;
 	feuille5->keyfilsD=NULL;
 	feuille5->keyValG=NULL;
 	feuille5->keyValD=NULL;
 	feuille5->element=9;
 	noeud2_5->keyfilsG=feuille5;

	Noeud* feuille5_5 = (Noeud*)malloc(sizeof(Noeud)); //3eme feuille
	feuille5_5->keyP=noeud2_5;
	feuille5_5->keyfilsG=NULL;
	feuille5_5->keyfilsD=NULL;
	feuille5_5->keyValG=feuille5;
	feuille5->keyValD =feuille5_5;
	feuille5_5->keyValD=NULL;
	feuille5_5->element=10;
	noeud2_5->keyfilsD=feuille5_5;

    return racine1;
}
Noeud* creerFeuille( int valeur,Noeud *kfg, Noeud *kfd, Noeud *kp,  Noeud *kvd,  Noeud *kvg) {
    Noeud *newnoeud = (Noeud*)malloc(sizeof(Noeud));
    newnoeud->keyfilsD=kfd;
    newnoeud->keyfilsG=kfg;
    newnoeud->keyP=kp;
    newnoeud->keyValD=kvd;
    newnoeud->keyValG=kvg;
	newnoeud->element=valeur;

    return newnoeud;
}
int recherche(Noeud *noeud, int cle){
	printf("racine val : %d \n", noeud->element);


	if (noeud->element == cle) {
		return 2;
	}
	else if ((noeud->keyValD!=NULL) && (noeud->keyValD->element <= cle)) return recherche(noeud->keyValD, cle);
	else if ((noeud->keyValG!=NULL) && (noeud->keyValG->element >= cle)) return recherche(noeud->keyValG, cle);
	else if (noeud->element > cle && (noeud->keyfilsG !=NULL) ) return recherche(noeud->keyfilsG, cle);//cle plus petite -> gauche
	else if(noeud->element < cle && (noeud->keyfilsD !=NULL)) return recherche(noeud->keyfilsD, cle);//cle + grande -> droite
	else return 0;

}

void viderBuffer(){
    int c = 0;
    while (c != '\n' && c != EOF)
    {
        c = getchar();
    }
}
int lire(char *chaine, int longueur){
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
void insertion(Noeud *noeud,int valeur){

	/* 1- creer une valeur
	 * 2- recherche de son emplacement dans l'arbre
	 * 3- equilibrer avec son parent, valD/valG, filsD/filsG
	 * 4- Reparcourir l'abre et équilibrer n'ensemble
	 *
	 *
	 *
	 *
	 * */

}
void void buildTreeGraphic(){

}
void menu(Noeud *racine ,int valUtilisateur){
	char nombreTexte[10] = {0};
	    int n=0,x=0;
	    //int valUtilisateur=0;

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
}
