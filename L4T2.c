#include <stdio.h>

int main(void)
{
    int matriisi1[2][2];
    int matriisi2[2][2];
    printf("Anna arvot yhteenlaskettaville matriiseille:\n");

    printf("Matriisin 1 alkiot:\n");
    printf("Rivi 1 alkio 1: ");
    scanf("%d", &matriisi1[0][0]);
    printf("Rivi 1 alkio 2: ");
    scanf("%d", &matriisi1[1][0]);
    printf("Rivi 2 alkio 1: ");
    scanf("%d", &matriisi1[0][1]);
    printf("Rivi 2 alkio 2: ");
    scanf("%d", &matriisi1[1][1]);

    printf("\nMatriisi 1:\n%4d %4d \n%4d %4d \n\n", matriisi1[0][0], matriisi1[1][0], matriisi1[0][1], matriisi1[1][1]);

    printf("Matriisin 2 alkiot:\n");
    printf("Rivi 1 alkio 1: ");
    scanf("%d", &matriisi2[0][0]);
    printf("Rivi 1 alkio 2: ");
    scanf("%d", &matriisi2[1][0]);
    printf("Rivi 2 alkio 1: ");
    scanf("%d", &matriisi2[0][1]);
    printf("Rivi 2 alkio 2: ");
    scanf("%d", &matriisi2[1][1]);

    printf("\nMatriisi 2:\n%4d %4d \n%4d %4d \n\n", matriisi2[0][0], matriisi2[1][0], matriisi2[0][1], matriisi2[1][1]);

    printf("Summamatriisi:\n%4d %4d \n%4d %4d \n\n", matriisi1[0][0] + matriisi2[0][0], matriisi1[1][0] + matriisi2[1][0], matriisi1[0][1] + matriisi2[0][1], matriisi1[1][1] + matriisi2[1][1]);

    printf("Kiitos ohjelman käytöstä.\n");
    return (0);
}