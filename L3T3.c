#include <stdio.h>
#include <string.h>
#include <ctype.h>

void pienempiNumero(float luku1, float luku2, int onkoInt)
{
    float suurempi = luku1 > luku2 ? luku1 : luku2;
    float pienempi = suurempi == luku1 ? luku2 : luku1;

    if (onkoInt)
    {
        if (suurempi == pienempi)
            printf("Luvut %.0f ja %.0f ovat yhtä suuria.\n", suurempi, pienempi);
        else
            printf("Luku %.0f on suurempi ja %.0f pienempi.\n", suurempi, pienempi);
    }
    else
    {
        if (suurempi == pienempi)
            printf("Luvut %5.2f ja %5.2f ovat yhtä suuria.\n", suurempi, pienempi);
        else
            printf("Luku %5.2f on suurempi ja %5.2f pienempi.\n", suurempi, pienempi);
    }
}

void pienempiMerkkijono(char jono1[20], char jono2[20])
{
    if (strcmp(jono1, jono2) == 0)
    {
        printf("Merkkijonona '%s' ja '%s' ovat yhtä suuria.\n", jono1, jono2);
        return;
    }
    else if (strcmp(jono1, jono2) <= 0)
    {
        printf("Merkkijonona '%s' on suurempi ja '%s' pienempi.\n", jono2, jono1);
    }
    else
    {
        printf("Merkkijonona '%s' on suurempi ja '%s' pienempi.\n", jono1, jono2);
    }
}

int main()
{
    int luku1, luku2;
    float desimaali1, desimaali2;
    char merkkijono1[20], merkkijono2[20];
    printf("Anna kaksi kokonaislukua:\nLuku 1: ");
    scanf("%d", &luku1);
    printf("Luku 2: ");
    scanf("%d", &luku2);
    pienempiNumero((float)luku1, (float)luku2, 1);
    printf("Anna kaksi desimaalilukua:\nLuku 1: ");
    scanf("%f", &desimaali1);
    printf("Luku 2: ");
    scanf("%f", &desimaali2);
    pienempiNumero(desimaali1, desimaali2, 0);
    printf("Anna kaksi nimeä:\nNimi 1: ");
    scanf("%s", merkkijono1);
    printf("Nimi 2: ");
    scanf("%s", merkkijono2);
    pienempiMerkkijono(merkkijono1, merkkijono2);
    printf("Kiitos ohjelman käytöstä.\n");
    return (0);
}