#include <stdio.h>

int main(void)
{
    int n1 = 0, n2 = 1, n3, i, luku;
    printf("Anna luku, jolle lasketaan Fibonaccin luku: ");
    scanf("%d", &luku);
    printf("Luvun %d Fibonaccin luku on ", luku);
    for (i = 0; i < luku; ++i)
    {
        if (i == luku - 1)
            printf("%d.\n", n3);
        n3 = n1 + n2;
        n1 = n2;
        n2 = n3;
    }
    printf("Kiitos ohjelman käytöstä.\n");
    return (0);
}