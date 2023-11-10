#include <stdlib.h>
#include <stdio.h>
#include "charactere.h"

void creerPersonnage(Personnage* mario,Map* map,SDL_Renderer* renderer) {
    mario->image=malloc(sizeof(SDL_Texture*)*NUMBER_IMAGE_MARIO);
    mario->image[0]=loadImage("img/Mario1.png",renderer);
    mario->image[1]=loadImage("img/Mario2.png",renderer);
    mario->image[2]=loadImage("img/Mario3.png",renderer);
    mario->image[3]=loadImage("img/Mario4.png",renderer);
    mario->image[4]=loadImage("img/Mario5.png",renderer);
    mario->image[5]=loadImage("img/Mario6.png",renderer);
    mario->position.x=0;
    mario->position.y=0;
    mario->position.w=WIDTH_MARIO;
    mario->position.h=HEIGHT_MARIO;
    mario->jump=0;
    mario->jumptime=0;
    mario->gravite=0;
    mario->direction=0;
    mario->dernieredirection=0;
    mario->temp=0;
    mario->win=0;
    mario->lvl;
}
void afficherMario(Personnage* mario,SDL_Renderer* renderer)
{
    SDL_Event event;
    if(event.type == SDL_KEYDOWN)
    {
        if(event.key.keysym.scancode == SDLK_LEFT)
        {
            int direction=2;
        }
    }
    
    if(event.type == SDL_KEYDOWN)
    {
        if(event.key.keysym.scancode == SDLK_RIGHT)
        {
            int direction=1;
        }
    }
    SDL_Rect srcrect = {0,0,WIDTH_MARIO,HEIGHT_MARIO};
    if(mario->direction==0)
    {
        SDL_RenderCopy(renderer,mario->image[0],&srcrect,&mario->position);
    }
       if(mario->direction==1)
    {
        SDL_RenderCopy(renderer,mario->image[1],&srcrect,&mario->position);
    }
       if(mario->direction==2)
    {
        SDL_RenderCopy(renderer,mario->image[5],&srcrect,&mario->position);
    }
}
void freePersonnage(Personnage* mario) {
    free(mario);
}

/*Personnage **goomba, int nbGoomba*/