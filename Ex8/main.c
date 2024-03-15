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
             /   \     /\
            /     \   /  \
           1      15 25  40
                /          \
               /            \
              9             45
            /   \          /
           /     \        /
          7      12      42
    */

    Arbre *racine;
    racine = creationNoeud(20);
    Ajout_Rec(racine,5);
    Ajout_Rec(racine,1);
    Ajout_Rec(racine,15);
    Ajout_Rec(racine,9);
    Ajout_Rec(racine,7);
    Ajout_Rec(racine,12);
    Ajout_Rec(racine,30);
    Ajout_Rec(racine,25);
    Ajout_Rec(racine,40);
    Ajout_Rec(racine, 45);
    Ajout_Rec(racine, 42);

    infixe(racine);
    printf("\n");

    printf("\nLa somme des noeuds est : %d \n", SommeNodes(racine));
    printf("\nLa somme des feuilles est : %d \n\n\n", SommeFeuilles(racine));

    miroir(racine);
    infixe(racine);
    printf("\n");


    return 0;
}
