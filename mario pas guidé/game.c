
#include "game.h"
#include "file.h"
#include "charactere.h"
#include "event.h"

int jouer(SDL_Renderer *renderer) {
    SDL_Event event;
    int quit = 1;
    while(quit)
    {
        while(SDL_PollEvent(&event))
        {
            if(event.type == SDL_QUIT)
            {
                quit = 0;
                break;
            }
        }   
    }

    return 0;

}