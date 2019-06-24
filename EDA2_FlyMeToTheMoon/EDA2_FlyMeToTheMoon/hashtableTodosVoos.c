#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "hashtableTodosVoos.h"
//#include "hashtable.h"
//Esta hashtabkle foi implementada com base neste site :
// https://www.tutorialspoint.com/data_structures_algorithms/hash_table_program_in_c.htm


unsigned int hashCodeVoos(char key[SIZE_KEYS])
{
    int res=0;
    for (int i = 0; i < SIZE_KEYS; i++)
    {
        if(key[i]!='\0')
        {
            res=res + (int) key[i];
        }
    }

    return res % SIZE_VOOS;
}


struct voosIds* searchVoos(char key[SIZE_KEYS]) {
    //get the hash
     unsigned int hashIndex = hashCodeVoos(key);

    //move in array until an empty
    while(hashVoos[hashIndex] != NULL) {

        if(strcmp (hashVoos[hashIndex]->Id,key)==0)
        {
            return hashVoos[hashIndex];
        }

        //go to next cell
        ++hashIndex;

        //wrap around the table
        hashIndex %= SIZE_VOOS;
    }

    return NULL;
}

bool insertVoos(struct voosIds* novoVoo) {

    char key[SIZE_KEYS];
    strcpy(key,novoVoo->Id);
    //get the hash
    unsigned int hashIndex = hashCodeVoos(key);

    //move in array until an empty or deleted cel
    while(hashVoos[hashIndex] != NULL && hashVoos[hashIndex]->flagDesativo!=true)
    {
        if (strcmp(hashVoos[hashIndex]->Id, novoVoo->Id)==0)//Para não deixar que haja dois aeroportos iguais na hastable
        {


            return false;
        }

        //go to next cell
        ++hashIndex;

        //wrap around the table
        hashIndex %= SIZE_VOOS;
    }

    novoVoo->indexProprio = hashIndex; //Para termos o hashIndex se formos fazer delete saber em que indice vamos rescrever o Voo
    hashVoos[hashIndex] = novoVoo;
    return true;

}

void displayVoos() {
    int i = 0;

    for(i = 0; i<SIZE_VOOS; i++)
    {

        if(hashVoos[i] != NULL)
        {
            printf(" (%s)",hashVoos[i]->Id);
        }
        else
        {
            //printf(" ; ");
        }

    }

    printf("\n");
}


