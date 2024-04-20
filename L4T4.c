#include <stdio.h>
#define PITUUS 50

typedef struct
{
    int id;
    char tunnus[PITUUS];
    char salasana[PITUUS];
} KAYTTAJA;

int naytaMenu()
{
    int valinta = -1;
    printf("\nValitse haluamasi toiminto:\n1) Lisää uusi tunnus\n2) Tulosta tunnukset\n0) Lopeta\nValintasi: ");
    scanf("%d", &valinta);
    printf("\n");
    return valinta;
}

void lisaaTunnus(KAYTTAJA kayttajat[PITUUS], int viimeisinID)
{
    KAYTTAJA uusiKayttaja;
    printf("Anna käyttäjätunnus: ");
    scanf("%s", uusiKayttaja.tunnus);
    printf("Anna salasana: ");
    scanf("%s", uusiKayttaja.salasana);
    uusiKayttaja.id = viimeisinID;
    kayttajat[viimeisinID] = uusiKayttaja;
    printf("Tunnus '%s' lisättiin listaan.\n", uusiKayttaja.tunnus);
}

void tulostaTunnukset(KAYTTAJA kayttajat[PITUUS], int viimeisinID)
{
    if (viimeisinID == 0)
    {
        printf("Listalla ei ole yhtään tunnusta.\n");
        return;
    }
    printf("Listalla olevat tunnukset:\n");
    for (int i = 0; i < viimeisinID; i++)
    {
        printf("%d. tunnus '%s', salasana '%s', ID '%d'.\n", i + 1, kayttajat[i].tunnus, kayttajat[i].salasana, kayttajat[i].id);
    }
}

int main(void)
{
    int valinta = -1;
    int viimeisinID = 0;
    KAYTTAJA kayttajat[PITUUS];

    printf("Käyttäjätunnusten hallinta.");

    while (valinta)
    {
        valinta = naytaMenu();

        switch (valinta)
        {
        case 0:
            continue;
            break;
        case 1:
            lisaaTunnus(kayttajat, viimeisinID);
            viimeisinID++;
            break;
        case 2:
            tulostaTunnukset(kayttajat, viimeisinID);
            break;
        }
    }
    printf("Kiitos ohjelman käytöstä.\n");
    return (0);
}