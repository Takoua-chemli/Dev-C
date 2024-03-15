#include <stdio.h>
#include <stdlib.h>
#include "ArbreFcts.h"


int main()
{

    int arr[] = {15, 20, 3, 12, 16, 30, 9, 8, 10, 7, 14, 18};

    int n = sizeof(arr) / sizeof(arr[0]);


    // Cr�ation de l'arbre BST
    arbre* racine = NULL;
    for (int i = 0; i < n; i++)
    {
        racine = inserer(racine, arr[i]);
    }

    //Question 1
    printf("Les valeurs du tableau selon la m�thode dichotomique sont : \n");
    infixe(racine);

    int tailleArbre = taille(racine);
    printf("\n\nL'abre binaire contient %d noeud(s)", tailleArbre);


    //Question 2
    printf("\n\n***ARRAY***\n");

    // Cr�ation du tableau � partir de l'arbre BST
    int *Tab = (int*)malloc(n * sizeof(int));
    if (Tab == NULL)
    {
        printf("Allocation de m�moire a �chou�.");
        exit(1);
    }

    int i = 0;
    ArbreVersTableau(racine, Tab, &i);

    //2eme solution
    //ArbreVersTableau(racine, Tab);

    // Affichage du tableau
    printf("Tableau � partir de l'arbre BST : \n");
    afficherTableau(Tab, n);

    // Lib�ration de la m�moire
    free(Tab);

    return 0;
}

