#include <stdio.h>
#define merkkijononPituus 30

int jononPituus(char merkkijono[merkkijononPituus])
{
    int pituus = 0;

    for (int i = 0; merkkijono[i] != '\n'; i++)
    {
        pituus++;
    }

    return pituus;
}

void kopioJono(char jono1[merkkijononPituus], char jono2[merkkijononPituus])
{
    int pituus = jononPituus(jono1);
    jono1[pituus] = '\0';
    jono2[pituus] = '\0';

    for (int i = 0; i < pituus; i++)
    {
        jono2[i] = jono1[i];
    }
}

int main()
{
    char merkkijono1[merkkijononPituus];
    char merkkijono2[merkkijononPituus];

    printf("Anna kopioitava merkkijono: ");
    fgets(merkkijono1, merkkijononPituus, stdin);

    kopioJono(merkkijono1, merkkijono2);

    printf("Merkkijono 1 on '%s'.\nMerkkijono 2 on '%s'.\nKiitos ohjelman käytöstä.\n", merkkijono1, merkkijono2);

    return 0;
}