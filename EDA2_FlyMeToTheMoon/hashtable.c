#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "hashtable.h"






int hashCode(char key[5])
{
    int res=0;
    for (int i = 0; i < 5; i++)
    {
        if(key[i]!='\0')
        {
            res=res + (int) key[i];
        }
    }

    return res % SIZE;
}

struct air *search(char key[5]) {
    //get the hash
    int hashIndex = hashCode(key);

    //move in array until an empty
    while(hashArray[hashIndex] != NULL) {

        if(strcmp (hashArray[hashIndex]->Id,key)==0)
        {
            return hashArray[hashIndex];
        }

        //go to next cell
        ++hashIndex;

        //wrap around the table
        hashIndex %= SIZE;
    }

    return NULL;
}

bool insert(struct air* novoAir) {

    //struct air *item = (struct air*) malloc(sizeof(struct air));
    char key[5];
    strcpy(key,novoAir->Id);
    //get the hash
    int hashIndex = hashCode(key);

    //move in array until an empty or deleted cel
    while(hashArray[hashIndex] != NULL && hashArray[hashIndex]->flag!=true)
    {
        if (strcmp(hashArray[hashIndex]->Id, novoAir->Id)==0)//Para não deixar que haja dois aeroportos iguais na hastable
        {


            return false;
        }

        //go to next cell
        ++hashIndex;

        //wrap around the table
        hashIndex %= SIZE;
    }

    hashArray[hashIndex] = novoAir;
    return true;

}

struct air* delete(struct air* item) {
    char key[5];
    strcpy(key,item->Id);

    //get the hash
    int hashIndex = hashCode(key);

    //move in array until an empty
    while(hashArray[hashIndex] != NULL) {

        if(strcmp (hashArray[hashIndex]->Id,key)==0) {
            struct air* temp = hashArray[hashIndex];

            //assign a dummy item at deleted position
            hashArray[hashIndex] = dummyItem;
            return temp;
        }

        //go to next cell
        ++hashIndex;

        //wrap around the table
        hashIndex %= SIZE;
    }

    return NULL;
}

void display() {
    int i = 0;

    for(i = 0; i<SIZE; i++)
    {

        if(hashArray[i] != NULL)
        {
            printf(" (%s)",hashArray[i]->Id);
        }
        else
        {
            //printf(" ; ");
        }

    }

    printf("\n");
}


