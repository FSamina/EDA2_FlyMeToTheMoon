#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include "hashtable.h"


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
    /*  PARA TESTAR
    dummyItem = (struct air*) malloc(sizeof(struct air));
    dummyItem->flag = true; //foi "removido"
    struct air *itemA = (struct air*) malloc(sizeof(struct air));
    char  arr[5] = "LISB";
    strcpy(itemA->Id,arr);
    itemA->flag =false;


    insert(itemA);
    insert(itemA);
    item = search("LISB");

    if(item != NULL) {
        printf("Element found: %s\n", item->Id);
    } else {
        printf("Element not found\n");
    }

    delete(item);
    item = search("LISB");

    if(item != NULL) {
        printf("Element found: %s\n", item->Id);
    } else {
        printf("Element not found\n");
    }

    display(); */
    return -1;
}