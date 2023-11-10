#include "event.h"

void seDeplacerDroite(Personnage *personnage)
{
    personnage->position.x = personnage->position.x + 4;
}
void seDeplacerGauche(Personnage *personnage)
{
    personnage->position.x = personnage->position.x - 4;
}
void seDeplacerSaut(Personnage *personnage,int nb)
{   
    if(nb <personnage->jumptime)
    {
        personnage->position.y--;
    }

}
