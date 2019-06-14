#include <stdio.h>

struct air
{
    char Id[5];
    short hour;
    short minute;
    char IdPrecessor[5];
    short tempoTotalDiskt;

};

struct voos
{
    char Id[7];
    char IdAirChegada[5];
    short hourPartida;
    short minutePartida;
    short hourChegada;
    short minuteChegada;
    short tempTotal;
};


struct flightsPerAir{
//        struct voos voosTemp[voosPorAir];
};

/*
int main(void)
{
    printf("Size of air = %lu Bytes  \nSize of voos = %lu  Bytes \n", sizeof(struct air),sizeof(struct voos));
    return -1;
}
 */