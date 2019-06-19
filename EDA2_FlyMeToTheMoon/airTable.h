//"estrutura" dos aeroportos mantido em disco
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "hashtable.h"


#define FNAME "airTable.bin"

void exitTable(FILE *file, struct air *x[SIZE]);

void enterTable(FILE *file, int n);

FILE *openTable();

