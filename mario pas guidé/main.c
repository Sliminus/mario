#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>
#include <stdlib.h>

#include "file.h"
#include "game.h"

//ligne de compilation gcc main.c file.c game.c event.c charactere.c -o mario -lSDL2main -lSDL2_image -lSDL2

/*
Le fichier va contenir l'écran d'introduction et va ensuite permettre de basculer sur le jeu en appuyant sur 1. 
Le jeu sera quant à lui géré par le fichier game.c
*/
int main(int argc, char *argv[])
{
    if(SDL_Init(SDL_INIT_VIDEO)== -1)
    {
        printf("Erreur : %s",SDL_GetError());
        return EXIT_FAILURE;
    }
    SDL_Window* window = NULL;
    if((window = SDL_CreateWindow("mario", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,640, 480, SDL_WINDOW_SHOWN))== NULL)
    {
        printf("Erreur : %s",SDL_GetError());
        return EXIT_FAILURE;
    }
    SDL_Renderer* renderer = NULL;
    if((renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED))== NULL)
    {
        printf("Erreur : %s",SDL_GetError());
        return EXIT_FAILURE;
    }
    SDL_RenderClear(renderer);
    SDL_Texture* image = NULL;
    image = loadImage(/img/menu.jpg,renderer);
    SDL_RenderCopy(renderer,image,640,480);
    SDL_RenderPresent(renderer);
    SDL_Delay(1000000);
    SDL_DestroyTexture(image);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}