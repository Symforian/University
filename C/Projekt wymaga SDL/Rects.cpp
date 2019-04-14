#include "Rects.h"
void loadRect(anim which,int number,SDL_Rect *old)
{
    (*old).h=300;
    (*old).w=300;
    (*old).x=number*300;
    (*old).y=which*300;
}

void loadCardGraphicRect(int number,SDL_Rect *Graph)
{
    (*Graph).h=100;
    (*Graph).w=75;
    (*Graph).x=number*75;
    (*Graph).y=2700;

}
