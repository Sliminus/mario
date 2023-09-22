#include <stdlib.h>
#include <stdio.h>
#include "charactere.h"
 #define WIDTH_MARIO 30 
#define HEIGHT_MARIO 40 
#define NUMBER_IMAGE_MARIO 6 

void creerPersonnage(Personnage* mario) {
    Personnage *mario = malloc(sizeof(Personnage));
    mario->SDL_Texture** image=malloc(sizeof(SDL_Texture* image*NUMBER_IMAGE_MARIO));
    mario->SDL_Rect={0,0,HEIGHT_MARIO,WIDTH_MARIO};
    mario->jump = 0;
    mario->jumptime=0;
    mario->gravite=0;
    mario->direction=0;
    mario->dernieredirection=0;
    mario->temp;
    mario->win=0;
    mario->lvl;
    
}
void freePersonnage(Personnage* mario, Personnage **goomba, int nbGoomba) {
    free(mario);
}