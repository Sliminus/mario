#include "event.h"

void seDeplacer(Personnage *personnage)
{
    if(personnage->direction == 1)
    {
        personnage->position.x++;
    }
}
