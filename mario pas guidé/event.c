#include "event.h"

void event()
{
    int quit = 1;
    while(quit)
    {
        if(event.type == SDL_QUIT)
        {
            quit = 0;
        }
    }
}