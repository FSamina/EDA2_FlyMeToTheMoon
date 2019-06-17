//"estrutura" dos aeroportos mantido em disco
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "aeroportoVoo.h"
#include "hashtable.h"


#define FNAME "airTable.bin"

void exitTable(FILE *file, struct air *x){
    fseek(file,0,SEEK_SET);
    fwrite(x, sizeof(x)*SIZE,1,file);

}

void read(FILE *file, int n){
    fseek(file,0,SEEK_SET);
    size_t test = fread(hashArray, sizeof(hashArray)*SIZE, 1, file);
    if (test<=0) exit(6);
}

FILE *abrir() {
    FILE *file;
    int zero = 0;
    file = fopen(FNAME, "r+");
    if (file == NULL) {
        file = fopen(FNAME, "w+");
    }if (file == NULL) {
        exit(6);
    }


    return file;
}

int main(){
    FILE *file;
    file = abrir();
    struct voos temp;
    char nada [7]="abc";
    strcpy(temp.Id,nada);
    printf("%s\n",temp.Id);
    struct flightsPerAir tempnada;
    tempnada.voosTemp[0]=temp;
    //write(file,0,&tempnada);
    printf("%s\n",read(file,0).voosTemp->Id);

}


