#ifndef ARBREFCTS_H_INCLUDED
#define ARBREFCTS_H_INCLUDED


struct node {
    char valeur;
    struct node *FilsG;
    struct node *FilsD;
};

typedef struct node Arbre;


Arbre* creationNoeud(char valeur) {
  /* dynamically allocate memory for a new Arbre */
  Arbre *newNode = malloc(sizeof(Arbre));

  /* populate valeur in new Node */
  newNode->valeur = valeur;
  newNode->FilsG = NULL;
  newNode->FilsD = NULL;

  return newNode;
}

/*
La fonction ci-dessous doit retourner  cet arbre :
            -
           / \
         +    /
        / \  / \
       +   z v  w
      / \
     x   y
*/
Arbre* ConstruireArbre(){
    // Root Node
    Arbre* root =  creationNoeud('-');

    root->FilsG = creationNoeud('+');
    root->FilsD = creationNoeud('/');

    root->FilsG->FilsG = creationNoeud('+');
    root->FilsG->FilsD = creationNoeud('z');
    root->FilsG->FilsG->FilsG = creationNoeud('x');
    root->FilsG->FilsG->FilsD = creationNoeud('y');

    root->FilsD->FilsG = creationNoeud('v');
    root->FilsD->FilsD = creationNoeud('w');

    return root;
}

int est_feuille(Arbre *nd)
{
  if(nd->FilsG==NULL && nd->FilsD==NULL)
    return 1;
  else
    return 0;
}

void parcoursInfixeParenthese(Arbre *A)
{
    if (est_feuille(A))
    {
        printf("%1c ",A->valeur);
    }
    else
    {
        printf("(");
        parcoursInfixeParenthese(A->FilsG);
        printf("%1c ",A->valeur);
        parcoursInfixeParenthese(A->FilsD);
        printf(")");
    }
}


#endif // ARBREFCTS_H_INCLUDED
