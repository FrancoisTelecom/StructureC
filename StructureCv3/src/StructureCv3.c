#include <stdio.h>
#include <stdlib.h>
#define DEGRE 4 //-> order = 2
//#include "struct.c"

struct tree {
	int leaf;      // 0-> false, 1->true
	int numKeys;     //how many keys does this node contain?
	int element[DEGRE+1];
	struct tree *stree[DEGRE+1];   //kids[i] holds nodes < keys[i] fils de l'arbre
};

typedef struct tree *bTree;


bTree initialisation(); //build Btree with 1 racine, 2 nodes and 6 leaves
int rechercherDansNoeud(bTree tree, int val,int estpresent, bTree ssArbre);
int search(bTree tree, int val);
bTree returnFilsNull(bTree tree); //permet d'initialier le sAbre à null
bTree createLeaf(int tab[], int val);//crée une feuille
bTree insertion(bTree tree, int val);
bTree returnElementNull(bTree tree);//return les élements à null
int positionInsertion(bTree tree, int val);
int isLeaf(bTree tree);//test si c'est une feuille
bTree burst(bTree tree, int val);//éclatement d'un noeud

int main() {
	bTree arbre;
	arbre = initialisation();
	printf("search : %d\n",search(arbre,150));

	free(initialisation());
	return EXIT_SUCCESS;
}


bTree initialisation(){
	bTree racine = malloc(sizeof(*racine));
	racine->leaf=0;
	racine->numKeys=1;
	racine->element[0]=NULL;
	racine->element[1]=51;
	racine->element[2]=NULL;
	racine->element[3]=NULL;
	racine->element[4]=NULL;


	bTree noeud1 = malloc(sizeof(*noeud1));
	noeud1->leaf=0;
	noeud1->numKeys=2;
	noeud1->element[0]=NULL;
	noeud1->element[1]=11;
	noeud1->element[2]=30;
	noeud1->element[3]=NULL;
	noeud1->element[4]=NULL;
	racine->stree[0]=noeud1;

	bTree leaf1 = malloc(sizeof(*leaf1));
	returnFilsNull(leaf1);
	leaf1->leaf=1;
	leaf1->numKeys=2;
	leaf1->element[0]=NULL;
	leaf1->element[1]=2;
	leaf1->element[2]=7;
	leaf1->element[3]=NULL;
	leaf1->element[4]=NULL;
	noeud1->stree[0]=leaf1;


	bTree leaf2 = malloc(sizeof(*leaf2));
	returnFilsNull(leaf2);
	leaf2->leaf=1;
	leaf2->numKeys=3;
	leaf2->element[0]=NULL;
	leaf2->element[1]=12;
	leaf2->element[2]=15;
	leaf2->element[3]=22;
	leaf2->element[4]=NULL;
	noeud1->stree[1]=leaf2;


	bTree leaf3 = malloc(sizeof(*leaf3));
	returnFilsNull(leaf3);
	leaf3->leaf=1;
	leaf3->numKeys=2;
	leaf3->element[0]=NULL;
	leaf3->element[1]=35;
	leaf3->element[2]=41;
	leaf3->element[3]=NULL;
	leaf3->element[4]=NULL;
	noeud1->stree[2]=leaf3;

	bTree noeud2 = malloc(sizeof(*noeud2));
	noeud2->leaf=0;
	noeud2->numKeys=2;
	noeud2->element[0]=NULL;
	noeud2->element[1]=66;
	noeud2->element[2]=78;
	noeud2->element[3]=NULL;
	noeud2->element[4]=NULL;
	racine->stree[1]=noeud2;

	bTree leaf4 = malloc(sizeof(*leaf4));
	returnFilsNull(leaf4);
	leaf4->leaf=1;
	leaf4->numKeys=3;
	leaf4->element[0]=NULL;
	leaf4->element[1]=53;
	leaf4->element[2]=54;
	leaf4->element[3]=63;
	leaf4->element[4]=NULL;
	noeud2->stree[0]=leaf4;


	bTree leaf5 = malloc(sizeof(*leaf5));
	returnFilsNull(leaf5);
	leaf5->leaf=1;
	leaf5->numKeys=4;
	leaf5->element[0]=NULL;
	leaf5->element[1]=68;
	leaf5->element[2]=69;
	leaf5->element[3]=71;
	leaf5->element[4]=76;
	noeud2->stree[1]=leaf5;

	bTree leaf6 = malloc(sizeof(*leaf6));
	returnFilsNull(leaf6);
	leaf6->leaf=1;
	leaf6->numKeys=3;
	leaf6->element[0]=NULL;
	leaf6->element[1]=79;
	leaf6->element[2]=84;
	leaf6->element[3]=93;
	leaf6->element[4]=NULL;
	noeud2->stree[2]=leaf6;


	return racine;
}

int search(bTree tree, int val){
	int result=0;
	int g=1,d=0,m=0;
	//bTree ssArbre =  malloc(sizeof(*ssArbre));
	bTree ssArbre = NULL;
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
				//result = rechercherDansNoeud(tree, val, result, ssArbre);
				d=tree->numKeys;
				while(g!=d){
						m=(g+d)/2;
						if(tree->element[m]>=val){
							d=m;
							if(tree->element[m]==val){return val;}
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

int rechercherDansNoeud(bTree tree, int val, int estpresent, bTree ssArbre){
	int g=1,d=tree->numKeys-1,m=0;
	while(g!=d){
		m=(g+d)/2;
		if(tree->element[m]>=val){
			d=m;
		}
		else{
			g=m+1;
		}
	}
	if(tree->element[g-1]==val){
		estpresent=val;
		ssArbre=NULL;
	}
	else{
		estpresent=0;
		ssArbre=tree->stree[g];
	}
	return estpresent;
}

bTree returnFilsNull(bTree tree){
	int i;
	for (i=0; i < DEGRE;i++) {
		tree->stree[i] = NULL;
	}
	return tree;
}

bTree returnElementNull(bTree tree){
	int i;
	for (i=0; i < DEGRE;i++) {
		tree->element[i] = NULL;
	}
	return tree;
}

bTree createLeaf(int tab[], int ordre){

	int var;
	bTree tmp=malloc(sizeof(*tmp));
	returnFilsNull(tmp);
	returnElementNull(tmp);
	tmp->leaf=1;
	tmp->numKeys=ordre;
	for (var = 0; var <= ordre; var++) {
		tmp->element[var]=tab[var];
	}
	return tmp;
}

bTree insertion(bTree tree, int val){
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

		}
	}
}

int positionInsertion(bTree tree, int val){
	int var;
	for (var = 1; var < DEGRE+1; ++var) {
		if(tree->element[var]==NULL){
			return var;
		}
	}
	return 0;
}

int isLeaf(bTree tree){
	if (tree->leaf==1){
		return 1;
	}
	return 0;
}

bTree burst(bTree tree, int val){
	int var,tmp[DEGRE+2];
	for (var = 1; var <= tree->numKeys; var++) {
		if(val<tree->element[var]){
			tmp[var]=val;
			tmp[var+1]=tree->element[var];
			var++;
		}
		else{
			tmp[var]=tree->element[var];
		}
	}
	returnElementNull(tree);
	for (var = 1; var <= (tree->numKeys+1)/2; var++) {
		tree->element[var]=tmp[var];
	}
	if((tree->numKeys+1)%2==1){
		//tree->element[var]tmp[(tree->numKeys+1)/2];
	}

}




