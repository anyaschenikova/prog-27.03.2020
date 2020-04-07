#include "bus.h"
#include<string.h>
#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
 
void printBus(Bus b)
{
    printf("==================\n");
    printf("Bus number: %s\n", b.num);
    printf("Stops:\n");
    for (int i = 0; i < b.count; i++)
    {
        printf("%s\n", b.stops[i]);
    }
   
}
 
Bus *MakeBus(const char *num, const char **stops, int count, int max_stop_size)
{
    Bus *b = malloc(sizeof(Bus));
    b->num = malloc((strlen(num) + 1) * sizeof(char));
    strcpy(b->num, num);
    b->stops = malloc((count + 1) * sizeof(char *));
    for (int i = 0; i < count; i++)
    {
        b->stops[i] = malloc((strlen(stops[i]) + 1) * sizeof(char));
        strcpy(b->stops[i], stops[i]);
    }
    b->count = count;
    b->max_stop_size = max_stop_size;
    return b;
}
 
int addStop(Bus *b,char *stopName) {
    if((b->count + 1) < b->max_stop_size) {
        b->stops[b->count] = (char *) malloc(strlen(stopName) * sizeof(char));
        strcpy(b->stops[b->count], stopName);
        b->count++;
        return 1;
    }
    return -1;
}
void removeStop(Bus *b, char *stopName) {
    int i = 0;
    for (i = 0; i < b->count; i++)
    {
        if (!strcmp(b->stops[i], stopName))
            break;
    }
    for (int j = i; j < b->count - 1; j++)
    {
        free(b->stops[j]);
        b->stops[j] = (char *) malloc((strlen(b->stops[j+1]) + 1) * sizeof(char));
        strcpy(b->stops[j], b->stops[j+1]);
    }
    b->count--;
    b->stops = (char **) realloc(b->stops, b->count);
   
}
 
void changeStop(Bus *b, char *stop, char *new_stop) {
    int i = 0;
    for (i = 0; i < b->count; i++)
    {
        if (!strcmp(b->stops[i], stop))
            break;
    }
    free(b->stops[i]);
    b->stops[i] = new_stop;
}
 
 
 
void swapStop(Bus *b, int ind1, int ind2) {
    char *tmp = (char *) malloc(999 * sizeof(char));
    strcpy(tmp, b->stops[ind1]);
    free(b->stops[ind1]);
    b->stops[ind1] = (char *) malloc(strlen(b->stops[ind2]) * sizeof(char));
    strcpy(b->stops[ind1], b->stops[ind2]);
    free(b->stops[ind2]);
    b->stops[ind2] = (char *) malloc(strlen(tmp) * sizeof(char));
    strcpy(b->stops[ind2], tmp);
    free(tmp);
}
 
void insertStop(Bus *b, int ind, char *stopName) {
    b->count++;
    b->stops = (char **) realloc(b->stops, (b->count) * sizeof(char));
    for (int i = b->count -1; i > ind; i--)
    {
        b->stops[i] = b->stops[i-1];
    }
    b->stops[ind] = stopName;
}