#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

#include "flightTable.h"

#define ID_AIR_SIZE 5
#define ID_VOO_SIZE 7

//TR <aeroporto-partida> <aeroporto-destino> <hora-chegada-aeroporto>
void calcViagem(char IdAirPartida[5],char IdAirChegada[5],short hourPartida,short minutePartida)
{


}
//FD <aeroporto-partida> <aeroporto-destino> <hora-partida>
void delVoo(char idVoo[7])
{

    

}

//FI <c´odigo> <aeroporto-partida> <aeroporto-destino> <hora-partida> <dura¸c~ao>
void intrudVoo(char idVoo[7],char IdAirPartida[5],char IdAirChegada[5],short hPartida,short mPartida,short tempoDeVoo,FILE *fileVoo)//temos de addicionar aerporto de partida
{
    int hashIndex=-1;
    hashIndex =search(IdAirPartida);
    struct voos* novoVoo = (struct voos*) malloc(sizeof(struct voos));//criamos o novo aeroporto
    struct voosIds* vooParaIds  = (struct voosIds*) malloc(sizeof(struct voosIds));
    strcpy(novoVoo->Id,idVoo);
    strcpy(novoVoo->IdAirChegada,IdAirChegada);
    strcpy(novoVoo->IdAirPartida,IdAirPartida);
    strcpy(vooParaIds->Id,idVoo);
    strcpy(vooParaIds->IdAirPartida,IdAirPartida);
    vooParaIds->index=hashIndex;
    novoVoo->hourPartida =hPartida;
    novoVoo->minutePartida=mPartida;
    novoVoo->tempTotal=tempoDeVoo;
    
    
    


    
   
    //write(fileVoo,hashIndex,pos,novoVoo);
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
    printf("HORA %hd  , minuto %hd ",novoAir->hour,novoAir->minute);
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
    FILE *file;
    FILE *fileVoos;
    fileVoos = abrir();
    file = openTable();
    //testar hastable
    dummyItem =  malloc(sizeof(struct air));
    dummyItem->flag = true; //foi "removido"
    char cod[5]="";
    
    char idAir[ID_AIR_SIZE]="";//Declara e inicializa o array de chars a 0
    char idVoo[ID_VOO_SIZE]="";//Declara e inicializa o array de chars a 0
    char idAirPartida[ID_AIR_SIZE]="";//Declara e inicializa o array de chars a 0
    char idAirDestino[ID_AIR_SIZE]="";//Declara e inicializa o array de chars a 0
    short hLocal=0;
    short mLocal=0;
    short duracaoVoo=0;
    //AI LIS 00:00
   
    while(scanf("%s",cod)!=EOF)// enquanto houver mais linhas // le strings
    {
        if (strcmp(cod,"X")==0)
        {
            exitTable(file,hashArray);

            //Termina o programa
            return -1;
        }else if (strcmp(cod,"AI")==0)
        {
            
            scanf("%s %hd:%hd",idAir,&hLocal,&mLocal);
            intrudAir(idAir,hLocal,mLocal);
        }else if (strcmp(cod,"FI")==0)
        {
             //FI IB3111 PDL MAD 09:50 80
            scanf("%s %s %s %hd:%hd %hd",idVoo,idAirPartida,idAirDestino,&hLocal,&mLocal,&duracaoVoo);
            intrudVoo(idVoo,idAirPartida,idAirDestino,hLocal,mLocal,duracaoVoo, fileVoos);
            printf("%s %s %s %hd:%hd %hd\n",idVoo,idAirPartida,idAirDestino,hLocal,mLocal,duracaoVoo);
        }else if (strcmp(cod,"FD")==0)
        {
            //FD BA1
            scanf("%s",idVoo);
            delVoo(idVoo);
            printf("%s\n",idVoo);
        }else if (strcmp(cod,"TR")==0)
        {
            //TR LIS PDL 00:00
            //TR <aeroporto-partida> <aeroporto-destino> <hora-chegada-aeroporto>
            scanf("%s %s %hd:%hd",idAirPartida,idAirDestino,&hLocal,&mLocal);
            calcViagem(idAirPartida,idAirDestino,hLocal,mLocal);
            printf("%s %s %hd:%hd\n",idAirPartida,idAirDestino,hLocal,mLocal);
        }
        
    }


    // //5 Aeroportos de teste
    // struct air *itemA = malloc(sizeof(struct air));
    // char  arrA[5] = "LISB";
    // strcpy(itemA->Id,arrA);
    // itemA->flag =false;
    // insert(itemA);
    // struct air *itemB = malloc(sizeof(struct air));
    // char arrB[5] = "MADR";
    // strcpy(itemB->Id,arrB);
    // itemB->flag =false;
    // insert(itemB);
    // struct air *itemC =  malloc(sizeof(struct air));
    // char arrC[5] = "NY";
    // strcpy(itemC->Id,arrC);
    // itemC->flag =false;
    // insert(itemC);
    // struct air *itemD =  malloc(sizeof(struct air));
    // char arrD[5] = "PORT";
    // strcpy(itemD->Id,arrD);
    // itemD->flag =false;
    // insert(itemD);
    // struct air *itemE =  malloc(sizeof(struct air));
    // char arrE[5] = "LIBA";
    // strcpy(itemE->Id,arrE);
    // itemE->flag =false;
    // insert(itemE);

    // item = search("PORT");

    // if(item != NULL) {
    //     printf("Element found: %s\n", item->Id);
    // } else {
    //     printf("Element not found\n");
    // }

    // delete(item);
    // item = search("LISB");

    // if(item != NULL) {
    //     printf("Element found: %s\n", item->Id);
    // } else {
    //     printf("Element not found\n");
    // }

    //display();


    //disk save
    



    return -1;
}