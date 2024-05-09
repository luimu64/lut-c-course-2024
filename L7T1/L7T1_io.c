#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "L7T1_io.h"

void tulostaLista(int *lista, int koko)
{
    printf("Listan askeleet: ");
    for (int i = 0; i < koko; i++)
    {
        printf("%d ", lista[i]);
    }
    printf("\n");
}

int lueAskeleetListaan(int *lista, int *koko)
{
    FILE *tiedosto;
    char rivi[100];
    int summa = 0;
    char limiter[2] = ":";

    if ((tiedosto = fopen("askeldata.txt", "r")) == NULL)
    {
        printf("Tiedoston avaus epäonnistui.\nKiitos ohjelman käytöstä.\n");
        exit(0);
    }
    else
    {
        for (int i = 0; i < *koko; i++)
        {
            fgets(rivi, 98, tiedosto);
            char *token = strtok(rivi, limiter);
            token = strtok(NULL, limiter); // second part
            if (token != NULL)
            {
                lista[i] = atoi(token);
                summa += atoi(token);
            }
        }
    }
    fclose(tiedosto);

    return summa;
}
