#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include "airTable.h"

#define ID_AIR_SIZE 5
#define ID_VOO_SIZE 7

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
    strcpy(novoVoo->IdAirPartida,IdAirPartida);
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
    //testar hastable
    dummyItem =  malloc(sizeof(struct air));
    dummyItem->flag = true; //foi "removido"
    char cod1='\0';
    char cod2='\0';
    char idAir[ID_AIR_SIZE]="";//Declara e inicializa o array de chars a 0
    char idVoo[ID_VOO_SIZE]="";//Declara e inicializa o array de chars a 0
    char idAirPartida[ID_AIR_SIZE]="";//Declara e inicializa o array de chars a 0
    char idAirDestino[ID_AIR_SIZE]="";//Declara e inicializa o array de chars a 0
    short hLocal=0;
    short mLocal=0;
    short duracaoVoo=0;
    //AI LIS 00:00
   
    while(scanf("%c%c ",&cod1,&cod2)!=EOF)// enquanto houver mais linhas
    {
        if (cod1=='X')
        {
            //Termina o programa
            return -1;
        }else if (cod1=='A' && cod2 == 'I')
        {
            
            for (int i = 0; i < ID_AIR_SIZE-1; i++)
            {
                scanf("%c",&idAir[i]);
                if (idAir[i]==' ')
                {
                    break;
                }
                
            }
            scanf(" %hd:%hd",&hLocal,&mLocal);
            intrudAir(idAir,hLocal,mLocal);
        }else if (cod1=='F' && cod2 == 'I')
        {
             //FI IB3111 PDL MAD 09:50 80
            for (int i = 0; i < ID_VOO_SIZE-1; i++)
            {
                scanf("%c",&idVoo[i]);
                if (idVoo[i]==' ')
                {
                    idVoo[i]='\0';
                    break;
                }
                
            }
            for (int i = 0; i < ID_AIR_SIZE-1; i++)//regista o aeroporto de Partida
            {
                scanf("%c",&idAirPartida[i]);
                printf("I = %d  char = %c",i,idAirPartida[i]);
                if (idAirPartida[i]==' ')
                {
                    idAirPartida[i]='\0';
                    break;
                }
                
            }
            for (int i = 0; i < ID_AIR_SIZE-1; i++)//regista o aeroporto de Chegada
            {
                scanf("%c",&idAirDestino[i]);
                if (idAirDestino[i]==' ')
                {
                    break;
                }
                
            }
            scanf(" %hd:%hd %hd",&hLocal,&mLocal,&duracaoVoo);
            printf("idvoo %s%s C %s hLocal = %hd mLocal= %hd duraçao= %hd",idVoo,idAirPartida,idAirDestino,hLocal,mLocal,duracaoVoo);
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

    display();


    //disk save
    FILE *file;
    file = openTable();
    exitTable(file,hashArray);



    return -1;
}