#include <stdlib.h>
#include <stdio.h>
#include "L7T1_io.h"

int main(void)
{
    int koko = 10;
    int *askeleet;
    int *koko_ptr;
    koko_ptr = &koko;

    askeleet = malloc(sizeof(int) * *koko_ptr);
    if (askeleet == NULL)
    {
        perror("Muistin varaus epäonnistui");
        exit(1);
    }

    int summa;
    printf("Askelanalyysi\n");
    summa = lueAskeleetListaan(askeleet, koko_ptr);
    tulostaLista(askeleet, *koko_ptr);
    printf("Askelia yhteensä: %d\n", summa);
    printf("Kiitos ohjelman käytöstä.\n");
    return 0;
}