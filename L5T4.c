#include <stdio.h>
#include <stdlib.h>

int tulostaMenu()
{
    int vastaus;
    printf("1) Tulosta taulukon alkiot\n2) Muuta taulukon kokoa\n0) Lopeta\nAnna valintasi: ");
    scanf("%d", &vastaus);
    return vastaus;
}

void tulostaAlkiot(int *arr, int koko)
{
    if (koko > 0)
    {
        printf("Taulukon alkiot ovat: ");
        for (int i = 0; i < koko; i++)
        {
            printf("%d ", arr[i]);
        }
        printf("\n");
    }
    else
        printf("Taulukko on tyhjä.\n");
}

void muutaKokoa(int **arr, int *koko)
{
    printf("Anna taulukon uusi koko: ");
    scanf("%d", koko);

    if (*koko < 0)
    {
        printf("Taulukon koko ei voi olla negatiivinen.\n");
        return;
    }

    if (*koko == 0)
    {
        free(*arr);
        *arr = NULL;
        return;
    }

    int *tmp = (int *)realloc(*arr, *koko * sizeof(int));
    if (tmp == NULL)
    {
        perror("Muistin varaus epäonnistui");
        exit(1);
    }

    *arr = tmp;
    for (int i = 0; i < *koko; i++)
    {
        (*arr)[i] = i;
    }
}

int main(void)
{
    int vastaus;
    int koko = 0;
    int *ptr = 0;

    while ((vastaus = tulostaMenu()) != 0)
    {
        if (vastaus == 1)
            tulostaAlkiot(ptr, koko);
        else if (vastaus == 2)
            muutaKokoa(&ptr, &koko);
        else
            printf("Tuntematon valinta, yritä uudestaan.");
    }

    free(ptr);
    printf("Muisti vapautettu.\n");
    printf("Kiitos ohjelman käytöstä.\n");
    return (0);
}
