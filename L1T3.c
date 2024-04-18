#include <stdio.h>
int main()
{
    int luku;
    int luku2;
    printf("Anna ensimmäinen kokonaisluku: ");
    scanf("%d", &luku);
    printf("Anna toinen kokonaisluku: ");
    scanf("%d", &luku2);
    printf("(%d + %d) * 2 = %d\n", luku, luku2, (luku + luku2) * 2);
    printf("(%d / %d) - 3 = %d\n", luku, luku2, (luku / luku2) - 3);
    printf("%d %% %d = %d\n", luku + 1, luku2 - 1, (luku + 1) % (luku2 - 1));
    return (0);
}