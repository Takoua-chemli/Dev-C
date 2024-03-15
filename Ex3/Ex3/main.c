#include <stdio.h>
#include <stdlib.h>
#include "Pilefcts.h"

int main()
{
    Pile *PileCD;
    PileCD = InitPile(PileCD);  // PileCD = NULL;

    PileCD = saisirPistesCD(PileCD);

    /*
    Piste P1, P2, P3;
    strcpy(P1.titre, "aa");
    strcpy(P1.artiste, "aa");
    P1.duree = 10;

    strcpy(P2.titre, "bb");
    strcpy(P2.artiste, "bb");
    P2.duree = 5;

    strcpy(P3.titre, "cc");
    strcpy(P3.artiste, "cc");
    P3.duree = 25;

    PileCD = empiler(PileCD,P1);
    PileCD = empiler(PileCD,P2);
    PileCD = empiler(PileCD,P3);
    */

    printf("\n******** La piste la plus courte est : ******** \n");
    Pile *pmin = min_Piste(PileCD);
    printf("Titre : (%s) \n", pmin->info.titre);
    printf("Nom et prénom : (%s) \n", pmin->info.artiste);
    printf("Duree : (%d) \n", pmin->info.duree);


    printf("\n******** les pistes ayant une durée > 10 min : ******** \n");
    Pile *PileSup10 = SupprimerToutesPistes(PileCD);
    AfficherPisteCD(PileSup10);

    printf("\n******** Les valeurs de PileCD sont : ******** \n");
	AfficherPisteCD(PileCD);


    return 0;
}
