#include <stdio.h>
#include <stdlib.h>
#define DEGRE 4 //-> order = 2
#include "main.h"
struct tree {
	int leaf;      // 0-> false, 1->true
	int numKeys;     //how many keys does this node contain?
	int element[DEGRE+1];
	struct tree *stree[DEGRE+1];   //kids[i] holds nodes < keys[i] fils de l'arbre
};

int main()
{
    printf("Menu Principal\n");
    char nombreTexte[10] = {0};
    int n=0,valUtilisateur=0,x=0;

    bTree arbre;
	arbre = initialisation();

    do{
        printf("Selection d'une action\n");
        printf("1 - Insertion\n");
        printf("2 - recherche\n");
        printf("3 - Sortir\n");
        n = lire(nombreTexte,10);

switch (n)
{
case 1:
  printf("Quel cle inserer\n");
   x = lire(nombreTexte,10);
   if(x>0){
        //insertion(arbre, x);
         burst(arbre, x);
   }
  else{ printf("Le nombre est incorrect\n");}
  break;

case 2:
  printf("Quel cle rechercher!\n");
   x = lire(nombreTexte,10);
   if(x>0){
        x=search(arbre,x);
        if(x==0){printf("La cle n'est pas la\n");}
        else{printf("La cle est %d\n",x);}
   }
  else{ printf("Le nombre est incorecte\n");}
  break;
case 3:
  printf("Au revoir !\n");
  break;
default:
  printf("Erreur\n");
  break;

}
    }while(n!=3);
free(initialisation());//libère la mémoire de l'arbre en dur
system("pause");
system("cls");
    return 0;
}

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

bTree initialisation(){
	bTree racine = malloc(sizeof(*racine));
	returnElementNull(racine);
	racine->leaf=0;
	racine->numKeys=1;
	racine->element[1]=51;

	bTree noeud1 = malloc(sizeof(*noeud1));
	returnElementNull(noeud1);
	noeud1->leaf=0;
	noeud1->numKeys=2;
	noeud1->element[1]=11;
	noeud1->element[2]=30;
	racine->stree[0]=noeud1;

	bTree leaf1 = malloc(sizeof(*leaf1));
	returnFilsNull(leaf1);
	returnElementNull(leaf1);
	leaf1->leaf=1;
	leaf1->numKeys=2;
	leaf1->element[1]=2;
	leaf1->element[2]=7;
	noeud1->stree[0]=leaf1;


	bTree leaf2 = malloc(sizeof(*leaf2));
	returnFilsNull(leaf2);
	returnElementNull(leaf2);
	leaf2->leaf=1;
	leaf2->numKeys=3;
	leaf2->element[1]=12;
	leaf2->element[2]=15;
	leaf2->element[3]=22;
	noeud1->stree[1]=leaf2;


	bTree leaf3 = malloc(sizeof(*leaf3));
	returnFilsNull(leaf3);
	returnElementNull(leaf3);
	leaf3->leaf=1;
	leaf3->numKeys=2;
	leaf3->element[1]=35;
	leaf3->element[2]=41;
	noeud1->stree[2]=leaf3;

	bTree noeud2 = malloc(sizeof(*noeud2));
	returnElementNull(noeud2);
	noeud2->leaf=0;
	noeud2->numKeys=2;
	noeud2->element[1]=66;
	noeud2->element[2]=78;
	racine->stree[1]=noeud2;

	bTree leaf4 = malloc(sizeof(*leaf4));
	returnFilsNull(leaf4);
	returnElementNull(leaf4);
	leaf4->leaf=1;
	leaf4->numKeys=3;
	leaf4->element[1]=53;
	leaf4->element[2]=54;
	leaf4->element[3]=63;
	noeud2->stree[0]=leaf4;

	bTree leaf5 = malloc(sizeof(*leaf5));
	returnFilsNull(leaf5);
	returnElementNull(leaf5);
	leaf5->leaf=1;
	leaf5->numKeys=4;
	leaf5->element[1]=68;
	leaf5->element[2]=69;
	leaf5->element[3]=71;
	leaf5->element[4]=76;
	noeud2->stree[1]=leaf5;

	bTree leaf6 = malloc(sizeof(*leaf6));
	returnFilsNull(leaf6);
	returnElementNull(leaf6);
	leaf6->leaf=1;
	leaf6->numKeys=3;
	leaf6->element[1]=79;
	leaf6->element[2]=84;
	leaf6->element[3]=93;
	noeud2->stree[2]=leaf6;

	return racine;
}

