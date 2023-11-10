#include "event.h"

void seDeplacer(Personnage *personnage)
{
    switch (personnage->direction)
    {
    case 1:
        personnage->position.x = personnage->position.x + 4;
        break;
    case 2:
        personnage->position.x = personnage->position.x - 4;
        break;
    
    default:
        break;
    }
    


}
