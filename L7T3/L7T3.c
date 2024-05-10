#include <stdio.h>
#include <stdlib.h>
#include "L7T3_io.h"
#include "L7T3_muisti.h"

int main(void)
{
    srand(1);

    int numeroMaara;
    int lisaNumeroMaara;

    printf("Lottoarvonta\n");
    printf("Kuinka monta numeroa arvotaan: ");
    scanf("%d", &numeroMaara);
    printf("Kuinka monta lisänumeroa arvotaan: ");
    scanf("%d", &lisaNumeroMaara);

    int *numerot = varaaMuistiaNumeroille(numeroMaara);
    int *lisaNumerot = varaaMuistiaNumeroille(lisaNumeroMaara);

    arvoNumerot(numerot, numeroMaara);
    arvoNumerot(lisaNumerot, lisaNumeroMaara);

    printf("\nArvottiin seuraavat numerot ja lisänumerot.\n");
    printf("Numerot: ");
    tulostaNumerot(numerot, numeroMaara);
    printf("Lisänumerot: ");
    tulostaNumerot(lisaNumerot, lisaNumeroMaara);

    printf("Kiitos ohjelman käytöstä.\n");
    return 0;
}