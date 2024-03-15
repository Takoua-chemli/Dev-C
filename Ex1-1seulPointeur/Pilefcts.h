#ifndef PILEFCTS_H_INCLUDED
#define PILEFCTS_H_INCLUDED


struct Pile{
    int valeur;
    struct cellule *suivant;
};

typedef struct Pile         Pile;


Pile * InitPile(Pile *P)
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

Pile* depiler(Pile *P, int *x)  // *x car on a 2 retours !!!
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

// Utility function to return the top element of the stack
int sommet(Pile *P)
{
    // check for an empty stack
    if (Pile_vide(P)==0)
    {
        return P->valeur;
    }
    else
    {
        printf("La pile est vide !!\n");
        exit(EXIT_FAILURE);
    }
}


void afficherit(Pile *P)
{
    printf("Les valeurs de la pile sont : \n");

    while (P != NULL)
    {
        printf(" (%d) \n",P->valeur);
        P=P->suivant;
    }
}


void afficherRec(Pile *P)
{
    if (Pile_vide(P)==0)
    {
        printf(" (%d) \n",P->valeur);
        afficherRec(P->suivant);
    }
}

//Question 1
Pile* chercher(Pile *P, int valeurrecherche)
{
    int exist = 0;
    Pile *S;

    S=P; //garder le somment de la pile car après le parcours (while)
         //on trouve P pointée sur NULL (fin Pile) et nous voulons
         //faire l'insertion de "valeurrecherche" en tete de Pile

	while(Pile_vide(P)==0 && exist == 0)
	{
		if (P->valeur ==valeurrecherche)
            exist = 1;
        else
            P = P->suivant;
	}

	if(exist == 0)
    {
        P = empiler(S, valeurrecherche);
        return P;
    }
	else
    {
        printf("La valeur existe !!!  \n");
        return S;
    }
}

//Question 2
Pile * chercherTrie(Pile *P, int valeurrecherche)
{
    Pile *pile_temp;
	pile_temp = InitPile(pile_temp);

	int valeur_depilee;

                        // < ou > ca depend min les valeurs ordre croissant ou croissant
	while(!Pile_vide(P) && P->valeur > valeurrecherche)
	{
            P=depiler(P, &valeur_depilee);
	        //printf("%d \n", valeur_depilee);
            pile_temp = empiler(pile_temp, valeur_depilee);
	}


    if(Pile_vide(P)==1 || P->valeur<valeurrecherche)
   {
		printf("La valeur n'existe pas !!!  \n");
		P = empiler(P, valeurrecherche);
	}
	else
     {
         printf("La valeur existe !!!  \n");
     }


    while(Pile_vide(pile_temp)==0)
	{
        pile_temp=depiler(pile_temp, &valeur_depilee);
        P=empiler(P, valeur_depilee);
	}

    return P; // car on va retourner la pile remplie  par la nouvelle valeur !!
}


Pile* sup_val_neg(Pile *P)
{
    Pile *pile_temp;
	pile_temp = InitPile(pile_temp);

	int valeur_depilee;
	while(Pile_vide(P)==0)
	{
        P=depiler(P, &valeur_depilee);
        //printf("%d \n", valeur_depilee);
        if(valeur_depilee>0)
        {
            pile_temp = empiler(pile_temp, valeur_depilee);
        }
	}

    while(Pile_vide(pile_temp)==0)
	{
        pile_temp=depiler(pile_temp, &valeur_depilee);
        P=empiler(P, valeur_depilee);
	}


    return P; // car on va retourner la pile remplie  par la nouvelle valeur !!
}


#endif // PILEFCTS_H_INCLUDED
