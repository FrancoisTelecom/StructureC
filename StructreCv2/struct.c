
/*typedef struct {
    int element;
    int ispremier;//0= non | 1= oui
} Key;*/

typedef struct Noeud {
	int element;
	struct Noeud *keyP;
	struct Noeud *keyfilsG;
	struct Noeud *keyfilsD;
	struct Noeud *keyValD;
	struct Noeud *keyValG;
} Noeud;
