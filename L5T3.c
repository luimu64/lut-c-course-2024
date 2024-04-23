#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct henkilo
{
    char nimi[30];
    int ika;
} HENKILO;

HENKILO *kopioHenkilo(HENKILO *src)
{
    HENKILO *t3;
    if ((t3 = (HENKILO *)malloc(sizeof(HENKILO))) == NULL)
    {
        perror("Muistin varaus epäonnistui");
        exit(1);
    }

    strcpy(t3->nimi, src->nimi);
    t3->ika = src->ika;

    return t3;
}

int vertaaHenkilo(HENKILO *h1, HENKILO *h2)
{
    if (!strcmp(h1->nimi, h2->nimi) && h1->ika == h2->ika)
        return 1;
    else
        return 0;
}

int main(int args, char *argv[])
{
    HENKILO t1, t2;
    printf("Anna ensimmäisen henkilön etunimi: ");
    scanf("%s", t1.nimi);
    printf("Anna ensimmäisen henkilön ikä: ");
    scanf("%d", &t1.ika);
    printf("Anna toisen henkilön etunimi: ");
    scanf("%s", t2.nimi);
    printf("Anna toisen henkilön ikä: ");
    scanf("%d", &t2.ika);
    printf(vertaaHenkilo(&t1, &t2) ? "Annetut tiedot ovat samoja.\n" : "Annetut tiedot eivät ole samoja.\n");

    HENKILO *t3 = kopioHenkilo(&t1);
    printf(vertaaHenkilo(&t1, t3) ? "Kopioinnin jälkeen tietueiden tiedot ovat samoja.\n" : "Kopioinnin jälkeen tietueiden tiedot eivät ole samoja.\n");
    printf(&t1 == t3 ? "Kopioinnin jälkeen tietuieden osoitteet ovat samoja.\n" : "Kopioinnin jälkeen tietueiden osoitteet eivät ole samoja.\n");

    free(t3);
    printf("Muisti vapautettu.\n");
    printf("Kiitos ohjelman käytöstä.\n");
    return (0);
}
