#include <stdio.h>
#include <stdlib.h>
#define DEGRE 4 //-> order = 2
//#include "struct.c"

struct tree {
	int leaf;      // 0-> false, 1->true
	int numKeys;     //how many keys does this node contain?
	int element[DEGRE];
	struct tree *stree[DEGRE+1];   //kids[i] holds nodes < keys[i] fils de l'arbre
};

typedef struct tree *bTree;


bTree initialisation(); //build Btree with 1 racine, 2 nodes and 6 leaves
int rechercherDansNoeud(bTree tree, int val,int estpresent, bTree ssArbre);
int search(bTree tree, int val);

int main() {
	bTree arbre;
	arbre = initialisation();
	printf("search : %d\n",search(arbre,51));

	free(initialisation());
	return EXIT_SUCCESS;
}


bTree initialisation(){
	bTree racine = malloc(sizeof(*racine));
	racine->leaf=0;
	racine->numKeys=1;
	racine->element[0]=51;

	bTree noeud1 = malloc(sizeof(*noeud1));
	noeud1->leaf=0;
	noeud1->numKeys=2;
	noeud1->element[0]=11;
	noeud1->element[1]=30;
	racine->stree[0]=noeud1;

	bTree leaf1 = malloc(sizeof(*leaf1));
	leaf1->leaf=1;
	leaf1->numKeys=1;
	leaf1->element[0]=27;
	noeud1->stree[0]=leaf1;

	bTree leaf2 = malloc(sizeof(*leaf2));
	leaf2->leaf=1;
	leaf2->numKeys=3;
	leaf2->element[0]=12;
	leaf2->element[1]=15;
	leaf2->element[2]=22;
	noeud1->stree[1]=leaf2;

	bTree leaf3 = malloc(sizeof(*leaf3));
	leaf3->leaf=1;
	leaf3->numKeys=2;
	leaf3->element[0]=35;
	leaf3->element[1]=41;
	noeud1->stree[2]=leaf3;

	bTree noeud2 = malloc(sizeof(*noeud2));
	noeud2->leaf=0;
	noeud2->numKeys=2;
	noeud2->element[0]=66;
	noeud2->element[1]=78;
	racine->stree[1]=noeud2;

	bTree leaf4 = malloc(sizeof(*leaf4));
	leaf4->leaf=1;
	leaf4->numKeys=3;
	leaf4->element[0]=53;
	leaf4->element[1]=54;
	leaf4->element[2]=63;
	noeud2->stree[0]=leaf4;

	bTree leaf5 = malloc(sizeof(*leaf5));
	leaf5->leaf=1;
	leaf5->numKeys=4;
	leaf5->element[0]=68;
	leaf5->element[1]=69;
	leaf5->element[2]=71;
	leaf5->element[3]=76;
	noeud2->stree[1]=leaf5;

	bTree leaf6 = malloc(sizeof(*leaf6));
	leaf6->leaf=1;
	leaf6->numKeys=3;
	leaf6->element[0]=79;
	leaf6->element[1]=84;
	leaf6->element[2]=93;
	noeud2->stree[2]=leaf6;
}

int search(bTree tree, int val){
	int result=0;
	bTree ssArbre;
	if (tree == NULL){
		return 0;
	}
	else{
		if(val<tree->element[0]){
			return search(tree->stree[0],val);
		}
		else{
			if(val>tree->element[tree->numKeys]){
				return search(tree->stree[tree->numKeys],val);
			}
			else{
				result = rechercherDansNoeud(tree, val, result, ssArbre);
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
	int g=1,d=tree->numKeys,m=0;
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
		estpresent=1;
		ssArbre=NULL;
	}
	else{
		estpresent=0;
		ssArbre=tree->stree[g-1];
	}

}
