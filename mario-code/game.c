
#include "game.h"
#include "file.h"
#include "charactere.h"
#include "event.h"

int jouer(SDL_Renderer *renderer) {
    SDL_Event event;
    int quit = 1,nb_saut = 0;

    SDL_SetRenderDrawColor(renderer, 255,255,255,255);
    Personnage *mario = malloc(sizeof(Personnage));

    Map *map = malloc(sizeof(Map));
    Sprites *sprites=malloc(sizeof(Sprites)*10);

    loadSprites(renderer, sprites);
    CreerMap(map);

    creerPersonnage(mario,map,renderer);
    while(quit)
    {
        SDL_RenderClear(renderer);
        while(SDL_PollEvent(&event))
        {
            if(event.type == SDL_KEYDOWN)
            {
                if(event.key.keysym.sym == SDLK_LEFT)
                {
                  mario->direction=2;
                  mario->jump=0;
                }
                if(event.key.keysym.sym == SDLK_RIGHT)
                {
                  mario->direction=1;
                  mario->jump=0;
                }
                if(event.key.keysym.sym == SDLK_UP)
                {
                  nb_saut++;
                  mario->jump=1;
                }

            }
            

            if(event.type == SDL_KEYUP)
            {
                if(event.key.keysym.sym == SDLK_LEFT || event.key.keysym.sym == SDLK_RIGHT)
                {
                  mario->direction=0;
                }
                if(event.key.keysym.sym == SDLK_UP)
                {
                  mario->jump=0;
                }
            }

            if(event.type == SDL_QUIT)
            {
                quit = 0;
                break;
            }
            seDeplacer(mario,&nb_saut);
        } 
        AfficherMap(map,sprites,renderer);
        afficherMario(mario,renderer); 
        SDL_RenderPresent(renderer);
    }
    LibererMap(map,sprites);
    freePersonnage(mario);

    return quit;
}