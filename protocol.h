#pragma once
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <termios.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

//#define BAUDRATE B38400
#define MODEMDEVICE "/dev/ttyS1"
#define _POSIX_SOURCE 1 /* POSIX compliant source */
#define FALSE 0
#define TRUE 1

#define DISC_CTRL       0x11
#define SET_CTRL        0x03
#define A_ADRESS        0x03
#define FLAG            0x7E
#define UA_CTRL         0x07
#define TRANSMITTER     1
#define RECEIVER        0
#define UA              0
#define SET             1
#define DISC            2
#define DATA_CTRL       3
#define FI_CTRL0        0x00
#define RR0             0x05
#define RR1             0x85
#define REJ0            0x01
#define REJ1            0x81
#define FI_CTRL1        0x40
#define ESC             0x7D
#define STUFF           0x20

typedef struct{

    speed_t baudRate;                   /*Velocidade de transmissão*/
    unsigned int sequenceNumber;

}LinkLayer;

typedef struct{
    int numOfInfoFramesSent;
    int numOfInfoFramesReceived;

    int numOfRRsSent;
    int numOfRRsReceived;
    
    int numOfREJsSent;
    int numOfREJsReceived;

    int timeouts;
}ProtocolStatistics;

void setLinkLayerStruct(speed_t baudrate);

void setProtocolStats();

typedef enum {START, FLAG_R, A_R, C_R, BCC1_R, DATA_R, END} enumStates;

int llopen(char *port, int status);

int sendMessageTransmitter(int fd, int type);

int sendMessageReceiver(int fd, int type);

int verifyFrame(unsigned char *message, int type);

int stateMachine(enumStates* state, unsigned char value);

int openPort(char *port, struct termios *oldtio);

int closePort(int fd, struct termios *oldtio);

int llopen_transmitter(char * port);

int llopen_receiver(char * port);

int llwrite(int fd, unsigned char *buffer, int length);

int writeFrameI(int fd, unsigned char *buffer, int length);

int llclose_transmitter(int fd);

int checkBCCs(unsigned char *buffer, int length, unsigned char *frame, int size);

