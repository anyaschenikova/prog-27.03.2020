#ifndef BUS
#define BUS
 
typedef struct Bus
{
    char *num;
    char **stops;
    unsigned int max_stop_size;
    unsigned int count;
}Bus;
 
Bus *MakeBus(const char *num, const char **stops, int count, int max_stop_size);
void printBus(Bus b);
int addStop(Bus *b, char *stopName);
void removeStop(Bus *b, char *stopName);
void insertStop(Bus *b, int num, char *stopName);
void changeStop(Bus *b, char *stop, char *new_stop);
void swapStop(Bus *b, int ind1, int ind2);
 
#endif // !BUSES