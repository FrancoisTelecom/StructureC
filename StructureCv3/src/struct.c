#define DEGRE 4 //-> order = 2
struct tree {
	int leaf;      // 0-> false, 1->true
	int numKeys;     //how many keys does this node contain?
	int element[DEGRE];
	struct tree *stree[DEGRE+1];   //kids[i] holds nodes < keys[i] fils de l'arbre
} ;

typedef struct tree *bTree;
