#include "recursive_solution.h"

static void OpenBox(uint16_t* room, uint16_t idPrisoner, uint16_t currentIdBox)
{
    uint16_t idNextBox = room[currentIdBox] - 1;

    Statistics_OpenBox(idPrisoner, currentIdBox);

    if (idNextBox == idPrisoner)
    {
        Statistics_Found();
        return;
    }

    OpenBox(room, idPrisoner, idNextBox);
}

void RecursiveSolution_Run(uint16_t* room, uint16_t idPrisoner)
{
    OpenBox(room, idPrisoner - 1 /* bc first prisoner has ONE label */, idPrisoner - 1);
}