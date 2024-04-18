#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int args, char *argv[])
{
    if (argv[1])
    {
        switch (argv[2][0])
        {
        case '+':
            printf("%.1f + %.1f = %.2f\n", atof(argv[1]), atof(argv[3]), atof(argv[1]) + atof(argv[3]));
            break;
        case '-':
            printf("%.1f - %.1f = %.2f\n", atof(argv[1]), atof(argv[3]), atof(argv[1]) - atof(argv[3]));
            break;
        case 'x':
            printf("%.1f x %.1f = %.2f\n", atof(argv[1]), atof(argv[3]), atof(argv[1]) * atof(argv[3]));
            break;
        case '/':
            printf("%.1f / %.1f = %.2f\n", atof(argv[1]), atof(argv[3]), atof(argv[1]) / atof(argv[3]));
            break;
        default:
            printf("Virheellinen syöte.\n");
            break;
        }
    }
    else
        printf("Et antanut syötteitä.\n");

    printf("Kiitos ohjelman käytöstä.\n");
    return (0);
}
