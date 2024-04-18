#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct kirja
{
    char nimi[50];
    int painovuosi;
    int hyllypaikka;
};

void cleanString(char str[48])
{
    str[strcspn(str, "\n")] = 0;
}

int main(void)
{
    struct kirja krj;
    char buffer[48];

    printf("Anna kirjan nimi: ");
    fgets(buffer, 48, stdin);
    cleanString(buffer);
    strcpy(krj.nimi, buffer);
    printf("Anna kirjan painovuosi: ");
    fgets(buffer, 6, stdin);
    cleanString(buffer);
    krj.painovuosi = atoi(buffer);
    printf("Anna kirjan hyllypaikka: ");
    fgets(buffer, 20, stdin);
    cleanString(buffer);
    krj.hyllypaikka = atoi(buffer);

    printf("Kirjan nimi on '%s', painovuosi %d ja hyllypaikka %d.\nKiitos ohjelman käytöstä.\n", krj.nimi, krj.painovuosi, krj.hyllypaikka);
    return (0);
}