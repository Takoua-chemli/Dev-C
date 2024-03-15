#include <stdio.h>
#include <stdlib.h>
#include "ArbreFcts.h"


int main()
{
     /*
                   20
                 /    \
                /      \
               5       30
    */

    Arbre *racine=NULL;
    racine = creationNoeud(20);
    Ajout_Arbre(racine,5);
    Ajout_Arbre(racine,30);

    infixe(racine);
    printf("\n");


    /*
                   12
                 /    \
                /      \
               7       14
    */

    Arbre *racine2;
    racine2 = creationNoeud(12);
    Ajout_Arbre(racine2,7);
    Ajout_Arbre(racine2,14);

    infixe(racine2);
    printf("\n");


    Larb *L1=NULL;
    L1=ajouterEnTete(L1, racine);
    L1=ajouterEnTete(L1, racine2);


    int val;
    printf("Donner la valeur à chercher\n");
    scanf("%d",&val);

    Arbre *Pnoeud = chercherL(L1, val);

    if(Pnoeud != NULL)
        printf("\nLa valeur existe dans la liste \n");
    else
        printf("\nLa valeur n'existe pas dans la liste\n");


    // Suppression de liste
    if(suppL(L1) == NULL)
        printf("\nLa liste est maintenant vide\n");
    else
        printf("\nErreur!! \n");

    return 0;
}
