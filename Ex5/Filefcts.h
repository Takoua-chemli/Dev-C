#ifndef FILEFCTS_H_INCLUDED
#define FILEFCTS_H_INCLUDED


typedef int boolean;
#define true 1
#define false 0

struct element{
char valeur;
struct element *suivant;
};
typedef struct element element;

// File
struct file
{
    element *tete;
    element *queue;
};

typedef struct file file;


void Init_File(file *q)
{
    q->tete = NULL;
    q->queue = NULL;
}

int File_vide(file *q)
{
    return (q->tete == NULL);
}

void enfiler(file *q, char value)
{
        element *tmp;
        tmp = malloc(sizeof(element));
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
    element *tmp;

    if(File_vide(q))
    {
        printf("Impossible, la file est vide");
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

void AfficheFile(element *f)
{
    if(f == NULL)
    {
        printf("\n");
    }
    else
    {
        printf("%c\t", f->valeur);
        AfficheFile(f->suivant);
    }
}
int existe(file *Fmots, char x)
{
    // S : Pointeur sur la liste de la file pour faire le parcours et garder la trace Fmots->tete
    element *S = Fmots->tete;

	while(S != NULL)
	{
		if (S->valeur == x)
                return 1; // retourner 1 et quitter la boucle !!
                         // 2eme solution avec une variable exit=0 etc
        else
            S = S->suivant;
	}

    return 0;
}


//version itérative
void AfficheFileIt(file *Fmots)
{
    element *S;
    S = Fmots->tete;

    printf("Le contenu de la file est le suivant :\n");
    while(S != NULL)
    {
        printf("%c\t", S->valeur);
        S = S->suivant;
    }
}


//version récursive
 //recevoir l'@ la liste pointé par tete
void AfficheFileRec(element *tete)
{
   if(tete == NULL)
    {
        printf("\n");
    }
    else
    {
        printf("%c\t", tete->valeur);
        AfficheFileRec(tete->suivant);
    }
}

                                    //'c'
void afficherJusqua(file *Fmots, char elt)
{
    // S : Pointeur sur la liste de la file pour faire le parcours et garder la trace Fmots->tete
    element *S;
    int exist = 0;

    // caractère cherché existe !!
    if(existe(Fmots, elt) == 1)
    {
        S = Fmots->tete;

        while(S != NULL && exist == 0)
        {
            if(S->valeur == elt)
            {
                exist = 1;
            }
            else
            {
                printf("La valeur est %c \n", S->valeur);
                S = S->suivant;
            }
        }
    }
    else // caractère cherché n'existe pas!!
    {
        printf("\n\n %c est inexistant !!!\n", elt);
        AfficheFileIt(Fmots);
    }
}

#endif // FILEFCTS_H_INCLUDED
