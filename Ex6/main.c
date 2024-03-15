#include <stdio.h>
#include <stdlib.h>
#include "ArbreFcts.h"


int main()
{
    Arbre *root = ConstruireArbre();
    parcoursInfixeParenthese(root);

    return 0;
}
