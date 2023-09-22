#include <stdlib.h>
#include <stdio.h>
#include "charactere.h"
 #define WIDTH_MARIO 30 
#define HEIGHT_MARIO 40 
#define NUMBER_IMAGE_MARIO 6 

void creerPersonnage() {
    Personnage *mario = malloc(sizeof(Personnage));
    
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