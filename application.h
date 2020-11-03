#include "protocol.c"

#define START           1
#define END             2
#define DATA            0x01
#define DEFAULT_PACK    1024

typedef struct{

    char *originalFileName;            
    int originalFileSize;
    int fileDes;
    int fileDesNewFile;
    int porta_serie;
    char *duplicateFileName;
    int duplicatePacketSize;
    int controlPacketSize;

}ApplicationLayer;

int llopen(char *port, int status);

void setUpPacketSize(int packet_size);

void readFileData(char *filename);

int createControlPacket(int fd, int type);

int readControlPacket(int fd);

int createDataPacket();

int writeDataPackets(unsigned char *packet);

int sendFile(int fd);

int readFile(int fd);
