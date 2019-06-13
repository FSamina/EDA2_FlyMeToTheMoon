//"estrutura" dos voos mantido em disco e organizada por aeroportos
#include <stdio.h>
#include <stdbool.h>
#import "main.c"

#define FNAME "flightTable.bin"


struct flightsPerAir tempAir;

void write(FILE *file, int n, int x){
    fseek(file,n* sizeof(tempAir),SEEK_SET)

}

FILE *abrir() {
    FILE *file;
    int zero = 0;
    file = fopen(FNAME, "r+");
    if (file == NULL) {
        file = fopen(FNAME, "w+");
    }

    return file;
}

