#include <stdio.h>
#include <stdlib.h>
#include "Pilefcts.h"

int main()
{
    Pile *P1;
    P1 = InitPile(P1);

	P1=empiler(P1, 10);
	P1=empiler(P1, 12);
	P1=empiler(P1, 14);
    printf("******** Les valeurs de P1 sont : ******** \n");
	afficher(P1);


	Pile *P2=NULL;
    InitPile(P2);
	P2=empiler(P2, 11);
	P2=empiler(P2, 12);
	P2=empiler(P2, 13);
    printf("******** Les valeurs de P2 sont : ******** \n");
	afficher(P2);


	Pile *P3=NULL;
    P3=InitPile(P3);
	P3 = creer_pileP3(P1, P2);
	printf("******** Les valeurs de P3 sont : ******** \n");
	afficher(P3);

    return 0;
}
