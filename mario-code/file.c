#include <SDL2/SDL_image.h>

#include "file.h"


/*permet de charger une image dans une SDL_Texture avec l'option SDL_TEXTUREACCESS_TARGET
pour pouvoir modifier la texture après. */
SDL_Texture *loadImage(const char path[], SDL_Renderer *renderer)
{
    SDL_Surface *surface = NULL; 
    SDL_Texture *tmp = NULL, *texture = NULL;
    surface = IMG_Load(path);
    if(NULL == surface)
    {
        fprintf(stderr, "Erreur IMG_Load : %s", SDL_GetError());
        return NULL;
    }
    tmp = SDL_CreateTextureFromSurface(renderer, surface);
    if(NULL == tmp)
    {
        fprintf(stderr, "Erreur SDL_CreateTextureFromSurface : %s", SDL_GetError());
        return NULL;
    }
    texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, 
                            SDL_TEXTUREACCESS_TARGET, surface->w, surface->h); 
    if(texture == NULL) 
    {
        fprintf(stderr, "Erreur SDL_CreateTextureFromSurface : %s", SDL_GetError());
        return NULL;
    }
    SDL_SetRenderTarget(renderer, texture); /* La cible de rendu est maintenant texture. */
    SDL_SetTextureBlendMode(tmp, SDL_BLENDMODE_NONE); /* gère la transparence du fond des images*/
    SDL_RenderCopy(renderer, tmp, NULL, NULL); /* On copie tmp sur texture */
    SDL_DestroyTexture(tmp); //nettoyage
    SDL_FreeSurface(surface); //nettoyage
    SDL_SetRenderTarget(renderer, NULL); /* La cible de rendu est de nouveau le renderer. */
    return texture;
}

void loadSprites(SDL_Renderer *renderer, Sprites* sprites)
{
    char png[][30]={"img/sky.png","img/sol.png","img/block.png","img/boite.png","img/tuyau1.png","img/tuyau2.png","img/tuyau3.png","img/tuyau4.png","img/fin1.png","img/fin2.png"};
    int trav[]={0,1,1,1,1,1,1,0,0};
    for(int i=0;i<10;i++)
    {
        sprites[i].sprite=loadImage(png[i],renderer);
        sprites[i].traverser=trav[i];
    }

}


void CreerMap(Map* map)
{
    char nom[25];
    FILE* fd=NULL;
    fd = fopen("level/niveau0.lvl","r");
    if(fd==NULL)
    {
        perror("fichier niveau 0 erreur :");
        EXIT_FAILURE;
    }
    fgets(nom,25,fd);
    int var1,var2;
    fscanf(fd,"%d %d",&var1,&var2);
    map->width=var1;
    map->height=var2;

    map->LoadedMap=malloc(sizeof(int*)*var1);
    for(int i=0;i<var1;i++)
    {
        map->LoadedMap[i]=malloc(sizeof(int*)*var2);
    }

    for(int i=0;i<var1;i++)
    {
        for(int j=0;j<var2;j++)
        {
            fscanf(fd,"%d",&(map->LoadedMap[i][j]));
        }
    }
    map->xscroll=0;
    map->yscroll=0;
    free(fd);

}


void AfficherMap(Map* map, Sprites* sprites,SDL_Renderer *renderer)
{
    for(int i=0;i<30;i++)
    {
        for(int j=0;j<30;j++)
        {
            SDL_Rect srcrect = {0,0,Size_Sprite,Size_Sprite};
            SDL_Rect dstrect = {Size_Sprite*j,Size_Sprite*i,Size_Sprite,Size_Sprite};
            SDL_RenderCopy(renderer,sprites[map->LoadedMap[i+map->xscroll][j+map->yscroll]].sprite,&srcrect,&dstrect);
        }
    }
}



void LibererMap(Map* map, Sprites* sprites)
{
    free(sprites);
    for(int i=0;i<(map->width);i++)
    {
        free(map->LoadedMap[i]);
    }
    free(map->LoadedMap);
    free(map);    
}