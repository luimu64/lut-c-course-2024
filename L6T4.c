#include <stdio.h>
#include <stdlib.h>

typedef struct lukuAlkio
{
    int iLuku;
    struct lukuAlkio *pSeuraava;
} LUKUALKIO;

enum eSijainti
{
    loppuun = 1,
    keskelle = 0
};

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
    LUKUALKIO *ptr;
    ptr = *pAlku;
    while (ptr != NULL)
    {
        *pAlku = ptr->pSeuraava;
        free(ptr);
        ptr = *pAlku;
    }
    *pAlku = NULL;
}

void lisaaAlkio(enum eSijainti sij, LUKUALKIO **pAlku, LUKUALKIO **pLoppu, int index)
{
    LUKUALKIO *pUusi = (LUKUALKIO *)malloc(sizeof(LUKUALKIO));
    if (pUusi == NULL)
    {
        perror("Muistin varaus epäonnistui");
        exit(1);
    }
    pUusi->iLuku = index;
    pUusi->pSeuraava = NULL;

    if (sij == loppuun) // loppuun
    {
        if (*pAlku == NULL)
        {
            *pAlku = pUusi;
            *pLoppu = pUusi;
        }
        else
        {
            (*pLoppu)->pSeuraava = pUusi;
            *pLoppu = pUusi;
        }
    }
    else // keskelle
    {
    }
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
        lisaaAlkio(loppuun, pAlku, pLoppu, *index);
        (*index)++;
    }

    tulostaAlkiot(*pAlku);
}

int main(void)
{
    int vastaus;
    int koko = 0;
    int index = 1;
    LUKUALKIO *pAlku = NULL, *pLoppu = NULL;

    printf("Tämä ohjelma hallitsee listaa ja sen alkioita.\n");
    while ((vastaus = tulostaMenu()) != 0)
    {
        switch (vastaus)
        {
        case 1:
            luoLista(&pAlku, &pLoppu, &koko, &index);
            break;
        case 2:
            lisaaAlkio(1, &pAlku, &pLoppu, index);
            tulostaAlkiot(pAlku);
            index++;
            break;
        case 4:
            vapautaMuisti(&pAlku);
            break;
        case 6:
            if (pAlku != NULL)
                tulostaAlkiot(pAlku);
            else
                printf("\n");
            break;

        default:
            printf("Tuntematon valinta, yritä uudestaan.");
            break;
        }
    }

    vapautaMuisti(&pAlku);
    printf("Kiitos ohjelman käytöstä.\n");
    return (0);
}
