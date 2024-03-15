
struct node {
    int valeur;
    struct node *FilsG;
    struct node *FilsD;
};
typedef struct node Arbre;


Arbre* creationNoeud(int valeur)
{
  /* dynamically allocate memory for a new Arbre */
  Arbre *newNode = malloc(sizeof(Arbre));

  /* populate valeur in new Node */
  newNode->valeur = valeur;
  newNode->FilsG = NULL;
  newNode->FilsD = NULL;

  return newNode;
}



Arbre * Ajout_Rec(Arbre *root, int x)
{
    //searching for the place to insert
    if(root==NULL)
        return creationNoeud(x);
    else
    {
        if(x > root->valeur) // x is greater. Should be inserted to right
            root->FilsD = Ajout_Rec(root->FilsD, x);
        else // x is smaller should be inserted to left
            root->FilsG = Ajout_Rec(root->FilsG,x);
    }

    return root;
}


void infixe(Arbre *root)
{
    if(root!=NULL) // checking if the root is not null
    {
        infixe(root->FilsG); // visiting left child
        printf(" %d ", root->valeur); // printing valeur at root
        infixe(root->FilsD);// visiting right child
    }
}

int SommeNodes(Arbre *A)
{
    if (A == NULL)
        return 0;
    else
        return  A->valeur + SommeNodes(A->FilsG) + SommeNodes(A->FilsD);
}

int SommeFeuilles(Arbre *A)
{
    if (A == NULL)
        return 0;
    else
    {
       if(A->FilsG==NULL && A->FilsD==NULL)
            return  A->valeur;
        else
            return  0 + SommeFeuilles(A->FilsG) + SommeFeuilles(A->FilsD);

    }
}

void miroir (Arbre *racine)
{
    Arbre *aux;

	if(racine != NULL) // checking if the racine is null
    {
        miroir(racine->FilsG);
        miroir (racine->FilsD);

        //On permute le neud ainsi que ses valeurs
        //donc "int aux" est faux !!!
        Arbre *aux = racine->FilsG;
        racine->FilsG = racine->FilsD;
        racine->FilsD = aux;
    }
}

