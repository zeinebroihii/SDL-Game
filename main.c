#include "fonction.h"

void pause()
{
    int continuer = 1;
    SDL_Event event;
 
    while (continuer)
    {
        SDL_WaitEvent(&event);
        switch(event.type)
        {
            case SDL_QUIT:
                continuer = 0;
        }
    }
}

int main (void)
{
SDL_Surface *screen =NULL;
SDL_Init(SDL_INIT_VIDEO);
SDL_EnableKeyRepeat(10,40);
int continuer=1;
screen = SDL_SetVideoMode(1500,480,32,SDL_HWSURFACE | SDL_DOUBLEBUF | SDL_RESIZABLE);
SDL_Surface *fond=NULL,*perso,*circlea,*circleb,*coeur;
SDL_Rect positionfond,persopos,circleapos,circlebpos,poscoeur;

SDL_Event event;

int tempsp=0,tempsa=0;
int v=1;
int tempspb=0,tempsab=0;
int vb=1;
ES es,es2;
initializeES(&es);
initializeES2(&es2);
int mvd=0,mvg=0,verif1=0,verif2=0,etat;
int score=0;

poscoeur.x=0;
poscoeur.y=0;
coeur= IMG_Load("v4.png");


positionfond.x=0;
positionfond.y=0;
fond= IMG_Load("background.png");



perso=IMG_Load("perso.png");
persopos.x=650;
persopos.y=330;
int x=1;
int xb=1;
while (continuer == 1)
    {
if(x)
mves(&es.espos,&tempsp,&tempsa,&v);
if(xb)
mves2(&es2.espos,&tempspb,&tempsab,&vb);
        SDL_PollEvent(&event);
        switch(event.type)
        {



            case SDL_QUIT:
                continuer = 0;

SDL_Quit();
                break;
	    case SDL_MOUSEMOTION: 
			
                        break;
            case SDL_KEYDOWN:
                switch(event.key.keysym.sym)
                {   
		    case SDLK_ESCAPE:
			continuer=0;
			break; 
		   
                   
                    case SDLK_RIGHT:

etat=0;
verif2=0;
if(mvd==1)
{

persopos.x+=20;
mvd=0;
}
else
{
if(collitrigo(perso,circlea,persopos,es.espos))
{

persopos.x+=20;
x=1;

}
else {mvg=1;
     x=0; 
if (!verif1)
{scorecount(&score,&coeur,etat);
verif1=1;

}
}  


}

		    break;

                    case SDLK_LEFT: 
etat=1;
verif1=0;
if(mvg==1)
{

persopos.x-=20;
mvg=0;
}
else
{ 
if(collitrigo(perso,circleb,persopos,es2.espos))
{persopos.x-=20;
xb=1;}
else {mvd=1;
xb=0;
if (!verif2)
{scorecount(&score,&coeur,etat);
verif2=1;
}

 }     
}   
                      break;
		    
                }
               

                
}
 
SDL_BlitSurface(fond,NULL,screen, &positionfond);
SDL_BlitSurface(es.image,NULL,screen, &es.espos);
SDL_BlitSurface(es2.image,NULL,screen, &es2.espos);
SDL_BlitSurface(perso,NULL,screen, &persopos);
SDL_BlitSurface(coeur,NULL,screen, &poscoeur);

SDL_Flip(screen);
}

}

