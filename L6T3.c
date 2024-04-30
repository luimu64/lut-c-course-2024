#include <stdio.h>
#include <stdlib.h>

typedef struct lukuAlkio
{
    int iLuku;
    struct lukuAlkio *pSeuraava;
} LUKUALKIO;

int tulostaMenu()
{
    int vastaus;
    printf("1) Tulosta listan alkiot\n2) Muuta listan pituutta\n0) Lopeta\nAnna valintasi: ");
    scanf("%d", &vastaus);
    return vastaus;
}

void tulostaAlkiot(LUKUALKIO *pAlku, int koko)
{
    LUKUALKIO *ptr;
    ptr = pAlku;
    printf("Listassa on seuraavat luvut: \n");
    while (ptr != NULL)
    {
        printf("%d ", ptr->iLuku);
        ptr = ptr->pSeuraava;
    }
    printf("\n");
}

void vapautaMuisti(LUKUALKIO *pAlku)
{
    LUKUALKIO *ptr;
    ptr = pAlku;
    while (ptr != NULL)
    {
        pAlku = ptr->pSeuraava;
        free(ptr);
        ptr = pAlku;
    }
}

void luoLista(LUKUALKIO **pAlku, LUKUALKIO **pLoppu, int koko)
{
    printf("Anna listan uusi pituus: ");
    scanf("%d", &koko);

    if (koko < 0)
    {
        printf("listan pituus ei voi olla negatiivinen.\n");
        return;
    }

    if (koko == 0)
    {
        free(*pAlku);
        *pAlku = NULL;
        return;
    }

    if (*pAlku != NULL)
    {
        vapautaMuisti(*pAlku);
        *pAlku = NULL;
    }

    for (int i = 0; i < koko; i++)
    {
        LUKUALKIO *pUusi = (LUKUALKIO *)malloc(sizeof(LUKUALKIO));
        if (pUusi == NULL)
        {
            perror("Muistin varaus epäonnistui");
            exit(1);
        }
        pUusi->iLuku = i;
        pUusi->pSeuraava = NULL;

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
}

int main(void)
{
    int vastaus;
    int koko = 0;
    LUKUALKIO *pAlku = NULL, *pLoppu = NULL;

    while ((vastaus = tulostaMenu()) != 0)
    {
        if (vastaus == 1)
        {
            if (pAlku != NULL)
                tulostaAlkiot(pAlku, koko);
            else
                printf("Lista on tyhjä.\n");
        }

        else if (vastaus == 2)

            luoLista(&pAlku, &pLoppu, koko);

        else
            printf("Tuntematon valinta, yritä uudestaan.");
    }

    vapautaMuisti(pAlku);
    printf("Kiitos ohjelman käytöstä.\n");
    return (0);
}
