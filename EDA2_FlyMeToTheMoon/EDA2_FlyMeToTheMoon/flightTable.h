//"estrutura" dos voos mantido em disco e organizada por aeroportos
#include "airTable.h"
#define FNAME "flightTable.bin"


struct flightsPerAir tempAir;

void write(FILE *file, int hash,int posValid, struct voos *x);
struct flightsPerAir read(FILE *file, int n);

FILE *abrir();

