
#define TRUE  1
#define FALSE 0

struct noeud
{
    int valeur;
    struct noeud *FilsG;
    struct noeud *FilsD;
};

typedef struct noeud Arbre;


Arbre* creationNoeud(int valeur)
{
    /* Dynamically allocate memory for a new noeud */
    Arbre *newnoeud = malloc(sizeof(Arbre));

    /* Check if memory allocation was successful */
    if (newnoeud == NULL)
    {
        fprintf(stderr, "Erreur: Impossible d'allouer de la mémoire\n");
        exit(0);
    }

    /* Populate valeur in new noeud */
    newnoeud->valeur = valeur;
    newnoeud->FilsG = NULL;
    newnoeud->FilsD = NULL;

    return newnoeud;
}


/*
This function returns below tree
            30
           /  \
         20    60
        / \    / \
       14  25 35 70
      / \
     8  19
*/

Arbre* ConstruireArbre1(){
    // Root noeud
    Arbre *root =  creationNoeud(30);

    root->FilsG = creationNoeud(20);
    root->FilsD = creationNoeud(60);

    root->FilsG->FilsG = creationNoeud(14);
    root->FilsG->FilsD = creationNoeud(25);
    root->FilsD->FilsG = creationNoeud(35);
    root->FilsD->FilsD = creationNoeud(70);

    root->FilsG->FilsG->FilsG = creationNoeud(8);
    root->FilsG->FilsG->FilsD = creationNoeud(19);

    return root;
}

/*
This function returns below tree
            30
           /  \
         20    60
        / \    / \
       14  25 35 70
      / \
     8  19
*/
Arbre* ConstruireArbre2(){
    // Root noeud
    Arbre *root =  creationNoeud(30);

    root->FilsG = creationNoeud(20);
    root->FilsD = creationNoeud(60);

    root->FilsG->FilsG = creationNoeud(14);
    root->FilsG->FilsD = creationNoeud(25);
    root->FilsD->FilsG = creationNoeud(35);
    root->FilsD->FilsD = creationNoeud(70);

    root->FilsG->FilsG->FilsG = creationNoeud(8);
    root->FilsG->FilsG->FilsD = creationNoeud(19);

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

// Question 1
int verif(Arbre *root, int x) {
    if (root == NULL)
    {
        return FALSE;
    }
    else
        if (root->valeur == x)
        {
            return TRUE;
        }
        else
        {
        // Utilisation de l'opérateur logique "||" pour vérifier la valeur dans les deux sous-arbres
            return (verif(root->FilsG, x) || verif(root->FilsD, x));
        }
}



//Question 2
// Checks, if two trees are same or not
        /*
        A1  30         A2   30
           /  \            /  \
         20    60        20    60

        */
// Cette fonction vérifie si les arbres a1 et a2 sont identiques.
int estIdentique(Arbre *a1, Arbre *a2) {
    // Si les deux arbres sont vides, ils sont identiques
    // ou les deux pointeurs A1 et A2 ont atteint les feuilles sans retourner faux
    if (a1 == NULL && a2 == NULL)
    {
        return TRUE;
    }

    // Si un seul des arbres est vide ou si les valeurs des racines sont différentes, ils ne sont pas identiques
    if (a1 == NULL || a2 == NULL || a1->valeur != a2->valeur) {
        return FALSE;
    }
    else
    // Sinon, vérifiez récursivement les sous-arbres gauche et droit
    return estIdentique(a1->FilsG, a2->FilsG) && estIdentique(a1->FilsD, a2->FilsD);
}



// Question 3
// Cette fonction vérifie si a1 est un sous-arbre de a2.
int verifSousArbre(Arbre *a1, Arbre *a2) {
    // Si a2 est NULL, cela signifie que nous avons descendu tous les niveaux de l'arbre a2
    //sans trouver a1. Donc, a1 ne peut pas être un sous-arbre de a2, nous retournons donc FALSE.
    if (a2 == NULL)
    {
        return FALSE;
    }

    //Pour retouner true, on a 2 cas :
    // 1) Si a1 est NULL, cela signifie que nous avons descendu tout les niveaux de l'arbre a1
    //et que nous n'avons trouvé aucune différence avec a2.
    //Donc, a1 est un sous-arbre de a2, nous retournons donc TRUE.

    // 2) Aussi, Si l'arbre avec a1 comme racine est identique à l'arbre avec a2 comme nœud racine,
    // alors a1 est un sous-arbre de a2, nous retournons donc TRUE.
    if (a1 == NULL || estIdentique(a1, a2) == TRUE)
    {
        return TRUE;
    }
    else
    // Sinon, de manière récursive, nous vérifions si a1 est un sous-arbre de l'un des sous-arbres de a2.
    // Nous appelons récursivement la fonction verifSousArbre avec les sous-arbres gauche et droit de a2.
        return (verifSousArbre(a1, a2->FilsG) || verifSousArbre(a1, a2->FilsD));
}


