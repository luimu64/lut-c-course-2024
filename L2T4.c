#include <stdio.h>
#define pi 3.142

int main()
{
    float luku;
    int valinta;

    printf("Anna liukuluku: ");
    scanf("%f", &luku);
    printf("\n");
    printf("Valikko\n1) Kerro piin arvo luvulla %.3f.\n2) Jaa piin arvo luvulla %.3f.\nValitse: ", luku, luku);
    scanf("%d", &valinta);
    printf("\n");

    if (valinta == 1)
    {
        printf("Pii * %.3f = %.3f.\n", luku, pi * luku);
    }
    else if (valinta == 2)
    {
        printf("Pii / %.3f = %.3f.\n", luku, pi / luku);
    }
    else
    {
        printf("Tuntematon valinta.\n");
    }

    return (0);
}