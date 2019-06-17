#include "aeroportoVoo.h"

#define SIZE 200003
struct air * hashArray[SIZE];
struct air* dummyItem;
struct air* item;

int hashCode(char key[5]);

struct air * search(char key[5]);

bool insert(struct air* novoAir);

struct air* delete(struct air* item);

void display();