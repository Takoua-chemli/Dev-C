#ifndef ARBREFCTS_H_INCLUDED
#define ARBREFCTS_H_INCLUDED

struct noeud
{
    int valeur;
    struct noeud *FilsG;
    struct noeud *FilsD;
};

typedef struct noeud arbre;

arbre* creerNoeud(int valeur)
{
    arbre *nouveauNoeud = (arbre*)malloc(sizeof(arbre));
    if (nouveauNoeud == NULL)
    {
        printf("Allocation de mémoire a échoué.");
        exit(1);
    }
    nouveauNoeud->valeur = valeur;
    nouveauNoeud->FilsG = NULL;
    nouveauNoeud->FilsD = NULL;
    return nouveauNoeud;
}

arbre* inserer(arbre* racine, int valeur)
{
    if (racine == NULL)
        return creerNoeud(valeur);

    if (valeur < racine->valeur)
        racine->FilsG = inserer(racine->FilsG, valeur);
    else if (valeur > racine->valeur)
        racine->FilsD = inserer(racine->FilsD, valeur);

    return racine;
}

//Question 1
//methode dichotomique
arbre* TableauVersArbre(int tab[], int debut, int fin)
{
    //It will avoid overflow
    if (debut > fin)
        return NULL;

    //Variable will store middle element of array and make it racine of binary search tree
    int milieu = (debut + fin) / 2;
    arbre *noeud = creerNoeud(tab[milieu]);

    //Construct FilsG subtree
    noeud->FilsG = TableauVersArbre(tab, debut, milieu - 1);

    //Construct FilsD subtree
    noeud->FilsD = TableauVersArbre(tab, milieu + 1, fin);

    return noeud;

}

// Function to insert noeuds in level order
/*
noeud* insertLevelOrder(int arr[], int i, int n)
{
	noeud *racine = NULL;
	// Base case for recursion
	if (i < n)
	{
		racine = creationNoeud(arr[i]);

		// insert FilsG child
		racine->FilsG = insertLevelOrder(arr, 2 * i + 1, n);

		// insert FilsD child
		racine->FilsD = insertLevelOrder(arr, 2 * i + 2, n);
	}

	return racine;
}
*/

void afficherTableau(int *tab2, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("Tab[%d]: %d\n", i, tab2[i]);
    }
    printf("\n");
}


//1ere solution

void ArbreVersTableau(arbre *racine, int *arr, int *index)
{
    if(racine != NULL)
    {
        ArbreVersTableau(racine->FilsG, arr, index);
        arr[(*index)] = racine->valeur;
        (*index)++;
        ArbreVersTableau(racine->FilsD, arr, index);
    }
}


//2eme solution se basant sur le parcour préfixe
/*
void ArbreVersTableau(arbre *racine, int *A)
{
    static int pos = 0;

    if(racine->FilsG != NULL)
        ArbreVersTableau(racine->FilsG, A);

    A[pos++] = racine->valeur;

    if(racine->FilsD != NULL)
        ArbreVersTableau(racine->FilsD, A);
}
*/


// Function to print tree noeuds in InOrder fashion
void infixe(arbre *racine)
{
	if (racine != NULL)
	{
		infixe(racine->FilsG);
		printf("%d  ", racine->valeur);
		infixe(racine->FilsD);
	}
}


int taille(arbre *noeud)
{
    if (noeud == NULL)
        return 0;
    else
        return 1 + taille(noeud->FilsG) + taille(noeud->FilsD);
}


#endif // ARBREFCTS_H_INCLUDED
