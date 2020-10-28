#include "protocol.c"

#define START       1
#define END         2

typedef struct{

    char *fileName;            
    int fileSize;

}ApplicationLayer;

int llopen(char *port, int status);

int createControlPacket(char *filename, int type);

int readControlPacket(int fd);
