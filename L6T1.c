#include <stdio.h>
#include <stdlib.h>

typedef struct numero
{
    int iNum;
    struct numero *pSeuraava;
} NUMERO;

int menu()
{
    int vastaus;
    printf("Anna positiivinen kokonaisluku, 0 lopettaa: ");
    scanf("%d", &vastaus);
    return vastaus;
}

int main(int args, char *argv[])
{
    NUMERO *pAlku = NULL, *pLoppu = NULL;
    NUMERO *pUusi, *ptr;

    int vastaus;
    printf("Anna listan luvut.\n");
    while ((vastaus = menu()) != 0)
    {
        if ((pUusi = (NUMERO *)malloc(sizeof(NUMERO))) == NULL)
        {
            perror("Muistin varaus epäonnistui");
            exit(1);
        }
        // Uuden alkion jäsenmuuttujien arvojen asettaminen
        pUusi->iNum = vastaus;
        pUusi->pSeuraava = NULL;
        // Uuden alkion lisääminen listaan viimeiseksi alkioksi
        if (pAlku == NULL)
        {                  // lista on tyhjä, joten
            pAlku = pUusi; // tehdään ensimmäinen alkio
            pLoppu = pUusi;
        }
        else
        { // lista ei ole tyhjä, joten lisätään loppuun
            pLoppu->pSeuraava = pUusi;
            pLoppu = pUusi;
        }
    }

    printf("Listassa on seuraavat luvut: ");
    ptr = pAlku;
    while (ptr != NULL)
    {
        printf("%d ", ptr->iNum);
        ptr = ptr->pSeuraava;
    }

    ptr = pAlku;
    while (ptr != NULL)
    {
        pAlku = ptr->pSeuraava;
        free(ptr);
        ptr = pAlku;
    }

    printf("\nKiitos ohjelman käytöstä.\n");
    return (0);
}
