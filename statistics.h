#ifndef _H_STATISTICS
#define _H_STATISTICS

#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>

void Statistics_Init(uint16_t numOfPrisoners);

void Statistics_Reset();

void Statistics_OpenBox(uint16_t idPrisoner, uint16_t idBox);

void Statistics_Found();

/* if stream is NULL, then stream = stdout */
void Statistics_Print(FILE* stream);

void Statistics_Free();

#endif