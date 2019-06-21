//"estrutura" dos aeroportos mantido em disco
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "airTable.h"




void exitTable(FILE *file, struct air *x[SIZE]){
    fseek(file,0,SEEK_SET);
    fwrite(x, sizeof(struct air)*SIZE,1,file);

}

void enterTable(FILE *file, int n){
    fseek(file,0,SEEK_SET);
    size_t test = fread(hashArray, sizeof(hashArray)*SIZE, 1, file);
    if (test<=0) exit(6);
}

FILE *openTable() {
    FILE *file;
    file = fopen(FNAMET, "r+");
    if (file == NULL) {
        file = fopen(FNAMET, "w+");
    }if (file == NULL) {
        exit(6);
    }
    return file;
}

