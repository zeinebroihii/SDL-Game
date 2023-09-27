#include <stdio.h>
#include <SDL/SDL.h>
#include <stdlib.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>



typedef struct ES ES ;
struct ES
{

SDL_Surface *image;

SDL_Rect espos;

};

int collitrigo(SDL_Surface *  box,SDL_Surface *circle,SDL_Rect boxpos,SDL_Rect circlepos);

void scorecount(int* score , SDL_Surface ** coeur, int etat );

void initializeES(ES* es);

void initializeES2(ES* es);

void mves(SDL_Rect* pos,int* tempsp, int* tempsa, int* v);

void mves2(SDL_Rect* pos,int* tempsp, int* tempsa, int* v);




