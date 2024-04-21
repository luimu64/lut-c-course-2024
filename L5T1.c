#include <stdio.h>
#include <stdlib.h>

int nelio(int luku)
{
    return luku * luku;
}

int main(int args, char *argv[])
{
    if (!argv[1])
        printf("Et antanut lukua!\n");
    else
        printf("Luku on %d.\nLuvun neliö on %d.\n", atoi(argv[1]), nelio(atoi(argv[1])));

    printf("Kiitos ohjelman käytöstä.\n");
    return (0);
}
