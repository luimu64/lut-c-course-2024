#include <stdio.h>
#include <stdlib.h>
#include "L7T3_muisti.h"

int *varaaMuistiaNumeroille(int maara)
{
    int *pMuistilohko;
    if ((pMuistilohko = (int *)malloc(maara * sizeof(int))) == NULL)
    {
        perror("Muistin varaus epäonnistui");
        exit(1);
    }
    return pMuistilohko;
}

void vapautaMuisti(int *pMuistiLohko)
{
    free(pMuistiLohko);
    printf("Muisti vapautettu.\n");
}