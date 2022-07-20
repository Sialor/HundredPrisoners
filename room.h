#ifndef _H_ROOM
#define _H_ROOM

#include <stdint.h>

/* array alloc with random boxes */
uint16_t* Room_Create(uint16_t numOfPrisoners);

void Room_Free(uint16_t** room);

#endif