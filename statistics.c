#include "statistics.h"

static uint16_t* g_prisoners;
static uint16_t* g_boxes;
static uint16_t g_numOfBoxes = 0; /* same as g_numOfPrisoners */
static uint16_t g_numOfFound = 0;

static void Free(uint16_t** arr)
{
    if (*arr != NULL)
    {
        free(*arr);
        arr = NULL;
    }
}

static void Init(uint16_t** arr)
{
    *arr = (uint16_t*)calloc(g_numOfBoxes, sizeof(uint16_t));
}

void Statistics_Init(uint16_t numOfPrisoners)
{
    g_numOfBoxes = numOfPrisoners;

    g_prisoners = NULL;
    g_boxes = NULL;

    Init(&g_prisoners);
    Init(&g_boxes);
}

void Statistics_Reset()
{
    g_numOfFound = 0;

    Free(&g_prisoners);
    Init(&g_prisoners);

    Free(&g_boxes);
    Init(&g_boxes);
}

void Statistics_Free()
{
    Free(&g_prisoners);
    Free(&g_boxes);
}

void Statistics_OpenBox(uint16_t idPrisoner, uint16_t idBox)
{
    if (g_boxes == NULL || g_numOfBoxes == 0)
    {
        return;
    }

    g_prisoners[idPrisoner]++;
    g_boxes[idBox]++;
}

void Statistics_Found()
{
    g_numOfFound++;
}

void Statistics_Print(FILE* stream)
{
    int i;
 
    if (!stream)
    {
        stream = stdout;
    }

    fprintf(stream, "Number of prisoners (boxes)   = %i\n", g_numOfBoxes);

    for (i = 0; i < g_numOfBoxes; ++i)
    {
        fprintf(stream, "%i prisoners are opened box with id %i\n", g_boxes[i], i);
    }

    for (i = 0; i < g_numOfBoxes; ++i)
    {
        fprintf(stream, "%i box has opened %i prisoners\n", i, g_prisoners[i]);
    }
}