#include <stdio.h>
#include <stdlib.h>
#include "Filefcts.h"


int main()
{
    char c;
    file *F1 = malloc(sizeof(file));
    Init_File(F1);

    enfiler(F1,'A');
    enfiler(F1,'B');
    enfiler(F1,'C');
    enfiler(F1,'D');
    enfiler(F1,'E');
    enfiler(F1,'F');
    enfiler(F1,'G');


    AfficheFile(F1->tete);

    printf("Donner la valeur à défiler : \n");
    scanf("%c",&c);

    afficherJusqua(F1, c);

    return 0;
}