int search(bTree tree, int val){
	int result=0,g=1,d=0,m=0;
	bTree ssArbre = NULL;//init a 0 ->protection test
	if (tree == NULL){
		return 0;
	}
	else{
		if(val<tree->element[1]){
			return search(tree->stree[0],val);
		}
		else{
			if(val>tree->element[tree->numKeys]){
				return search(tree->stree[tree->numKeys],val);
			}
			else{
				//rechercherDansNoeud(tree, val, ssArbre);
				d=tree->numKeys;
				while(g!=d){
						m=(g+d)/2;
						if(tree->element[m]>=val){
							d=m;
							if(tree->element[m]==val){
								return val;
							}
						}
						else{
							g=m+1;
						}
					}
					if(tree->element[g]==val){
						result=val;
						ssArbre=NULL;
					}
					else{
						result=0;
						ssArbre=tree->stree[g-1];
					}
				if (result!=0){
					return result;
				}
				else{
					return search(ssArbre, val);

				}
			}
		}
	}
}

bTree returnFilsNull(bTree tree){//fonction init stree[] = null
	int i;
	for (i=0; i <= DEGRE;i++) {
		tree->stree[i] = NULL;
	}
	return tree;
}

bTree returnElementNull(bTree tree){//fonction init element[] = null
	int i;
	for (i=0; i <= DEGRE;i++) {
		tree->element[i] = NULL;
	}
	return tree;
}

bTree createLeaf(int *tab, int ordre){

	int var;
	bTree tmp=malloc(sizeof(*tmp));
	returnFilsNull(tmp);//init a null fils
	returnElementNull(tmp);//init a null element
	tmp->leaf=1; // ->feuille oui
	tmp->numKeys=ordre; //->nb de valeurs dans le tableau
	for (var = 0; var <= ordre; var++) {
		tmp->element[var]=tab[var];
	}
	return tmp;
}

bTree insertion(bTree tree, int val){//algo doc non évolu avec le temp
	int tab[DEGRE+1], pos=0;
	if (tree == NULL){
		tab[1] = val;
		return createLeaf(tab,1);
	}
	else{
		pos = positionInsertion(tree, val);
		if(isLeaf(tree)==1){
			tree->element[pos]=val;
			tree->numKeys++;
		}
		if(tree->numKeys<=DEGRE){
			return tree;
		}
		else{
			burst(tree, val);
		}
	}
}

int positionInsertion(bTree tree, int val){ //retourne la position dans le tableau
	int var;
	for (var = 1; var < DEGRE+1; var++) {
		if(tree->element[var] == NULL){
			return var;
		}
	}
	return 0;
}

int isLeaf(bTree tree){// renvoi si une feuille ou non
	if (tree->leaf==1){
		return 1;
	}
	return 0;
}

