#include <stdio.h>
#include <stdlib.h>
#include "L7T3_io.h"

int tarkistaNumero(int *taulukko, int tarkistettava, int koko)
{
    for (int i = 0; i < koko; i++)
    {
        if (taulukko[i] == tarkistettava)
            return 1;
    }
    return 0;
}

void arvoNumerot(int *taulukko, int maara)
{
    for (int i = 0; i < maara; i++)
    {
        int uusiNumero = rand() % 38;
        while (tarkistaNumero(taulukko, uusiNumero, maara))
            uusiNumero = rand() % 38;

        taulukko[i] = uusiNumero;
    }
}

void tulostaNumerot(int *taulukko, int maara)
{
    for (int i = 0; i < maara; i++)
    {
        printf("%d ", taulukko[i]);
    }
    printf("\n");
}