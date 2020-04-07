#ifndef BUS_ARRAY
#define BUS_ARRAY
#include "bus.h"
 
typedef struct BusArray
{
    Bus *buses;
    unsigned int count;
    unsigned int max_stop_size;
}BusArray;
 
void printBusArray(BusArray *ba);
int addBusToBusArray(BusArray *ba, Bus *b);
void removeBusFromBusArray(BusArray *ba, Bus *b);
void editBusFromBusArray(BusArray *ba, char *num, char *new_num);
 
#endif