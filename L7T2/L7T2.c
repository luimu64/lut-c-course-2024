#include <stdlib.h>
#include <stdio.h>
#include "L7T2_lista.h"

int main(void)
{
    int vastaus;
    int koko = 0;
    int index = 1;
    int sijainti;
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
            lisaaAlkio(-1, &pAlku, &pLoppu, &index);
            tulostaAlkiot(pAlku);
            break;
        case 3:
            printf("Monenneksi solmuksi alkio lisätään: ");
            scanf("%d", &sijainti);
            lisaaAlkio(sijainti, &pAlku, &pLoppu, &index);
            tulostaAlkiot(pAlku);
            break;
        case 4:
            vapautaMuisti(&pAlku);
            break;
        case 5:
            printf("Monesko alkio poistetaan: ");
            scanf("%d", &sijainti);
            poistaAlkio(sijainti, &pAlku, &pLoppu);
            tulostaAlkiot(pAlku);
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
