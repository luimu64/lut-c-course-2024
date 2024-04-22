#include <stdio.h>
#include <stdlib.h>

int tarkistaSyote(int parametri)
{
    return parametri > 0;
}

int *varaaMuisti(int *koko)
{
    int *pMuistilohko;
    if ((pMuistilohko = (int *)malloc(*koko * sizeof(int))) == NULL)
    {
        perror("Muistin varaus epäonnistui");
        exit(1);
    }
    else
        printf("Muistin varaus onnistui.\n");
    return pMuistilohko;
}

void taytataulukko(int *pMuistiLohko, int *koko)
{
    printf("Taulukossa on tilaa %d alkiolle.\n", *koko);
    for (int i = 0; i < *koko; i++)
    {
        printf("Anna %d. luku: ", i + 1);
        scanf("%d", &pMuistiLohko[i]);
    }
    printf("Taulukko täytetty.\n");
}

void tulostaTaulukko(int *pMuistiLohko, int *koko)
{
    printf("Taulukossa on luvut: ");
    for (int i = 0; i < *koko; i++)
    {
        printf("%d ", pMuistiLohko[i]);
    }
    printf("\nTaulukko tulostettu.\n");
}

void vapautaMuisti(int *pMuistiLohko)
{
    free(pMuistiLohko);
    printf("Muisti vapautettu.\n");
}

int main(int args, char *argv[])
{
    int koko = 0;
    int *pMuistilohko;
    if (args == 2 && tarkistaSyote((atoi(argv[1]))))
    {
        koko = atoi(argv[1]);
        pMuistilohko = varaaMuisti(&koko);
        taytataulukko(pMuistilohko, &koko);
        tulostaTaulukko(pMuistilohko, &koko);
        vapautaMuisti(pMuistilohko);
    }
    else if (args == 2)
        printf("Parametri ei ollut positiivinen kokonaisluku.\n");
    else
        printf("Et antanut taulukon kokoa.\n");

    printf("Kiitos ohjelman käytöstä.\n");
    return (0);
}