bTree burst(bTree tree, int val){//eclatement d'un noeud
	int var,tmp[DEGRE+2];
	int tmpplus[(DEGRE/2)+1];
	int compteurplus=0,e,i,truc,tableau[DEGRE];
	bTree chocolat;
	for (var = 1; var <= tree->numKeys; var++) { //crée un tableau tmp organiser ordre croissant avec une nouvelle valeur
		if(val<tree->element[var]){
			tmp[var]=val;
			tmp[var+1]=tree->element[var];
			var++;
		}
		else{
			tmp[var]=tree->element[var];
		}
	}
	returnElementNull(tree); //vide que les éléments du tableau
	// 5 est à inserer
	/*1 2 3 4 5
	 * 1 2 ->arbre
	 * 3 -> père
	 * 4 5 ->creer feuille
	 *
	 * */

	if((tree->numKeys+1)%2==1){
		for (var = 1; var <= (tree->numKeys+1)/2; var++) { //si impaire on prend la valeur du milieu du tableau
			tree->element[var]=tmp[var];//les plus petites valeurs(la moitier) sont ré-insérer dans le noeud
			}
		for (var = ((tree->numKeys+1)/2)+1; var <= DEGRE+1; var++) {
			tmpplus[1+(var-DEGRE)]=tmp[var];
			compteurplus++;
		}
		int te=tmp[((tree->numKeys+1)/2)+1];// te ->mediane
		tree=searchPapa(tree, tmp[((tree->numKeys+1)/2)+1]);

		for (var = 0; var <= tree->numKeys; var++) {//ici on insert la valeur médiane dans le noeud
			if (tree->element[var]==NULL){
				tree->element[var]= te;
			}
		}
		for(var = 0; var <= tree->numKeys; var++){//tri le tree->element en croissant
			for(i = 0; i < tree->numKeys; i++) {
				if(tree->element[var] > tree->element[var+1]){
					truc = tree->element[var];
					tree->element[var] = tree->element[var+1];
					tree->element[var+1] = truc;
				}
			}
		}

		bTree tmptree=createLeaf(tmpplus,compteurplus);
		for (var = 1; var < tree->numKeys; ++var) {
			if(tmptree->element[1]<tree->element[i]){//decale les fils de l'abre de 1 valeurs
				for (i = 0; i < tree->numKeys+1; ++i) {
					chocolat = tree->stree[i];
					tree->stree[i]=tree->stree[i+1];
					tree->element[i+1] = chocolat;
				}
				tree->stree[var] = tmptree;
			}
		}
	}
	//cas pair non traité
	/*1 2 3 5
		 * 1 2  ->arbre
		 *- -> père
		 *3 5  ->creer feuille
		 *
		 * */
	else{
		for (var = 1; var <= ((tree->numKeys+1)/2)+1; var++) {//sinon ->pair on stock les plus petite +1
			tree->element[var]=tmp[var];//les plus petites valeurs(la moitier+1) sont ré-insérer dans le noeud
			}
	}
}

bTree searchPapa(bTree tree, int val){
	bTree papa;
	papa=tree;
	int var;
	if (tree == NULL){
			return 0;
		}

	if(val<tree->element[1]){
		tree=tree->stree[0];
		for (var = 1; var <= tree->numKeys; var++) {
			if (tree->element[var] == val){
				//return papa->element[1];
				return papa;
				}
		}
		return searchPapa(papa->stree[0],val);
	}
	else{
		if(val>tree->element[tree->numKeys]){
			tree=tree->stree[tree->numKeys];
			for (var = 1; var <= tree->numKeys; var++) {
				if (tree->element[var] == val){
					//return papa->element[1];
					return papa;
				}
			}
			return searchPapa(papa->stree[tree->numKeys-1],val);
		}
		else{
			tree=tree->stree[tree->numKeys-1];
			for (var = 1; var <= tree->numKeys; var++) {
					if (tree->element[var] == val){
						//return papa->element[1];
						return papa;
					}
			}
		}
	}

	return 0;
}

/*int rechercherDansNoeud(bTree tree, int val, bTree ssArbre){
	int g=1,d=tree->numKeys-1,m=0,result=0;
	while(g!=d){
		m=(g+d)/2;
		if(tree->element[m]>=val){
			d=m;
		}
		else{
			g=m+1;
		}
	}
	if(tree->element[g]==val){
		result=val;
		ssArbre=NULL;
	}
	else{
		result=0;
		ssArbre=tree->stree[g-1];
	}
	if (result!=0){
		return result;
	}
	else{
		 search(ssArbre, val);
	}
}*/
