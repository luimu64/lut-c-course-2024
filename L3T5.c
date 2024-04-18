#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int lue(char tiedostonimi[30])
{
    FILE *tiedosto;
    int luku;

    if ((tiedosto = fopen(tiedostonimi, "rb")) == NULL)
    {
        perror("Tiedoston avaaminen epäonnistui, lopetetaan:");
        exit(0);
    }
    else
    {

        printf("Tiedostossa on seuraavat luvut:\n");
        for (int i = 0; i < 20; i++)
        {
            fread(&luku, sizeof(luku), 1, tiedosto);
            printf(i == 19 ? "%ld \n" : "%d ", luku);
        }
        fclose(tiedosto);
    }
    return 1;
}

int kirjoita(char nimi[30], int lahto)
{
    FILE *tiedosto;
    srand(lahto);
    int uusiRandomNro = 0;
    int i = 0;

    if ((tiedosto = fopen(nimi, "wb")) == NULL)
    {
        perror("Tiedoston avaaminen epäonnistui");
        exit(0);
    }
    for (i = 0; i < 20; i++)
    {
        uusiRandomNro = rand() % 1000;
        fwrite(&uusiRandomNro, sizeof(uusiRandomNro), 1, tiedosto);
    }
    fclose(tiedosto);
    return 1;
}

int main()
{
    char tiedostonNimi[30] = "";
    char lahtoarvo[10] = "0";

    printf("Anna käsiteltävän tiedoston nimi: ");
    fgets(tiedostonNimi, 30, stdin);
    printf("Anna satunnaisluvuille lähtöarvo: ");
    fgets(lahtoarvo, 10, stdin);
    // remove trailing newline
    tiedostonNimi[strcspn(tiedostonNimi, "\n")] = 0;
    lahtoarvo[strcspn(lahtoarvo, "\n")] = 0;

    if (kirjoita(tiedostonNimi, atoi(lahtoarvo)))
        printf("Tiedoston kirjoitus onnistui.\n");

    if (lue(tiedostonNimi))
        printf("Tiedoston lukeminen onnistui.\n");

    printf("Kiitos ohjelman käytöstä.\n");

    return (0);
}