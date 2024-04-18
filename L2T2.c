#include <stdio.h>
int main()
{
    int luku;
    int summa = 0;
    int i;

    printf("Anna jokin luku väliltä 10 - 200: ");
    scanf("%d", &luku);

    if ((luku > 200) || (luku < 10))
    {
        printf("Antamasi luku ei ole annetulla välillä.\n");
        return 0;
    }

    for (i = 0; i <= luku; i++)
    {
        summa += i;
    }

    printf("Lukujen 0 - %d summa on %d.\n", luku, summa);
    return 0;
}