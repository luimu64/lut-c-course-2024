#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Auto
{
    char cMerkki[100];
    int iVuosi;
    struct Auto *pSeuraava;
} AUTO;

void tulostaAutot(AUTO *pAlku)
{
    AUTO *ptr;
    ptr = pAlku;
    int i = 1;
    while (ptr != NULL)
    {
        printf("%d. ajoneuvo: %s vuosimalli %d.\n", i, ptr->cMerkki, ptr->iVuosi);
        ptr = ptr->pSeuraava;
        i++;
    }
}

void lisaaAuto(AUTO **pAlku, AUTO **pLoppu, char merkki[100], int vuosi)
{
    AUTO *pUusi;
    if ((pUusi = (AUTO *)malloc(sizeof(AUTO))) == NULL)
    {
        perror("Muistin varaus epäonnistui");
        exit(1);
    }
    // Uuden alkion jäsenmuuttujien arvojen asettaminen
    strcpy(pUusi->cMerkki, merkki);
    pUusi->iVuosi = vuosi;
    pUusi->pSeuraava = NULL;
    // Uuden alkion lisääminen listaan viimeiseksi alkioksi
    if (*pAlku == NULL)
    {                   // lista on tyhjä, joten
        *pAlku = pUusi; // tehdään ensimmäinen alkio
        *pLoppu = pUusi;
    }
    else
    { // lista ei ole tyhjä, joten lisätään loppuun
        (*pLoppu)->pSeuraava = pUusi;
        *pLoppu = pUusi;
    }
}

void vapautaMuisti(AUTO *pAlku)
{
    AUTO *ptr;
    ptr = pAlku;
    while (ptr != NULL)
    {
        pAlku = ptr->pSeuraava;
        free(ptr);
        ptr = pAlku;
    }
    printf("Muisti vapautettu.\n");
}

int main(int args, char *argv[])
{
    FILE *tiedosto;
    char rivi[100];
    char s[2] = " ";
    char merkki[100];
    int vuosi;
    AUTO *pAlku = NULL, *pLoppu = NULL;

    if (args == 2)
    {
        printf("Luetaan tiedot tiedostosta %s.\n", argv[1]);
        if ((tiedosto = fopen(argv[1], "r")) == NULL)
        {
            printf("Tiedoston avaus epäonnistui.\nKiitos ohjelman käytöstä.\n");
            exit(0);
        }
        else
        {
            while (fgets(rivi, 98, tiedosto) != NULL)
            {
                if (rivi[0] != '\n' && rivi[0] != '\0')
                {
                    if (rivi[strlen(rivi) - 1] == '\n')
                        rivi[strlen(rivi) - 1] = '\0';

                    char *token = strtok(rivi, s);
                    if (token != NULL) // Check if token is not null before proceeding
                    {
                        strcpy(merkki, token);
                        token = strtok(NULL, s);
                        if (token != NULL) // Check if token is not null before proceeding
                        {
                            vuosi = atoi(token);
                            lisaaAuto(&pAlku, &pLoppu, merkki, vuosi);
                        }
                    }
                }
            }
            printf("Tiedot luettu linkitettyyn listaan.\n");
            fclose(tiedosto);
        }

        if (pAlku != NULL)
            tulostaAutot(pAlku);
        else
            printf("Ajoneuvoja ei löytynyt.\n");

        vapautaMuisti(pAlku);
    }
    else
        printf("Et antanut tiedoston nimeä.\n");

    printf("Kiitos ohjelman käytöstä.\n");

    return (0);
}