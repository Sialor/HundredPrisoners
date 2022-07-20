#include "room.h"
#include "statistics.h"
#include "recursive_solution.h"

/* default is 100 */
const uint16_t numberOfPrisoners = 8;

int main()
{
	uint16_t start = 1, end = numberOfPrisoners;

	uint16_t i;

	uint16_t* testChamber = Room_Create(numberOfPrisoners);

	Statistics_Init(numberOfPrisoners);

	for (i = start; i <= end; ++i)
	{
		RecursiveSolution_Run(testChamber, i);
	}

	Statistics_Print(NULL);

	Statistics_Free();

	Room_Free(&testChamber);

	return 0;
}