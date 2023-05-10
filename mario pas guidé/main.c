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
        perror("erreur");
        SDL_QUIT();
    }
     if((window = SDL_CreateWindow("mario", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,640, 480, SDL_WINDOW_SHOWN))== NULL)
    {
        perror("erreur");
        SDL_QUIT();
    }
    
    //SDL_Window* SDL_CreateWindow(const char* title, int x, int y, int w, int h, Uint32 flags)
    //SDL_Renderer* SDL_CreateRenderer(SDL_Window* window, int index, Uint32 flags)
    //SDL_Texture* SDL_CreateTexture(SDL_Renderer* renderer, Uint32 format, int access, int w, int h)


    //SDL_Surface * IMG_Load(const char *file)
}