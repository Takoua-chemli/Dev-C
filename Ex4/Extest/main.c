#include <stdio.h>
#include <stdlib.h>

struct element
{
    int valeur;
    struct element *suivant;
};

typedef struct element Liste;


Liste * ajouterEnTete(Liste *list)
{
    /* On crée un nouvel élément */
    Liste *nouvelElement = malloc(sizeof(Liste));

    /* On assigne la valeur au nouvel élément */
     printf("Donner une valeur a inserer : ");
     scanf("%d",&nouvelElement->valeur);

    /* On assigne l'adresse de l'élément suivant au nouvel élément */
    nouvelElement->suivant = list;

    /* On retourne la nouvelle list, i.e. le pointeur sur le premier élément */
    return nouvelElement;
}

int sm_mult(Liste *tete, int V)
{
    if(tete == NULL)
        return 0;
    else
    {
        if(tete->valeur % V == 0)
            return tete->valeur + sm_mult(tete->suivant, V);
        else
            return sm_mult(tete->suivant,V);
    }
}


int Longueur(Liste *tete)
{
    int nb=0;
    Liste *p;
    p=tete;

	if(p==NULL)
		return(0);
	else
	{
		while(p != NULL)
		{
			nb++;
			p=p->suivant;
		}
	}
    return nb;
}



int main()
{
    printf("Hello world!\n");
    return 0;
}
