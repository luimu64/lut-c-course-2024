#include <stdio.h>
#include <string.h>
#define koko 200
#define true 1

int main()
{
    char merkki[2];
    char merkkijono[koko] = " ";
    int seuraavatyhja = 0;
    int valinta = -1;

    while (true)
    {
        printf("\nValikko\n1) Lisää uusi merkki\n2) Tyhjennä merkkijono\n3) Tulosta merkkijono\n0) Lopeta\nValintasi: ");
        if (scanf("%d", &valinta) != 1)
        {
            printf("\nTuntematon valinta.\n");
            getchar();
            continue;
        }
        else if (valinta == 0)
        {
            printf("\nOhjelman lopetus.\n");
            break;
        }

        printf("\n");

        switch (valinta)
        {
        case 1:
            printf("Anna jokin merkki: ");
            scanf("%1s", merkki);
            if (seuraavatyhja < koko)
            {
                merkkijono[seuraavatyhja] = merkki[0];
                seuraavatyhja++;
            }
            else
            {
                printf("Merkkijonoon ei mahdu enempää merkkejä.");
            }
            break;

        case 2:
            for (int i = 0; i < koko; i++)
            {
                merkkijono[i] = ' ';
            }
            seuraavatyhja = 0;
            printf("Merkkijono on tyhjennetty.\n");
            break;

        case 3:
            if (merkkijono[0] == ' ')
            {
                printf("Merkkijono on tyhjä.\n");
                break;
            }

            printf("Merkkijono: %s\n", merkkijono);
            break;

        default:
            printf("Tuntematon valinta.\n");
            break;
        }
    }
    return (0);
}