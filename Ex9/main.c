#include <stdio.h>
#include "ArbreFcts.h"

int main()
{
    int val;

    Arbre *root1 = ConstruireArbre1();
    Arbre *root2 = ConstruireArbre2();


    // Question 1
    printf("Donner la valeur à chercher : \n");
    scanf("%d", &val);

    if(verif(root1, val)== 1)
        printf("La valeur %d existe dans l'arbre \n", val);
    else
        printf("La valeur %d n'existe pas dans l'arbre \n", val);


    // Question 2
    printf("\n ************************* \n");
     if(estIdentique(root1, root2))
        printf("True : Arbre 1 est identique à l'arbre 2 \n");
    else
        printf("False : Arbre 1 n'est pas identique à l'arbre 2 \n");


                    //root1 : Arbre principal
                    //root2 : sousArbre
    if(verifSousArbre(root1, root2))
        printf("True : Arbre 2 est inclus à l'arbre 2 \n");
    else
        printf("False : Arbre 2 n'est pas inclus à l'arbre 2 \n");

    return 0;
}
