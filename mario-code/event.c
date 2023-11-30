#include "event.h"

void seDeplacer(Personnage *personnage)
{
    if(personnage->direction == 1)
    {
        personnage->position.x = personnage->position.x + 2;
    }
    if(personnage->direction == 2)
    {
        personnage->position.x = personnage->position.x - 2;
    }
    if(personnage->jumptime == 70 || personnage->jump == 0)
    {
        for(int i=0;i<personnage->jumptime;i++)
        {
            personnage->position.y++;
        }
        personnage->jumptime = 0;
    }
    if(personnage->jump == 1)
    {
        personnage->jumptime++;
        personnage->position.y--;
    }
    
}

void scroll(Personnage *personnage,Map *map)
{
    if((personnage->position.x > 550) && (personnage->direction == 1))
    {
        if((map->xscroll+30) != (map->width))
        {
            map->xscroll ++;
            personnage->position.x -= Size_Sprite_dest;
        }
    }
    if((personnage->position.x < 350) && (personnage->direction == 2))
    {
        if(map->xscroll != 0)
        {
            map->xscroll --;
            personnage->position.x += Size_Sprite_dest;
        }
    }
}