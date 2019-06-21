#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "hashtableTodosVoos.h"
//#include "hashtable.h"
//Esta hashtabkle foi implementada com base neste site :
// https://www.tutorialspoint.com/data_structures_algorithms/hash_table_program_in_c.htm


int hashCodeVoos(char key[SIZE_KEYS])
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


int searchVoos(char key[SIZE_KEYS]) {
    //get the hash
    int hashIndex = hashCodeVoos(key);

    //move in array until an empty
    while(hashVoos[hashIndex] != NULL) {

        if(strcmp (hashVoos[hashIndex]->Id,key)==0)
        {
            return hashIndex;
        }

        //go to next cell
        ++hashIndex;

        //wrap around the table
        hashIndex %= SIZE_VOOS;
    }

    return -1;
}

bool insertVoos(struct voosIds* novoVoo) {

    char key[SIZE_KEYS];
    strcpy(key,novoVoo->Id);
    //get the hash
    int hashIndex = hashCodeVoos(key);

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


