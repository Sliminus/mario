#include "event.h"

void seDeplacer(Personnage *personnage,int *nb)
{
    if(personnage->direction == 1)
    {
        personnage->position.x = personnage->position.x + 4;
    }
    if(personnage->direction == 2)
    {
        personnage->position.x = personnage->position.x - 4;
    }
    if(*nb == personnage->jumptime)
    {
        for(int i=0;i<*nb;i++)
        {
            personnage->position.y++;
        }
        *nb = 0;
    }else if(personnage->jump == 1)
    {
        personnage->position.y--;
    }
    if(personnage->jump == 0)
    {
        for(int i=0;i<*nb;i++)
        {
            personnage->position.y++;
        }
        *nb=0;
    }
    
}
