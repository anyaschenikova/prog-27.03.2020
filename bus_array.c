#include "bus_array.h"
#include <malloc.h>
#include "bus.h"
#include<stdio.h>
#include <string.h>
 
void printBusArray(BusArray *ba) {
    for (int i = 0; i < ba->count; i++)
    {
        printBus(ba->buses[i]);
    }    
}
 
int addBusToBusArray(BusArray *ba, Bus *b) {
    if((ba->count + 1) < ba->max_stop_size) {
        ba->buses = (Bus *) realloc(ba->buses, (ba->count + 1) * sizeof(Bus));
        if(!ba->buses) {
            printf("size error!\n");
        }
        ba->buses[ba->count] = *b;
        ba->count++;
        return 1;
    }
    return -1;
 
}
void removeBusFromBusArray(BusArray *ba, Bus *b) {
    int i = 0;
    for (i = 0; i < ba->count; i++)
    {
        if (!strcmp(ba->buses[i].num, b->num))
            break;
    }
    for (int j = i; j < ba->count - 1; j++)
    {
        ba->buses[j] = *b;
    }
    ba->count--;
}
 
void editBusFromBusArray(BusArray *ba, char *num, char *new_num) {
    int i;
    for (i = 0; i < ba->count; i++)
    {
        if(!strcmp(num, ba->buses[i].num)) {
            break;
        }
    }
    free(ba->buses[i].num);
    ba->buses[i].num = new_num;
}