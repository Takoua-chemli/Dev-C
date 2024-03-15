#ifndef PILEFCTS_H_INCLUDED
#define PILEFCTS_H_INCLUDED

typedef int boolean;
#define true 1
#define false 0

struct cellule{
int valeur;
struct cellule *suivant;
};
typedef struct cellule cellule;

// File
struct file
{
    cellule *tete;
    cellule *queue;
};


typedef struct cellule Pile;
typedef struct file file;

// Les fonctions de pile

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
//return (P=NULL);
}

Pile * empiler(Pile *P, int x)
{
    Pile *Q;
    Q=malloc(sizeof(Pile));
    Q->valeur=x;
    Q->suivant=P;

    /* On retourne la nouvelle liste, i.e. le pointeur sur le premier élément */
    return Q;
}

Pile * depiler(Pile *P, int *x)  // *x car on a 2 retours !!!
{
    Pile *Q;

    if (!Pile_vide(P))
    {
        *x=P->valeur;
        Q = P;
        P=P->suivant;
        free(Q);
        //printf("La valeur depilée est : %d \n\n", *x);

    }
    else
    {
        printf("Impossible, la Pile est vide !!! \n");
    }

    return P;
}


void afficherPile(Pile *P)
{
    while (P != NULL)
    {
        printf(" (%d) \n",P->valeur);
        P=P->suivant;
    }
}

// Les fonctions de la file

void Init_File(file *q)
{
    q->tete = NULL;
    q->queue = NULL;
}

int File_vide(file *q)
{
    return (q->tete == NULL);
}

void enfiler(file *q, float value)
{
        cellule *tmp;
        tmp = malloc(sizeof(cellule));
        tmp->valeur = value;
        tmp->suivant = NULL;

        if(File_vide(q))
        {
            q->tete = q->queue = tmp;
        }
        else
        {
            q->queue->suivant = tmp;
            q->queue = tmp;
        }
}

int defiler(file *q)
{
    cellule *tmp;

    if(File_vide(q))
    {
        printf("Impossible, la file est vide \n");
        return -1;
    }
    else
    {
        int n = q->tete->valeur;
        tmp = q->tete;
        q->tete = q->tete->suivant;
        free(tmp);
        if(q->tete == NULL)
        {
            q->queue == NULL;
        }

        return(n);
    }
}

void AfficheFile(cellule *q)
{
    if(q == NULL)
    {
        printf("NULL\n");
    }
    else
    {
        printf("%d\t", q->valeur);
        AfficheFile(q->suivant);
    }
}

///////////////////////////

Pile* inverser(Pile *P1)
{
	int valdepilee, valdefilee;

	file *f = malloc(sizeof(file));

    Init_File(f);

	while(!Pile_vide(P1))
	{
        P1 = depiler(P1,&valdepilee);
        enfiler(f, valdepilee);
	}

	while(!File_vide(f))
	{
        valdefilee = defiler(f);
		P1=empiler(P1,valdefilee);
	}

	return P1;
}


#endif // PILEFCTS_H_INCLUDED
