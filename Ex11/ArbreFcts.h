
struct noeud {
    int valeur;
    struct noeud *FilsG;
    struct noeud *FilsD;
};

typedef struct noeud Arbre;


struct element {
    Arbre *rac;
    struct element *suivant;
};

typedef struct element Larb;


Larb * ajouterEnTete(Larb *list, Arbre *racine)
{
    /* On cr�e un nouvel �l�ment */
    Larb *nouvelElement = malloc(sizeof(Larb));

     nouvelElement->rac=racine;

    /* On assigne l'adresse de l'�l�ment suivant au nouvel �l�ment */
    nouvelElement->suivant = list;

    return nouvelElement;
}



Arbre* creationNoeud(int valeur) {
  /* dynamically allocate memory for a new Arbre */
  Arbre *newnoeud = malloc(sizeof(Arbre));

  /* populate valeur in new noeud */
  newnoeud->valeur = valeur;
  newnoeud->FilsG = NULL;
  newnoeud->FilsD = NULL;

  return newnoeud;
}

Arbre * Ajout_Arbre(Arbre *racine, int x)
{
    //searching for the place to insert
    if(racine==NULL)
        return creationNoeud(x);
    else
        if(x>racine->valeur) // x is greater. Should be inserted to right
            racine->FilsD = Ajout_Arbre(racine->FilsD, x);
        else // x is smaller should be inserted to left
            racine->FilsG = Ajout_Arbre(racine->FilsG,x);

    return racine;
}


void infixe(Arbre *racine)
{
    if(racine!=NULL) // checking if the racine is not null
    {
        infixe(racine->FilsG); // visiting left child
        printf(" %d ", racine->valeur); // printing valeur at racine
        infixe(racine->FilsD);// visiting right child
    }
}

void AffichListe(Larb *list)
{
    if(list == NULL)   // Optionel, juste pour afficher NULL � la fin
        printf("NULL\n");
    else
        AffichListe(list->suivant);
}

Arbre* chercherInArbre(Arbre *racine, int x)
{
    if(racine==NULL || racine->valeur==x) //if racine->data is x then the element is found
        return racine;
    else
        if(x>racine->valeur) // x is greater, so we will search the right subtree
            return chercherInArbre(racine->FilsD, x);
        else //x is smaller than the data, so we will search the left subtree
            return chercherInArbre(racine->FilsG,x);
}



Arbre * chercherL(Larb *tete, int V)
{
Larb *p = NULL;   // @d'element cherch� (soit NIL soit @noeud)
while(tete != NULL && p==NULL)  //P==NULL pour dire l'el�ment n'est pas encore trouv� !!
{
    p = chercherInArbre(tete->rac, V);
	tete = tete->suivant;
}
return p;
}


// Suppression de liste
Larb * suppL(Larb *tete)
{
    Larb *p;
    while(tete != NULL)
    {
        p = tete;
        tete = tete->suivant;
        suppA(p->rac); // supprimer le sous arbre
        free(p);       // supprimer l'�l�ment courant de la liste
    }

    return tete;
}

void suppA(Arbre *rac)
{
    if(rac != NULL)
    {
        suppA(rac->FilsG);
        free(rac);
        suppA(rac->FilsD);
    }
}

