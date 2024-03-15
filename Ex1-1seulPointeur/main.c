#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Pilefcts.h"


int main(void)
{
    int n, val;

    Pile *P;

    P=InitPile(P); // ou Pile *P=NULL;


    do {
        printf("Donner le nombre de valeur � inserer dans la pile : \n");
        scanf("%d", &n);
    }while(!(n>0));

    for(int i=0; i<n; i++)
    {
        printf("Donner la valeur � inserer ");
        scanf("%d", &val);
        P=empiler(P, val);
    }

    printf("******** Question 1 ******** \n");
    int x;
	printf("Donner une la valeur � chercher : ? \n");
    scanf("%d",&x);

    P = chercher(P, x);
    afficherit(P);


    printf("******** Question 2 ******** \n");
    printf("******** On suppose qu'on a la pile tri�e suivante : ******** \n");

    P=InitPile(P);
    P=empiler(P, -12);
    P=empiler(P, -6);
    P=empiler(P, 14);
    P=empiler(P, 22);

    afficherit(P);


    int valeurrecherche;
	printf("Donner une la valeur � chercher dans la pile tri�e: ? \n");
    scanf("%d",&valeurrecherche);

    //La fonction "chercherTrie" va retourner la pile remplie par la nouvelle valeur !!
    //car on utilise un seul pointeur *P � l'appel des fonctions !!!
    P = chercherTrie(P,valeurrecherche);

    printf("Les valeurs de la pile sont : \n");
    afficherRec(P);


    printf("******** Question 3 ******** \n");
    printf("La pile apr�s la supression des valeurs n�gatives \n");

    P = sup_val_neg(P);

    printf("Les valeurs de la pile sont : \n");
    afficherRec(P);


    return 1;
}
