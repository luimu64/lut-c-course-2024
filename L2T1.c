#include <stdio.h>
int main()
{
    int luku1;
    int luku2;
    int valinta;

    printf("Anna kaksi kokonaislukua: ");
    scanf("%d %d", &luku1, &luku2);
    printf("\n");
    printf("Valikko\n1) Summaa luvut yhteen.\n2) Kerro luvut keskenään.\nValitse: ");
    scanf("%d", &valinta);
    printf("\n");

    if (valinta == 1)
    {
        printf("Luvut laskettiin yhteen. Tulos = %d.\n", luku1 + luku2);
    }
    else if (valinta == 2)
    {
        printf("Luvut kerrottiin keskenään. Tulos = %d.\n", luku1 * luku2);
    }
    else
    {
        printf("Tuntematon valinta.\n");
    }

    return (0);
}