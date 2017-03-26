typedef struct tree *bTree;

bTree initialisation(); //build Btree with 1 racine, 2 nodes and 6 leaves
//int rechercherDansNoeud(bTree tree, int val, bTree ssArbre);// complement fonction search
int search(bTree tree, int val); //permet de faire une recherche dans l'arbre
bTree returnFilsNull(bTree tree); //permet d'initialier le sAbre à null
bTree createLeaf(int tab[], int val);//crée une feuille
bTree insertion(bTree tree, int val);
bTree returnElementNull(bTree tree);//return les élements à null
int positionInsertion(bTree tree, int val);
int isLeaf(bTree tree);//test si c'est une feuille
bTree burst(bTree tree, int val);//éclatement d'un noeud
bTree searchPapa(bTree tree, int val);
void viderBuffer();
int lire(char *chaine, int longueur);
