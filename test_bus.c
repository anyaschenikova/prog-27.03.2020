#include "bus.h"
#define SIZE 3
#include "bus_array.h"
#include<stdio.h>
#include<malloc.h>
#include<string.h>
 
int main() {
    const char *stops[] = {
        "start",
        "pause",
        "finish"
    };
 
    // printf("Enter number: \n");
    // char *num1 = (char *) malloc(100 * sizeof(char));
    // scanf("%s", num1);
    // num1 = realloc(num1,  strlen(num1));
 
    // printf("Enter number: \n");
    // char *num2 = (char *) malloc(100 * sizeof(char));
    // scanf("%s", num2);
    // num2 = realloc(num2,  strlen(num2));
 
    // printf("Enter number: \n");
    // char *num3 = (char *) malloc(100 * sizeof(char));
    // scanf("%s", num3);
    // num3 = realloc(num3,  strlen(num3));
 
 
    // Bus *b1 = MakeBus(num1, stops, 3, 5);
    // Bus *b2 = MakeBus(num2, stops, 3, 5);
    // Bus *b3 = MakeBus(num3, stops, 3, 5);
 
    // BusArray *ba = (BusArray *) malloc(SIZE * sizeof(Bus));
    // ba->count= 0;
    // ba->max_stop_size = SIZE + 2;
    // addBusToBusArray(ba, b1);
    // addBusToBusArray(ba, b2);
    // addBusToBusArray(ba, b3);
 
    // printBusArray(ba);
 
 
    // removeBusFromBusArray(ba, b1);
    // printBusArray(ba);
 
    // printf("Enter number: \n");
    // char *new_num = (char *) malloc(100 * sizeof(char));
    // scanf("%s", new_num);
    // new_num = realloc(new_num,  strlen(new_num));
    // editBusFromBusArray(ba, num1, new_num);
    // printBusArray(ba);
 
 
 
    printf("Enter number: \n");
    char *num = (char *) malloc(100 * sizeof(char));
    scanf("%s", num);
    num = realloc(num,  strlen(num));
 
    Bus *b = MakeBus(num, stops, 3, 5);
    printBus(*b);
 
 
    printf("Enter stopname: \n");
    char *new_stop = (char *) malloc(100 * sizeof(char));
    scanf("%s", new_stop);
    new_stop = realloc(new_stop,  strlen(new_stop));
 
    addStop(b, new_stop);
 
    removeStop(b, b->stops[2]);
    printBus(*b);
 
    printf("Enter stopname: \n");
    char *new_stop2 = (char *) malloc(100 * sizeof(char));
    scanf("%s", new_stop2);
    new_stop2 = realloc(new_stop2,  strlen(new_stop2));
 
 
    addStop(b, new_stop2);
    changeStop(b, b->stops[1], b->stops[2]);
    printBus(*b);
 
    swapStop(b, 1, 2);
    printBus(*b);
 
    printf("Enter stopname: \n");
    char *new_stop3 = (char *) malloc(100 * sizeof(char));
    scanf("%s", new_stop3);
    new_stop3 = realloc(new_stop3,  strlen(new_stop3));
    insertStop(b, 1, new_stop3);
    printBus(*b);
 
 
    // for (int i = 0; i < b->count; i++)
    // {
    //     free(b->stops[i]);
    // }
    // free(b->stops);
    free(b);
 
    // for (int i = 0; i < ba->count; i++)
    // {
    //     for (int j = 0; j < ba->buses[i].count; j++)
    //     {  
    //         free(ba->buses[i].stops[j]);
    //     }
    //     free(ba->buses[i].stops);
    //     free(ba->buses[i].num);
    // }
   
    // free(ba);
    return 0;
}