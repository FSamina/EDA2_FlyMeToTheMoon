//"estrutura" dos voos mantido em disco e organizada por aeroportos
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#import "main.h"

#define FNAME "flightTable.bin"


struct flightsPerAir tempAir;

void write(FILE *file, int n, struct flightsPerAir *x){
    fseek(file,n* sizeof(struct flightsPerAir),SEEK_SET);
    fwrite(x, sizeof(struct flightsPerAir),1,file);

}

struct flightsPerAir read(FILE *file, int n){
    fseek(file,n* sizeof(struct flightsPerAir),SEEK_SET);
    size_t test = fread(&tempAir, sizeof(struct flightsPerAir), 1, file);
    if (test>0)
        return tempAir;

    else {
        exit(6);
    }
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
/*
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

// gitingnoreTEST

 */
