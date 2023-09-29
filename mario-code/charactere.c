#include <stdlib.h>
#include <stdio.h>
#include "charactere.h"

void creerPersonnage(Personnage* mario,Map* map) {
    Personnage *mario = malloc(sizeof(Personnage));
    mario->image=malloc(sizeof(SDL_Texture*)*NUMBER_IMAGE_MARIO);
    mario->position.x=0;
    mario->position.y=0;
    mario->position.w=WIDTH_MARIO;
    mario->position.h=HEIGHT_MARIO;
    mario->jump = 0;
    mario->jumptime=0;
    mario->gravite=0;
    mario->direction=0;
    mario->dernieredirection=0;
    mario->temp=0;
    mario->win=0;
    mario->lvl;
    
}
void freePersonnage(Personnage* mario, Personnage **goomba, int nbGoomba) {
    free(mario);
}