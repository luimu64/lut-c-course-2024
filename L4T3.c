#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct laskuData
{
    float ekaArgumentti;
    char modifieri;
    float tokaArgumentti;
} LASKUDATA;

int main(void)
{
    LASKUDATA lsk;
    char laskuInput[30];
    char *tok;
    float tulos;

    fgets(laskuInput, 28, stdin);
    tok = strtok(laskuInput, " ");

    for (int i = 0; tok != 0; i++)
    {
        switch (i)
        {
        case 0:
            lsk.ekaArgumentti = atof(tok);
            break;
        case 1:
            lsk.modifieri = tok[0];
            break;
        case 2:
            lsk.tokaArgumentti = atof(tok);
            break;
        }
        tok = strtok(0, " ");
    }

    switch (lsk.modifieri)
    {
    case '+':
        printf(" = %.2f\n", lsk.ekaArgumentti + lsk.tokaArgumentti);
        break;
    case '-':
        printf(" = %.2f\n", lsk.ekaArgumentti - lsk.tokaArgumentti);
        break;
    case 'x':
        printf(" = %.2f\n", lsk.ekaArgumentti * lsk.tokaArgumentti);
        break;
    case '/':
        printf(" = %.2f\n", lsk.ekaArgumentti / lsk.tokaArgumentti);
        break;
    default:
        printf("Virheellinen syöte.\n");
        break;
    }

        printf("Kiitos ohjelman käytöstä.\n");
    return (0);
}