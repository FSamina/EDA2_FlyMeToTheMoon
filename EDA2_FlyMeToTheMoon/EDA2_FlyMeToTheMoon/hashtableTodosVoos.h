#include "aeroportoVoo.h"

#define SIZE_KEYS 7
#define SIZE_VOOS 2000000
//aproxim 7mb
struct voosIds* hashVoos[SIZE_VOOS];

int hashCodeVoos(char key[SIZE_KEYS]);

int  searchVoos(char key[SIZE_KEYS]);

bool insertVoos(struct voosIds* novoVoo);

void displayVoos();