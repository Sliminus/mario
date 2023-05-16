#include "event.h"

void event()
{
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
}