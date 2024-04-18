#include <stdio.h>
int main()
{
    char etunimi[30];
    char sukunimi[30];
    int ika;
    float paino;

    printf("Anna etunimesi: ");
    scanf("%s", etunimi);
    printf("Anna sukunimesi: ");
    scanf("%s", sukunimi);
    printf("Anna ikäsi: ");
    scanf("%d", &ika);
    printf("Anna painosi: ");
    scanf("%f", &paino);
    printf("Nimesi on %s %s, ikäsi on %d vuotta ja painat %0.1f kg.\n", etunimi, sukunimi, ika, paino);
    return (0);
}