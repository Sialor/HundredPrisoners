#include "room.h"

#include <stdlib.h>
#include <time.h>

/* don't check valid pointer and size of array
return index of empty element */
static uint16_t GetEmptyBox(uint16_t* room, uint16_t numOfPrisoners)
{
    uint16_t index;

    do
    {
        index = rand() % numOfPrisoners;

        if (room[index] == 0)
        {
            return index;
        }
    } while ( 1 );
}

/* shuffle boxes in room */
static void ShuffleBoxes(uint16_t* room, uint16_t numOfPrisoners)
{
    int i = 0;

    uint16_t min = 1, max = numOfPrisoners + 1;

    srand( (unsigned int)time( NULL ) );

    for ( i = min; i < max; ++i )
    {
        room[GetEmptyBox(room, numOfPrisoners)] = i;
    }
}

uint16_t* Room_Create(uint16_t numOfPrisoners)
{
    uint16_t* room = (uint16_t*)calloc(numOfPrisoners, sizeof(uint16_t));

    ShuffleBoxes(room, numOfPrisoners);

    return room;
}

void Room_Free(uint16_t** room)
{
    if (*room != NULL)
    {
        free(*room);
        *room = NULL;
    }
}