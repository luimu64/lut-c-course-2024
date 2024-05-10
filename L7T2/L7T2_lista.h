typedef struct lukuAlkio
{
    int iLuku;
    struct lukuAlkio *pSeuraava;
} LUKUALKIO;

LUKUALKIO *haeAlkio(LUKUALKIO **pAlku, int sijainti);
void tulostaAlkiot(LUKUALKIO *pAlku);
void vapautaMuisti(LUKUALKIO **pAlku);
void lisaaAlkio(int sij, LUKUALKIO **pAlku, LUKUALKIO **pLoppu, int *index);
void luoLista(LUKUALKIO **pAlku, LUKUALKIO **pLoppu, int *koko, int *index);
int tulostaMenu();
void poistaAlkio(int sij, LUKUALKIO **pAlku, LUKUALKIO **pLoppu);