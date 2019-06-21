//"estrutura" dos aeroportos mantido em disco

#include "hashtable.h"


#define FNAMET "airTable.bin"

void exitTable(FILE *file, struct air *x[SIZE]);

void enterTable(FILE *file, int n);

FILE *openTable();

