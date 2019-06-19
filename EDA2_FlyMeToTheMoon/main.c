#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include "hashtable.h"
#include "airTable.c"


//TR <aeroporto-partida> <aeroporto-destino> <hora-chegada-aeroporto>
void calcViagem(char IdAirPartida[5],char IdAirChegada[5],short hourPartida,short minutePartida)
{


}
//FD <aeroporto-partida> <aeroporto-destino> <hora-partida>
void delVoo(char IdAirPartida[5],char IdAirChegada[5],short hPartida,short mPartida)
{

}

//FI <c´odigo> <aeroporto-partida> <aeroporto-destino> <hora-partida> <dura¸c~ao>
void intrudVoo(char idVoo[7],char IdAirPartida[5],char IdAirChegada[5],short hPartida,short mPartida,short tempoDeVoo)//temos de addicionar aerporto de partida
{
    struct voos *novoVoo = (struct voos*) malloc(sizeof(struct voos));//criamos o novo aeroporto
    strcpy(novoVoo->Id,idVoo);
    strcpy(novoVoo->IdAirChegada,IdAirChegada);
    //meter o id do aerporto de partida?
    novoVoo->hourPartida =hPartida;
    novoVoo->minutePartida=mPartida;
    novoVoo->tempTotal=tempoDeVoo;

    //falta inserir (devo inserir os voos numa hastable tambem?)

}

//AI <código> <fuso-hor´ario>
void intrudAir(char key[5],short hLocal,short mLocal)//recebe como argumento codigo e hora local
{
    bool check=false;
    struct air *novoAir = (struct air*) malloc(sizeof(struct air));//criamos o novo aeroporto
    strcpy(novoAir->Id,key);
    novoAir->flag =false;
    novoAir->hour=hLocal;
    novoAir->minute=mLocal;
    check = insert(novoAir);
    if (check)
    {
        printf("+ novo aeroporto %s\n",novoAir->Id);
    }else
    {
        printf("+ aeroporto %s existe\n",novoAir->Id);
    }
}

int main(void)
{
    //testar hastable
    dummyItem =  malloc(sizeof(struct air));
    dummyItem->flag = true; //foi "removido"
    
    //5 Aeroportos de teste
    struct air *itemA = malloc(sizeof(struct air));
    char  arrA[5] = "LISB";
    strcpy(itemA->Id,arrA);
    itemA->flag =false;
    insert(itemA);
    struct air *itemB = malloc(sizeof(struct air));
    char arrB[5] = "MADR";
    strcpy(itemB->Id,arrB);
    itemB->flag =false;
    insert(itemB);
    struct air *itemC =  malloc(sizeof(struct air));
    char arrC[5] = "NY";
    strcpy(itemC->Id,arrC);
    itemC->flag =false;
    insert(itemC);
    struct air *itemD =  malloc(sizeof(struct air));
    char arrD[5] = "PORT";
    strcpy(itemD->Id,arrD);
    itemD->flag =false;
    insert(itemD);
    struct air *itemE =  malloc(sizeof(struct air));
    char arrE[5] = "LIBA";
    strcpy(itemE->Id,arrE);
    itemE->flag =false;
    insert(itemE);

    item = search("PORT");

    if(item != NULL) {
        printf("Element found: %s\n", item->Id);
    } else {
        printf("Element not found\n");
    }

    // delete(item);
    // item = search("LISB");

    // if(item != NULL) {
    //     printf("Element found: %s\n", item->Id);
    // } else {
    //     printf("Element not found\n");
    // }

    display();


    //disk save
    FILE *file;
    file = openTable();
    exitTable(file,hashArray);



    return -1;
}