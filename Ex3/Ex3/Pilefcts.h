#ifndef PILEFCTS_H_INCLUDED
#define PILEFCTS_H_INCLUDED

struct element
{
    char titre[20];
    char artiste[30];
    int duree;
};
typedef struct element Piste;


struct cellule
{
    Piste info;
    struct cellule *suivant;
};
typedef struct cellule Pile;


Pile* InitPile(Pile *P)
{
	P=NULL;
	return P;
}


int Pile_vide(Pile *P)
{
if (P==NULL)
	return 1;
else
	return 0;

//ou
//return (P==NULL);
}


//Empiler
Pile* insererPiste(Pile *PileCD, Piste P)
{
    Pile *nv;
    nv=malloc(sizeof(Pile));

    nv->info = P;

    /* ou bien
    strcpy(nv->info.titre, P.titre);
    strcpy(nv->info.artiste, P.artiste);
    nv->info.duree = P.duree;
    */

    nv->suivant=PileCD;
    PileCD = nv;

    return nv;
}


Pile* saisirPistesCD(Pile *PileCD)
{
    char rep;
    Piste P;

    do{

        fflush(stdin);
        printf("Donner le titre de la piste : \n");
		gets(P.titre);

        printf("Donner le nom et prénom de l'artiste : \n");
        gets(P.artiste);

        printf("Donner la duree : \n");
        scanf("%d",&P.duree);

        PileCD = insererPiste(PileCD,P);


        do{
            fflush(stdin);
			printf("Voulez vous continuer (O/N) \n");
			scanf("%c",&rep);
		   }while(!(rep=='n' || rep=='N' || rep=='o' || rep=='O'));
           fflush(stdin);

	}while(!(rep=='n' || rep=='N'));

    return PileCD;
}


Pile* min_Piste(Pile *PileCD)
{
    int minduree = PileCD->info.duree;
    Pile *pmin = PileCD;

    PileCD = PileCD->suivant;
    while (Pile_vide(PileCD)==0)
    {
        if(PileCD->info.duree < minduree)
            {
                minduree = PileCD->info.duree;
                pmin = PileCD;
            }

        PileCD = PileCD->suivant;
    }

    return pmin;
}


//Dépiler
Pile* SupprimerPiste(Pile *PileCD, Piste *P)  // *P car on a 2 retours !!!
{
    Pile *S;

    if (Pile_vide(PileCD)) // if(PileCD == NULL)
    {
        printf("Impossible, la Pile est vide !!! \n");
    }
    else
    {
        strcpy(P->titre, PileCD->info.titre);
        strcpy(P->artiste, PileCD->info.artiste);
        P->duree = PileCD->info.duree;

        S = PileCD;
        PileCD = PileCD->suivant;
        free(S);
    }

    return PileCD;
}

Pile* SupprimerToutesPistes(Pile *PileCD)
{
    Pile *pile_temp;
	pile_temp = InitPile(pile_temp);

	Piste valeur_depilee;

	while(!Pile_vide(PileCD))
	{
        PileCD=SupprimerPiste(PileCD, &valeur_depilee);

        if(valeur_depilee.duree >= 10)
        {
            pile_temp = insererPiste(pile_temp, valeur_depilee);
        }
	}

    while(!Pile_vide(pile_temp))
	{
        pile_temp=SupprimerPiste(pile_temp, &valeur_depilee);
        PileCD=insererPiste(PileCD, valeur_depilee);
	}


    return PileCD; // car on va retourner la pile remplie  par la nouvelle valeur !!
}

//version itérartive
void AfficherPisteCD(Pile *PileCD)
{
    int i=1;

    while (PileCD != NULL)
    {
        printf("Les informations du piste %d : \n", i++);
        printf("Titre : (%s) \n", PileCD->info.titre);
        printf("Nom et prénom : (%s) \n",PileCD ->info.artiste);
        printf("Duree : (%d) \n", PileCD ->info.duree);

        PileCD = PileCD->suivant;
    }
}


//version récursive
void afficherRec(Pile *PileCD)
{
	if(PileCD !=NULL)
    {
        printf("Titre : (%s) \n", PileCD->info.titre);
        printf("Nom et prénom : (%s) \n",PileCD ->info.artiste);
        printf("Duree : (%d) \n", PileCD ->info.duree);

        afficherRec(PileCD->suivant);
    }
}


#endif // PILEFCTS_H_INCLUDED
