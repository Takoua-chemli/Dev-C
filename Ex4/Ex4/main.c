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

    printf("******** Les valeurs de P1 avant inversement sont : ******** \n");
	afficherPile(P1);

	printf("******** Les valeurs de P1 apres inversement sont : ******** \n");
	P1 = inverser(P1);
    afficherPile(P1);

    return 0;
}
