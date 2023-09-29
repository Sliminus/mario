
#include "game.h"
#include "file.h"
#include "charactere.h"
#include "event.h"

int jouer(SDL_Renderer *renderer) {
    SDL_Event event;
    int quit = 1;

    SDL_SetRenderDrawColor(renderer, 255,255,255,255);
    Personnage *mario = malloc(sizeof(Personnage));

    Map *map = malloc(sizeof(Map));
    //Sprites *sprite[10]=malloc(sizeof(Sprites));

    CreerMap(map);

    creerPersonnage(mario,map);
    while(quit)
    {
        SDL_RenderClear(renderer);
        while(SDL_PollEvent(&event))
        {
            if(event.type == SDL_QUIT)
            {
                quit = 0;
                break;
            }
        }   

        SDL_RenderPresent(renderer);
    }

    freePersonnage(mario);
}