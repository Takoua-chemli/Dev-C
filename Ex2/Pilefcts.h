#ifndef PILEFCTS_H_INCLUDED
#define PILEFCTS_H_INCLUDED

typedef int boolean;
#define true 1
#define false 0


struct cellule{
int valeur;
struct cellule *suivant;
};
typedef struct cellule Pile;


Pile * InitPile(Pile *P)
{
	P=NULL;
	return P;
}

boolean Pile_vide(Pile *P)
{
if (P==NULL)
	return true;
else
	return false;

//ou
//return (P==NULL);
}


Pile * empiler(Pile *P, int x)
{
    Pile *nv;
    nv=malloc(sizeof(Pile));
    nv->valeur=x;
    nv->suivant=P;
	P=nv;

    /* On retourne la nouvelle liste, i.e. le pointeur sur le premier élément */
    return nv;
}

Pile * depiler(Pile *P, int *x)  // *x car on a 2 retours !!!
{
    Pile *S;

    if (Pile_vide(P)==1)
    {
        printf("Impossible, la Pile est vide !!! \n");
    }
    else
    {
        *x=P->valeur;
        S = P;
        P=P->suivant;
        free(S);
        //printf("La valeur depilée est : %d \n\n", *x);
    }

    return P;
}



void afficher(Pile *P)
{
    while (P != NULL)
    {
        printf(" (%d) \n",P->valeur);
        P=P->suivant;
    }
}


//version récursive
int existeRecursive(Pile *P, int valeurrecherche)
{
    if(Pile_vide(P))
        return 0;
    else
    {
        if(P->valeur == valeurrecherche)
            return 1;
        else
            return existeRecursive(P->suivant, valeurrecherche);
    }
}


Pile* creer_pileP3(Pile *P1, Pile *P2)
{
	Pile *Ptemp;
	Ptemp = InitPile(Ptemp);

	int valeur_depilee;

	while(!Pile_vide(P1))
	{
		P1=depiler(P1, &valeur_depilee);

		if(! existeRecursive(P2,valeur_depilee))
			Ptemp = empiler(Ptemp,valeur_depilee);
	}

	return Ptemp;
}

#endif // PILEFCTS_H_INCLUDED
