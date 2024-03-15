#include <stdio.h>
#include <stdlib.h>
#include "ArbreFcts.h"


int main() {
    Arbre *A = NULL;

    A = Ajout_Rec(A, 2000, 'O', 'A', 'H');
    A = Ajout_Rec(A, 1966, 'A', 'K', 'F');
    A = Ajout_Rec(A, 1952, 'B', 'L', 'H');
    A = Ajout_Rec(A, 1977, 'C', 'M', 'F');
    A = Ajout_Rec(A, 2005, 'D', 'N', 'H');
    A = Ajout_Rec(A, 1992, 'E', 'P', 'H');
    A = Ajout_Rec(A, 2002, 'F', 'W', 'F');
    A = Ajout_Rec(A, 1972, 'G', 'Z', 'H');
    A = Ajout_Rec(A, 1984, 'H', 'R', 'F');
    A = Ajout_Rec(A, 2009, 'I', 'V', 'H');
    A = Ajout_Rec(A, 1985, 'G', 'Y', 'F');

    printf("\n______________________________\n");
    afficheOrdreCroissant(A);

    printf("\n______________________________\n");
    int n = Nombre_de_personne(A);
    printf("le nombre de personnes dans l'arbre est : %d\n", n);

    int nh = Nombre_hommes(A);
    printf("le nombre d'hommes dans l'arbre est : %d\n", nh);

    int nf = Nombre_femmes(A);
    printf("le nombre de femmes dans l'arbre est : %d\n", nf);

    return 0;
}
