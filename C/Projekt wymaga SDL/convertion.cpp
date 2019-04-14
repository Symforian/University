#include "Global.h"
int posToRend(char z, int value)
{
    if(z=='x')
    {
        switch(value)
        {
        case 1:
            return 0;
        case 2:
            return 250;
        case 3:
            return 500;
        case 4:
            return 750;
        case 5:
            return 1000;
        }
    }
    else
        switch(value)
    {
    case 1:
        return 60;
    case 2:
        return 120;
    case 3:
        return 180;
    }
    return -1;
}
bool isPossible(int x, int y, int w)
{
    bool possible=true;
    switch (w)
    {
        case 1:
            if(y==1)
                possible=false;
                break;
        case 2:
            if(x==1)
                possible=false;
            break;
        case 3:
            if(y==3)
                possible=false;
            break;
        case 4:
            if(x==5)
                possible=false;
            break;
    }
    return possible;
}

void playOtherCard(Character* player,int id)
{
    if((*player).hand[id].status=="Heal")
     {
         (*player).champion_code.hp+=(*player).hand[id].value;
         if((*player).champion_code.hp>200)
         (*player).champion_code.hp-=(*player).champion_code.hp%200;
     }
     else if((*player).hand[id].status=="Red")
        (*player).champion_code.reduction=(*player).hand[id].value;


}
int renderFloorLights(char z,int coord)
{
    if(z=='x')
    {
        switch(coord)
        {
        case 1:
            return 0;
        case 2:
            return 255;
        case 3:
            return 511;
        case 4:
            return 767;
        case 5:
            return 1023;
        }
    }
    else
        switch(coord)
    {
    case 1:
        return 300;
    case 2:
        return 360;
    case 3:
        return 420;
    }
    return -1;
}
