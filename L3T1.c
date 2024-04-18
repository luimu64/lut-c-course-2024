#include <stdio.h>

int laskePotenssi(int luku, int potenssi)
{
    int tulos = 1;

    for (int i = 0; i < potenssi; i++)
    {
        tulos *= luku;
    }

    return tulos;
}

int main()
{
    int luku, potenssi;
    printf("Ohjelma laskee luvun potenssin.\nAnna kokonaisluku, jonka haluat korottaa potenssiin: ");
    scanf("%d", &luku);
    printf("Anna potenssi, jonka haluat laskea: ");
    scanf("%d", &potenssi);
    printf("%d ^ %d = %d.\n", luku, potenssi, laskePotenssi(luku, potenssi));
    printf("Kiitos ohjelman käytöstä.\n");
    return (0);
}