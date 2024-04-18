#include <stdio.h>
#include <stdlib.h>
#define nimenpituus 50;

int kirjoita(char tiedostonimi[100], char nimi[50])
{
    FILE *tiedosto;
    if ((tiedosto = fopen(tiedostonimi, "a")) == NULL)
    {
        perror("Tiedoston avaaminen epäonnistui");
    }

    if (fprintf(tiedosto, "%s\n", nimi))
    {
        printf("Nimi lisätty tiedostoon.\n\n");
        fclose(tiedosto);
        return 1;
    }
    else
        return 0;
}

void lue(char tiedostonimi[100])
{
    FILE *tiedosto;
    char rivi[48];
    if ((tiedosto = fopen(tiedostonimi, "r")) == NULL)
    {
        perror("Tiedoston avaaminen epäonnistui, lopetetaan:");
        exit(0);
    }
    else
    {
        printf("Tiedostossa olevat nimet:\n");
        while (fgets(rivi, 50, tiedosto) != NULL)
        {
            printf("%s", rivi);
        }
        printf("Tiedosto luettu ja tulostettu.\n\n");
        fclose(tiedosto);
    }
}

int naytaValikko()
{
    int valinta = 0;
    printf("Valitse alla olevista valinnoista\n1) Lisää uusi nimi\n2) Tulosta nimet\n0) Lopeta\nAnna valintasi: ");
    if (scanf("%d", &valinta) != 1)
    {
        printf("Tuntematon valinta.");
        getchar();
        valinta = naytaValikko();
    }
    return valinta;
}

int main()
{

    char tiedostonimi[100];
    int valinta;

    printf("Tämä ohjelma lisää nimiä tiedostoon ja lukee ne.\n");
    printf("Anna käsiteltävän tiedoston nimi: ");
    scanf("%s", tiedostonimi);

    while (1)
    {
        valinta = naytaValikko();
        if (valinta == 0)
        {
            printf("Kiitos ohjelman käytöstä.\n");
            break;
        }
        else if (valinta == 1)
        {
            char nimi[50];
            printf("Anna lisättävä nimi: ");
            scanf("%s", nimi);
            kirjoita(tiedostonimi, nimi);
        }
        else if (valinta == 2)
        {
            lue(tiedostonimi);
        }
    }

    return (0);
}