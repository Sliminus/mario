
#include "game.h"
#include "file.h"
#include "charactere.h"
#include "event.h"

int jouer(SDL_Renderer *renderer) {
    SDL_Event event;
    int quit = 1,nb = 0;

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
                  seDeplacerGauche(mario);
                }
                if(event.key.keysym.sym == SDLK_RIGHT)
                {
                  mario->direction=1;
                  seDeplacerDroite(mario);
                }
                if(event.key.keysym.sym == SDLK_UP)
                {
                  mario->jump=1;
                  seDeplacerSaut(mario,nb);
                }

            }
            if(event.type == SDL_QUIT)
            {
                quit = 0;
                break;
            }
        } 
        nb = 0;
        AfficherMap(map,sprites,renderer);
        afficherMario(mario,renderer); 
        SDL_RenderPresent(renderer);
    }
    LibererMap(map,sprites);
    freePersonnage(mario);

    return quit;
}