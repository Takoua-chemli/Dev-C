struct noeud {
    int annee_de_naissance;
    char nom;
    char prenom;
    char sexe;
    struct noeud *FilsG;
    struct noeud *FilsD;
};
typedef struct noeud Arbre;

Arbre* creationNoeud(int _annee, char _nom, char _prenom, char _sexe) {
    Arbre *A = malloc(sizeof(Arbre));
    A->annee_de_naissance = _annee;
    A->nom = _nom;
    A->prenom = _prenom;
    A->sexe = _sexe;
    A->FilsG = NULL;
    A->FilsD = NULL;
    return A;
}

Arbre* Ajout_Rec(Arbre *A, int _annee, char _nom, char _prenom, char _sexe) {
    if (A == NULL)
        return creationNoeud(_annee, _nom, _prenom, _sexe);
    else {
        if (_annee <= (A->annee_de_naissance))
            A->FilsG = Ajout_Rec(A->FilsG, _annee, _nom, _prenom, _sexe);
        else
            A->FilsD = Ajout_Rec(A->FilsD, _annee, _nom, _prenom, _sexe);
    }
    return A;
}

void afficheOrdreCroissant(Arbre *A) {
    if (A != NULL) {
        afficheOrdreCroissant(A->FilsG);
        printf("%d \t %c \t %c \t %c \n", A->annee_de_naissance, A->nom, A->prenom, A->sexe);
        afficheOrdreCroissant(A->FilsD);
    }
}

int Nombre_de_personne(Arbre *A) {
    if (A == NULL)
        return 0;
    else
        return 1 + Nombre_de_personne(A->FilsG) + Nombre_de_personne(A->FilsD);
}

int Nombre_hommes(Arbre *A) {
    if (A == NULL)
        return 0;
    else {
        if (A->sexe == 'H')
            return 1 + Nombre_hommes(A->FilsG) + Nombre_hommes(A->FilsD);
        else
            return 0 + Nombre_hommes(A->FilsG) + Nombre_hommes(A->FilsD);
    }
}

int Nombre_femmes(Arbre *A) {
    if (A == NULL)
        return 0;
    else {
        if (A->sexe == 'F')
            return 1 + Nombre_femmes(A->FilsG) + Nombre_femmes(A->FilsD);
        else
            return 0 + Nombre_femmes(A->FilsG) + Nombre_femmes(A->FilsD);
    }
}

