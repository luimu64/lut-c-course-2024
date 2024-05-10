#include <stdlib.h>
#include <stdio.h>
#include "L7T2_lista.h"

int tulostaMenu()
{
    int vastaus;
    printf("1) Luo lista\n2) Lisää alkio listan loppuun\n3) Lisää alkio listan keskelle\n4) Tyhjennä lista\n5) Poista alkio listasta\n6) Tulosta lista\n0) Lopeta\nAnna valintasi: ");
    scanf("%d", &vastaus);
    return vastaus;
}

void tulostaAlkiot(LUKUALKIO *pAlku)
{
    LUKUALKIO *ptr;
    ptr = pAlku;
    while (ptr != NULL)
    {
        printf("%d ", ptr->iLuku);
        ptr = ptr->pSeuraava;
    }
    printf("\n");
}

void vapautaMuisti(LUKUALKIO **pAlku)
{
    LUKUALKIO *ptr = *pAlku;
    while (ptr != NULL)
    {
        *pAlku = ptr->pSeuraava;
        free(ptr);
        ptr = *pAlku;
    }
    *pAlku = NULL;
}

LUKUALKIO *haeAlkio(LUKUALKIO **pAlku, int sijainti)
{
    LUKUALKIO *ptr = *pAlku;
    for (int i = 1; ptr != NULL && i < sijainti; i++)
        ptr = ptr->pSeuraava;
    return ptr;
}

void poistaAlkio(int sij, LUKUALKIO **pAlku, LUKUALKIO **pLoppu)
{
    LUKUALKIO *poistettava;
    if (sij == 1)
    {
        poistettava = *pAlku;
        *pAlku = (*pAlku)->pSeuraava;
    }
    else
    {
        LUKUALKIO *aikaisempi = haeAlkio(pAlku, sij - 1);
        poistettava = aikaisempi->pSeuraava;
        aikaisempi->pSeuraava = poistettava->pSeuraava;
    }
    free(poistettava);
}

void lisaaAlkio(int sij, LUKUALKIO **pAlku, LUKUALKIO **pLoppu, int *index)
{
    LUKUALKIO *pUusi = (LUKUALKIO *)malloc(sizeof(LUKUALKIO));
    if (pUusi == NULL)
    {
        perror("Muistin varaus epäonnistui");
        exit(1);
    }
    pUusi->iLuku = *index;
    pUusi->pSeuraava = NULL;

    if (*pAlku == NULL) // tyhjä = ensimmäinen
    {
        *pAlku = pUusi;
        *pLoppu = pUusi;
    }
    else if (sij == 1) // ensimmäinen korvaus
    {
        pUusi->pSeuraava = *pAlku;
        *pAlku = pUusi;
    }
    else if (sij == -1) // loppuun lisäys
    {
        (*pLoppu)->pSeuraava = pUusi;
        *pLoppu = pUusi;
    }
    else // keskelle lisäys
    {
        LUKUALKIO *aikaisempi = haeAlkio(pAlku, sij - 1);
        pUusi->pSeuraava = aikaisempi->pSeuraava;
        aikaisempi->pSeuraava = pUusi;
    }
    (*index)++;
}

void luoLista(LUKUALKIO **pAlku, LUKUALKIO **pLoppu, int *koko, int *index)
{
    printf("Anna listan pituus: ");
    scanf("%d", koko);

    if (*koko < 0)
    {
        printf("listan pituus ei voi olla negatiivinen.\n");
        return;
    }
    else if (*koko == 0)
    {
        vapautaMuisti(pAlku);
        return;
    }

    if (*pAlku != NULL)
        vapautaMuisti(pAlku);

    for (int i = 0; i < *koko; i++)
    {
        lisaaAlkio(-1, pAlku, pLoppu, index);
    }

    tulostaAlkiot(*pAlku);
}