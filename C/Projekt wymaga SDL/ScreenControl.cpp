#include "Global.h"
#include "ScreenControl.h"
#include "sequence.h"
#include "convertion.h"
#include <iostream>
using namespace std;
int W=0;//Winner
extern Texture gTexture;
extern Character gP1T;
extern Character gP2T;
extern SDL_Renderer* gRenderer;
string P1="0";
string P2="0";
bool quit=false;
int T=0;
int Screen=Starting_Screen;
SDL_Event e;
Uint32 startTime = 0;
void ScreenControl()
{

                while(quit==false)
                {
                    switch (Screen)
                {
                case Starting_Screen:
                    Start();
                    break;
                case Character_Selection_Screen_Player_1:
                    Selection(1);
                    break;
                case Character_Selection_Screen_Player_2:
                    Selection(2);
                    break;
                case Before_Player_1_Turn:
                    Before(1);
                    break;
                case Player_1_Turn:
                    Turn(1);
                    break;
                case Before_Player_2_Turn:
                    Before(2);
                    break;
                case Player_2_Turn:
                    Turn(2);
                    break;
                case Action_Screen:
                    Action();
                    break;
                case Ending_Screen:
                    Result(W);
                    break;
                case THERE_IS_NO_MOAR_SCREEN:
                    printf("Error u shouldn't be there; Check ScreenControl\n");
                    break;
                }

                }
}




void Start()
{
    //Sciezki
    ///
    gTexture.loadFromFile("grafika/ekrany/0.png");
    Texture A;
    A.loadFromFile("grafika/buttons/0/newPlay.png");
    Texture B;
    B.loadFromFile("grafika/buttons/0/ex.png");
    ///
     SDL_Rect ButtonS[3];
     {
        ButtonS[0].h=760;
        ButtonS[0].w=1280;
        ButtonS[0].x=0;
        ButtonS[0].y=0;

        ButtonS[1].h=760;
        ButtonS[1].w=1280;
        ButtonS[1].x=0;
        ButtonS[1].y=760;

        ButtonS[2].h=760;
        ButtonS[2].w=1280;
        ButtonS[2].x=0;
        ButtonS[2].y=1520;
     }


    int S=0,E=0;
    int mX,mY;

    while(!quit)
        {
        S=0;
        E=0;

        SDL_GetMouseState(&mX,&mY);
        //obsluga eventow
        while( SDL_PollEvent( &e ) != 0 )
            {
                //Kliknieto X lub escape'a
            if( e.type == SDL_QUIT || (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_ESCAPE))
                {
                            quit = true;
                }
                else
                    {

                        if(mX>=436 && mX<=793 && mY>=276 && mY<=376)
                            {
                                S=1;
                            if(e.type == SDL_MOUSEBUTTONDOWN)
                               {
                                   S=2;
                               }
                            if(e.type == SDL_MOUSEBUTTONUP)
                               {
                                    Screen++;
                                    A.freeT();
                                    B.freeT();
                                   break;
                               }
                            }
                        if(mX>=496 && mX<=726 && mY>=450 && mY<=524)
                            {
                                E=1;
                            if(e.type == SDL_MOUSEBUTTONDOWN)
                                E=2;
                            if(e.type == SDL_MOUSEBUTTONUP)
                                quit=true;

                            }


                    }
                //Renderowanie
                {
                SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
				SDL_RenderClear( gRenderer );
                gTexture.render(0,0,NULL);
                A.render(0,0,&ButtonS[S]);
                B.render(0,0,&ButtonS[E]);
				SDL_RenderPresent( gRenderer );
				}
            }

                A.freeT();
				B.freeT();
                break;

        }
}
void Selection(int Player)
{
    if(Player==1)
{
gP1T.posX=2;
gP1T.posY=2;
gP2T.posX=4;
gP2T.posY=2;
gP1T.toLeft=SDL_FLIP_NONE;
gP2T.toLeft=SDL_FLIP_HORIZONTAL;
}
gTexture.loadFromFile("grafika/ekrany/1.png");
Texture cont;
cont.loadFromFile("grafika/buttons/1/continue.png");
SDL_Rect contButton[4];
{
        contButton[0].h=720;
        contButton[0].w=1280;
        contButton[0].x=0;
        contButton[0].y=2160;

        contButton[1].h=720;
        contButton[1].w=1280;
        contButton[1].x=0;
        contButton[1].y=0;

        contButton[2].h=720;
        contButton[2].w=1280;
        contButton[2].x=0;
        contButton[2].y=720;

        contButton[3].h=720;
        contButton[3].w=1280;
        contButton[3].x=0;
        contButton[3].y=1440;
}
Texture champ[6];
champ[0].loadFromFile("grafika/buttons/1/Gratian.png");
for(int i=1;i<6;i++)
    champ[i].loadFromFile("grafika/buttons/1/EMPTY.png");

  //obsluga eventow
   int C=0;
    int mX,mY;
    while(!quit)
        {
            if((Player==1 && P1!="0")||(Player==2 && P2!="0"))
                C=1;

        SDL_GetMouseState(&mX,&mY);
        //obsluga eventow
        while( SDL_PollEvent( &e ) != 0 )
            {
                //Kliknieto X lub escape'a
            if( e.type == SDL_QUIT || (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_ESCAPE))
                {
                            quit = true;
                }
                else
                    {
                        if((Player==1 && P1!="0")||(Player==2 && P2!="0"))
                        {
                            if(mX>=467 && mX<=790 && mY>=600 && mY<=656)
                                {
                                    C=2;
                                if(e.type == SDL_MOUSEBUTTONDOWN)
                                   {
                                       C=3;
                                   }
                                if(e.type == SDL_MOUSEBUTTONUP)
                                   {
                                        Screen++;
                                       break;
                                   }
                            }
                        }
                        if(mX>=438 && mX<=513 && mY>=220 && mY<=320)
                            {
                            if(e.type == SDL_MOUSEBUTTONDOWN)
                            {
                                if(Player==1)
                                    {
                                        P1="Gratian";
                                       loadCharacter(P1,&gP1T);
                                    }
                                else
                                    {
                                        P2="Gratian";
                                        loadCharacter(P2,&gP2T);
                                    }
                            }
                            }

                    }
                SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
				SDL_RenderClear( gRenderer );
                gTexture.render(0,0,NULL);
                champ[0].render(438,220,NULL);
                champ[1].render(618,220,NULL);
                champ[2].render(780,220,NULL);
                champ[3].render(438,354,NULL);
                champ[4].render(618,354,NULL);
                champ[5].render(780,354,NULL);
                if(P1=="Gratian")
                    champ[0].render(247,191,NULL);
                if(P2=="Gratian")
                    champ[0].render(972,179,NULL);
                cont.render(0,0,&contButton[C]);
				SDL_RenderPresent( gRenderer );
            }
        cont.freeT();
for(int i=0;i<6;i++)
    champ[i].freeT();
    break;
        }


}

void Before(int Player)
{
    if(Player==1)
            clearSequences();

    if(Player==1)
    gTexture.loadFromFile("grafika/ekrany/p1t.png");
    else
    gTexture.loadFromFile("grafika/ekrany/p2t.png");
    Texture cont;
    cont.loadFromFile("grafika/buttons/1/continue.png");

    SDL_Rect contButton[3];
        {
        contButton[0].h=720;
        contButton[0].w=1280;
        contButton[0].x=0;
        contButton[0].y=0;

        contButton[1].h=720;
        contButton[1].w=1280;
        contButton[1].x=0;
        contButton[1].y=720;

        contButton[2].h=720;
        contButton[2].w=1280;
        contButton[2].x=0;
        contButton[2].y=1440;
        }

    int mX,mY;
    int C=0;
    while(!quit)
    {
        C=0;

        SDL_GetMouseState(&mX,&mY);
            while( SDL_PollEvent( &e ) != 0 )
            {
                //Kliknieto X lub escape'a
            if( e.type == SDL_QUIT || (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_ESCAPE))
                {
                            quit = true;
                }
                 if(mX>=467 && mX<=790 && mY>=600 && mY<=656)
                {
                    C=1;
                    if(e.type == SDL_MOUSEBUTTONDOWN)
                    {
                        C=2;
                    }
                    if(e.type == SDL_MOUSEBUTTONUP)
                    {
                        Screen++;
                        break;
                    }
                }
                {
                SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
				SDL_RenderClear( gRenderer );
                gTexture.render(0,0,NULL);
                cont.render(0,0,&contButton[C]);
                SDL_RenderPresent( gRenderer );
                }
            }

        if(Screen!=Before_Player_1_Turn && Screen!=Before_Player_2_Turn)
            break;
    }
        cont.freeT();

}

void Turn(int Player)
{
    int x1=posToRend('x',gP1T.posX);
    int y1=posToRend('y',gP1T.posY);
    int x2=posToRend('x',gP2T.posX);
    int y2=posToRend('y',gP2T.posY);
gTexture.loadFromFile("grafika/ekrany/4.png");
Texture buttons;
buttons.loadFromFile("grafika/buttons/3/buttons.png");
SDL_Rect onethird[3];
{
    onethird[0].h=60;
    onethird[0].w=1280;
    onethird[0].x=0;
    onethird[0].y=0;

    onethird[1].h=420;
    onethird[1].w=1280;
    onethird[1].x=0;
    onethird[1].y=60;

    onethird[2].h=240;
    onethird[2].w=1280;
    onethird[2].x=0;
    onethird[2].y=480;
}
SDL_Rect move_button[5];
{
move_button[1].h=50;
move_button[1].w=50;
move_button[1].x=275;
move_button[1].y=486;

move_button[2].h=50;
move_button[2].w=50;
move_button[2].x=210;
move_button[2].y=542;

move_button[3].h=50;
move_button[3].w=50;
move_button[3].x=275;
move_button[3].y=542;

move_button[4].h=50;
move_button[4].w=50;
move_button[4].x=340;
move_button[4].y=542;

}
SDL_Rect button[2];
{
    button[0].h=12;
    button[0].w=12;
    button[0].x=0;
    button[0].y=0;

    button[1].h=90;
    button[1].w=90;
    button[1].x=12;
    button[1].y=0;
}
SDL_Rect hp_bar[4];
{
    //back bars
    hp_bar[0].h=30;
    hp_bar[0].w=160;
    hp_bar[0].x=112;
    hp_bar[0].y=33;

    hp_bar[3].h=30;
    hp_bar[3].w=160;
    hp_bar[3].x=112;
    hp_bar[3].y=33;
    //bars
    hp_bar[1].h=20;
    hp_bar[1].w=gP1T.champion_code.hp;
    hp_bar[1].x=112;
    hp_bar[1].y=0;

    hp_bar[2].h=20;
    hp_bar[2].w=gP2T.champion_code.hp;
    hp_bar[2].x=112;
    hp_bar[2].y=0;

}
SDL_Rect hightlight;
{
hightlight.h=60;
hightlight.w=255;
hightlight.x=500;
hightlight.y=0;
}
SDL_Rect descrip[5];
{
    descrip[0].h=100;
    descrip[0].w=100;
    descrip[0].x=400;
    descrip[0].y=2700;

    descrip[1].h=100;
    descrip[1].w=100;
    descrip[1].x=500;
    descrip[1].y=2700;

    descrip[2].h=100;
    descrip[2].w=100;
    descrip[2].x=600;
    descrip[2].y=2700;

    descrip[3].h=100;
    descrip[3].w=100;
    descrip[3].x=700;
    descrip[3].y=2700;

    descrip[4].h=100;
    descrip[4].w=100;
    descrip[4].x=800;
    descrip[4].y=2700;

}
int mX,mY;

 while(!quit)
        {
            //timer
            startTime = SDL_GetTicks()/200;
            T=startTime%6;

        SDL_GetMouseState(&mX,&mY);
        //obsluga eventow
        while( SDL_PollEvent( &e ) != 0 )
            {


                //Kliknieto X lub escape'a
            if( e.type == SDL_QUIT || (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_ESCAPE))
                {
                            quit = true;
                }
                else
                    {
                        //koniec tury
                        if(mX>=1162 && mX<=1252 && mY>=508 && mY<=598)
                        {
                            if(e.type == SDL_MOUSEBUTTONDOWN)
                            {if(canIEndMyTurn(Player))
                            {
                                Screen++;
                                break;
                            }}
                        }
                        //clearing
                        if(mX>=800 && mX<=875 && mY>=500 && mY<=600)
                        {if(e.type == SDL_MOUSEBUTTONDOWN)
                            {
                                removeSequence(Player,0);

                            }}
                        if(mX>=894 && mX<=969 && mY>=500 && mY<=600)
                        {if(e.type == SDL_MOUSEBUTTONDOWN)
                            {
                                removeSequence(Player,1);

                            }}
                        if(mX>=986 && mX<=1061 && mY>=500 && mY<=600)
                        {if(e.type == SDL_MOUSEBUTTONDOWN)
                            {
                                removeSequence(Player,2);
                            }}
                        //add rotation
                        if(mX>=787 && mX<=799 && mY>=602 && mY<=614)
                        if(e.type == SDL_MOUSEBUTTONDOWN)
                            turnPlayerAround(Player,0);
                        if(mX>=880 && mX<=892 && mY>=602 && mY<=614)
                        if(e.type == SDL_MOUSEBUTTONDOWN)
                            turnPlayerAround(Player,1);
                        if(mX>=974 && mX<=986 && mY>=602 && mY<=614)
                        if(e.type == SDL_MOUSEBUTTONDOWN)
                            turnPlayerAround(Player,2);

                        //movement arrows
                        if(mX>=275 && mX<=325 && mY>=486 && mY<=536)
                        if(e.type == SDL_MOUSEBUTTONDOWN)
                            {addSequenceToFirstEmptyPlace(Player,1);}
                        if(mX>=210 && mX<=260 && mY>=542 && mY<=592)
                        if(e.type == SDL_MOUSEBUTTONDOWN)
                           {addSequenceToFirstEmptyPlace(Player,2);}
                        if(mX>=275 && mX<=325 && mY>=542 && mY<=592)
                        if(e.type == SDL_MOUSEBUTTONDOWN)
                            {addSequenceToFirstEmptyPlace(Player,3);}
                        if(mX>=340 && mX<=390 && mY>=542 && mY<=592)
                        if(e.type == SDL_MOUSEBUTTONDOWN)
                            {addSequenceToFirstEmptyPlace(Player,4);}

                        //cards
                        if(mX>=76 && mX<=151 && mY>=604 && mY<=704)
                            if(e.type == SDL_MOUSEBUTTONDOWN)
                            {
                                if(!(isThere(Player,5)))
                                addSequenceToFirstEmptyPlace(Player,5);
                            }

                        if(mX>=172 && mX<=247 && mY>=604 && mY<=704)
                        if(e.type == SDL_MOUSEBUTTONDOWN)
                           {
                               if(!(isThere(Player,6)))
                               addSequenceToFirstEmptyPlace(Player,6);
                            }
                        if(mX>=264 && mX<=339 && mY>=604 && mY<=704)
                        if(e.type == SDL_MOUSEBUTTONDOWN)
                            {
                                if(!(isThere(Player,7)))
                                addSequenceToFirstEmptyPlace(Player,7);
                            }
                        if(mX>=356 && mX<=431 && mY>=604 && mY<=704)
                        if(e.type == SDL_MOUSEBUTTONDOWN)
                            {
                                if(!(isThere(Player,8)))
                                addSequenceToFirstEmptyPlace(Player,8);
                            }
                        if(mX>=448 && mX<=523 && mY>=604 && mY<=704)
                        if(e.type == SDL_MOUSEBUTTONDOWN)
                            {
                                if(!(isThere(Player,9)))
                                addSequenceToFirstEmptyPlace(Player,9);
                            }

                    }
                //Renderowanie
            }
            SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
				SDL_RenderClear( gRenderer );
				gTexture.render(0,60,&onethird[1]);

				//postacie
				if(Player==1)
				buttons.render(renderFloorLights('x',gP1T.posX),renderFloorLights('y',gP1T.posY),&hightlight);
				else
                buttons.render(renderFloorLights('x',gP2T.posX),renderFloorLights('y',gP2T.posY),&hightlight);
              				if(y1>=y2)
				{
				    gP1T.render(x1,y1,&(gP1T.champion_code.animation[animIdle][T]),0.0,0,gP1T.toLeft);
                    gP2T.render(x2,y2,&(gP2T.champion_code.animation[animIdle][T]),0.0,0,gP2T.toLeft);
				}
				else
                {
                    gP2T.render(x2,y2,&(gP2T.champion_code.animation[animIdle][T]),0.0,0,gP2T.toLeft);
                    gP1T.render(x1,y1,&(gP1T.champion_code.animation[animIdle][T]),0.0,0,gP1T.toLeft);
                }

                gTexture.render(0,0,&onethird[0]);
                //paski
                buttons.render(100,15,&hp_bar[3]);
                buttons.render(1030,15,&hp_bar[0]);
                buttons.render(105,20,&hp_bar[1]);
                buttons.render(1035,20,&hp_bar[2]);


                gTexture.render(0,480,&onethird[2]);
                if(canIEndMyTurn(Player)==true)
                    buttons.render(1162,508,&button[1]);
                    //rendering cards in hand
                    if(!(isThere(Player,5)))
                    {
                        if(Player==1)
                            gP1T.render(79,604,&(gP1T.hand[0].graphic));
                        else
                            gP2T.render(79,604,&(gP1T.hand[0].graphic));
                    }
                    if(!(isThere(Player,6)))
                    {
                        if(Player==1)
                            gP1T.render(172,604,&(gP1T.hand[1].graphic));
                        else
                            gP2T.render(172,604,&(gP1T.hand[1].graphic));
                    }
                    if(!(isThere(Player,7)))
                    {
                        if(Player==1)
                            gP1T.render(264,604,&(gP1T.hand[2].graphic));
                        else
                            gP2T.render(264,604,&(gP1T.hand[2].graphic));
                    }
                    if(!(isThere(Player,8)))
                    {
                        if(Player==1)
                            gP1T.render(356,604,&(gP1T.hand[3].graphic));
                        else
                            gP2T.render(356,604,&(gP1T.hand[3].graphic));
                    }
                    if(!(isThere(Player,9)))
                    {
                        if(Player==1)
                            gP1T.render(451,604,&(gP1T.hand[4].graphic));
                        else
                            gP2T.render(451,604,&(gP1T.hand[4].graphic));
                    }
                    if( mY>=604 && mY<=704)
                        {
                            if(mX>=76 && mX<=151)
                        {
                            if(Player==1)
                                gP1T.render(575,604,&descrip[0]);
                            else
                                gP2T.render(575,604,&descrip[0]);
                        }
                        else if(mX>=172 && mX<=247)
                        {
                            if(Player==1)
                                gP1T.render(575,604,&descrip[1]);
                            else
                                gP2T.render(575,604,&descrip[1]);
                        }
                        else if(mX>=264 && mX<=339)
                        {
                            if(Player==1)
                                gP1T.render(575,604,&descrip[2]);
                            else
                                gP2T.render(575,604,&descrip[2]);
                        }
                        else if(mX>=356 && mX<=431)
                        {
                            if(Player==1)
                                gP1T.render(575,604,&descrip[3]);
                            else
                                gP2T.render(575,604,&descrip[3]);
                        }
                            else if(mX>=448 && mX<=523)
                            {
                            if(Player==1)
                                gP1T.render(575,604,&descrip[4]);
                            else
                                gP2T.render(575,604,&descrip[4]);
                            }
                        }


                    if(isTurned(Player,0))
                        buttons.render(787,602,&button[0]);
                    if(isTurned(Player,1))
                        buttons.render(880,602,&button[0]);
                    if(isTurned(Player,2))
                        buttons.render(974,602,&button[0]);

                        if(getSequence(Player,0)<=4 && getSequence(Player,0)>0)
                    gTexture.render(812,525,&move_button[getSequence(Player,0)]);
                        else if(getSequence(Player,0)>0)
                    {
                        if(Player==1)
                            gP1T.render(800,500,&(gP1T.hand[getSequence(Player,0)-5].graphic));
                        else
                            gP2T.render(800,500,&(gP1T.hand[getSequence(Player,0)-5].graphic));
                    }

                        if(getSequence(Player,1)<=4 && getSequence(Player,1)>0)
                    gTexture.render(906,525,&move_button[getSequence(Player,1)]);
                        else if(getSequence(Player,1)>0)
                    {
                        if(Player==1)
                            gP1T.render(894,500,&(gP1T.hand[getSequence(Player,1)-5].graphic));
                        else
                            gP2T.render(894,500,&(gP1T.hand[getSequence(Player,1)-5].graphic));
                    }

                        if(getSequence(Player,2)<=4 && getSequence(Player,2)>0)
                    gTexture.render(998,525,&move_button[getSequence(Player,2)]);
                        else if(getSequence(Player,2)>0)
                    {
                        if(Player==1)
                            gP1T.render(986,500,&(gP1T.hand[getSequence(Player,2)-5].graphic));
                        else
                            gP2T.render(986,500,&(gP1T.hand[getSequence(Player,2)-5].graphic));
                    }

                    SDL_SetRenderDrawColor( gRenderer, 250, 0xFF, 0xFF, 0xFF );

                SDL_RenderPresent( gRenderer );

                if(Screen==Action_Screen || Screen==Before_Player_2_Turn)
                break;

        }

buttons.freeT();
}
void Action()
{
    combineSequences();
    int x1=posToRend('x',gP1T.posX);
    int y1=posToRend('y',gP1T.posY);
    int x2=posToRend('x',gP2T.posX);
    int y2=posToRend('y',gP2T.posY);
    int benchmark=SDL_GetTicks()/1000;
    Texture pom;
    pom.loadFromFile("grafika/buttons/1/Gratian.png");
Texture buttons;
buttons.loadFromFile("grafika/buttons/3/buttons.png");
SDL_Rect hp_bar[4];
{
    //back bars
    hp_bar[0].h=30;
    hp_bar[0].w=160;
    hp_bar[0].x=112;
    hp_bar[0].y=33;

    hp_bar[3].h=30;
    hp_bar[3].w=160;
    hp_bar[3].x=112;
    hp_bar[3].y=33;
    //bars
    hp_bar[1].h=20;
    hp_bar[1].w=gP1T.champion_code.hp;
    hp_bar[1].x=112;
    hp_bar[1].y=0;

    hp_bar[2].h=20;
    hp_bar[2].w=gP2T.champion_code.hp;
    hp_bar[2].x=112;
    hp_bar[2].y=0;

}
SDL_Rect background[2];
{
    background[0].h=60;
    background[0].w=1280;
    background[0].x=0;
    background[0].y=0;

    background[1].h=420;
    background[1].w=1280;
    background[1].x=0;
    background[1].y=60;
}
SDL_Rect button[3];
{
    button[0].h=12;
    button[0].w=12;
    button[0].x=0;
    button[0].y=0;

    button[1].h=90;
    button[1].w=90;
    button[1].x=12;
    button[1].y=0;

    button[2].h=240;
    button[2].w=1280;
    button[2].x=0;
    button[2].y=90;
}
SDL_Rect move_button[5];
{
move_button[0].h=12;
move_button[0].w=12;
move_button[0].x=0;
move_button[0].y=0;

move_button[1].h=50;
move_button[1].w=50;
move_button[1].x=275;
move_button[1].y=486;

move_button[2].h=50;
move_button[2].w=50;
move_button[2].x=210;
move_button[2].y=542;

move_button[3].h=50;
move_button[3].w=50;
move_button[3].x=275;
move_button[3].y=542;

move_button[4].h=50;
move_button[4].w=50;
move_button[4].x=340;
move_button[4].y=542;

}
SDL_Rect highlight;
highlight.h=60;
highlight.w=255;
highlight.x=800;
highlight.y=0;
    int mX,mY;
    int p1stat=0,p2stat=0;
    int k,l,m=0,n=0,o=0,p=0,r=0;
    /*
    *k-time passed from entering action screen in sec
    *l-variable of sequence code
    *m-placement control
    *n-flip control
    *o-animation control p1
    *p-animation control p2
    *r-waiting
    */
    int tick=0;
    int T1=1,T2=1;
     while(!quit)
        {
            hp_bar[1].w=gP1T.champion_code.hp;
            hp_bar[2].w=gP2T.champion_code.hp;
            //timer
            startTime = SDL_GetTicks()/200;
            k=SDL_GetTicks()/1000-benchmark;
            T=startTime%6;
            if(o!=0)
                T1=SDL_GetTicks()/200%6;
            if(p!=0)
                T2=SDL_GetTicks()/200%6;

        SDL_GetMouseState(&mX,&mY);
        //obsluga eventow
        while( SDL_PollEvent( &e ) != 0 )
            {
                //Kliknieto X lub escape'a
            if( e.type == SDL_QUIT || (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_ESCAPE))
                {
                            quit = true;
                }

            }

                SDL_SetRenderDrawColor( gRenderer, 255, 0xFF, 0xFF, 0xFF );
				SDL_RenderClear( gRenderer );
                gTexture.render(0,0,&background[0]);


                gTexture.render(0,60,&background[1]);
                if(k<6)
                {
                    if(y1>=y2)
				{
				    gP1T.render(x1,y1,&(gP1T.champion_code.animation[animIdle][T]),0.0,0,gP1T.toLeft);
                    gP2T.render(x2,y2,&(gP2T.champion_code.animation[animIdle][T]),0.0,0,gP2T.toLeft);
				}
				else
                {
                    gP2T.render(x2,y2,&(gP2T.champion_code.animation[animIdle][T]),0.0,0,gP2T.toLeft);
                    gP1T.render(x1,y1,&(gP1T.champion_code.animation[animIdle][T]),0.0,0,gP1T.toLeft);
                }
                }
                else if((tick==0||tick==4||tick==8) && r==0)
                {
                    if(getAction(tick)==1)
                        {if(gP1T.toLeft==SDL_FLIP_HORIZONTAL)
                            gP1T.toLeft=SDL_FLIP_NONE;
                            else
                            {gP1T.toLeft=SDL_FLIP_HORIZONTAL;}
                        }
                    if(getAction(tick+1)==1)
                        {if(gP2T.toLeft==SDL_FLIP_HORIZONTAL)
                            gP2T.toLeft=SDL_FLIP_NONE;
                            else
                            {gP2T.toLeft=SDL_FLIP_HORIZONTAL;}
                        }
                    if(y1>=y2)
				{
				    gP1T.render(x1,y1,&(gP1T.champion_code.animation[animIdle][T]),0.0,0,gP1T.toLeft);
                    gP2T.render(x2,y2,&(gP2T.champion_code.animation[animIdle][T]),0.0,0,gP2T.toLeft);
				}
				else
                {
                    gP2T.render(x2,y2,&(gP2T.champion_code.animation[animIdle][T]),0.0,0,gP2T.toLeft);
                    gP1T.render(x1,y1,&(gP1T.champion_code.animation[animIdle][T]),0.0,0,gP1T.toLeft);
                }
                tick+=2;
                r=SDL_GetTicks()/1000-benchmark;
                }
                else if((tick==2|| tick==6 || tick==10 ||tick==3|| tick==7 || tick==11) &&r==0)
                {
                    if(getAction(tick)/10==1 && (tick==2|| tick==6 || tick==10))
                    {
                        if(getAction(tick)%10<=4)
                            l=1;
                        else
                            l=getAction(tick)%10;
                       if(l==1)
                        {
                            if(isPossible(gP1T.posX,gP1T.posY,getAction(tick)%10)==true)
                            {
                                if(getAction(tick)%10==1 || getAction(tick)%10==3)
                                {
                                                    if(y1+m>=y2)
                                {
                                    gP1T.render(x1,y1+m,&(gP1T.champion_code.animation[animWalk][T]),0.0,0,gP1T.toLeft);
                                    gP2T.render(x2,y2,&(gP2T.champion_code.animation[animIdle][T]),0.0,0,gP2T.toLeft);
                                }
                                else
                                {
                                    gP2T.render(x2,y2,&(gP2T.champion_code.animation[animIdle][T]),0.0,0,gP2T.toLeft);
                                    gP1T.render(x1,y1+m,&(gP1T.champion_code.animation[animWalk][T]),0.0,0,gP1T.toLeft);
                                }
                                    if(getAction(tick)%10==1)
                                    m--;
                                    else
                                    m++;
                                    if(m==-60 || m==60)
                                    {
                                        m=0;
                                    if(getAction(tick)%10==1)
                                        gP1T.posY--;
                                        else
                                            gP1T.posY++;
                                        y1=posToRend('y',gP1T.posY);
                                        removeSequence(1,(tick+1)%3);
                                        n=0;
                                        tick++;

                                    }
                                }
                                else if(getAction(tick)%10==2 || getAction(tick)%10==4)
                                {
                                                    if(y1>=y2)
                                {
                                    gP1T.render(x1+m,y1,&(gP1T.champion_code.animation[animWalk][T]),0.0,0,gP1T.toLeft);
                                    gP2T.render(x2,y2,&(gP2T.champion_code.animation[animIdle][T]),0.0,0,gP2T.toLeft);
                                }
                                else
                                {
                                    gP2T.render(x2,y2,&(gP2T.champion_code.animation[animIdle][T]),0.0,0,gP2T.toLeft);
                                    gP1T.render(x1+m,y1,&(gP1T.champion_code.animation[animWalk][T]),0.0,0,gP1T.toLeft);
                                }
                                    if(getAction(tick)%10==2)
                                     m--;
                                     else
                                        m++;
                                     if((gP1T.toLeft==SDL_FLIP_HORIZONTAL && getAction(tick)%10==2) ||(gP1T.toLeft==SDL_FLIP_NONE && getAction(tick)%10==4) || n==1){}
                                     else
                                        {
                                            if(n!=1)
                                            {
                                            if(getAction(tick)%10==2)
                                            gP1T.toLeft=SDL_FLIP_HORIZONTAL;
                                            else
                                            gP1T.toLeft=SDL_FLIP_NONE;
                                            }
                                            n=1;
                                        }
                                     if(m==-250 || m==250)
                                     {
                                         if(getAction(tick)%10==2)
                                         gP1T.posX--;
                                         else
                                         gP1T.posX++;
                                         x1=posToRend('x',gP1T.posX);
                                         m=0;
                                         if(n==1)
                                         {
                                              if(gP1T.toLeft==SDL_FLIP_NONE)
                                             gP1T.toLeft=SDL_FLIP_HORIZONTAL;
                                             else
                                                gP1T.toLeft=SDL_FLIP_NONE;
                                            n=0;

                                         }
                                        removeSequence(1,(tick+1)%3);
                                        tick++;
                                        }
                                }
                            }
                            else
                                {
                    if(y1>=y2)
				{
				    gP1T.render(x1,y1,&(gP1T.champion_code.animation[animIdle][T]),0.0,0,gP1T.toLeft);
                    gP2T.render(x2,y2,&(gP2T.champion_code.animation[animIdle][T]),0.0,0,gP2T.toLeft);
				}
				else
                {
                    gP2T.render(x2,y2,&(gP2T.champion_code.animation[animIdle][T]),0.0,0,gP2T.toLeft);
                    gP1T.render(x1,y1,&(gP1T.champion_code.animation[animIdle][T]),0.0,0,gP1T.toLeft);
                }
                                    removeSequence(1,(tick+1)%3);
                                    tick++;
                                }
                        }
                        else //nie chodzenie
                        {
                            if(gP1T.hand[l-5].type=="A"||gP1T.hand[l-5].type=="*A"||gP1T.hand[l-5].type=="IA")
                            {
                                p1stat=l-3;
                                o=600;
                                for(int i=0;i<15;i++)
                                {
                                    if(gP1T.hand[l-5].where[i].cX==0 && gP1T.hand[l-5].where[i].cY==0)
                                        break;
                                    else
                                    {
                                        if(((gP1T.posX+gP1T.hand[l-5].where[i].cX==gP2T.posX && gP1T.toLeft==SDL_FLIP_NONE)||
                                            (gP1T.posX-gP1T.hand[l-5].where[i].cX==gP2T.posX && gP1T.toLeft==SDL_FLIP_HORIZONTAL))
                                            && gP1T.posY-gP1T.hand[l-5].where[i].cY==gP2T.posY)
                                        {
                                            gP2T.champion_code.reduction-=gP1T.hand[l-5].value;
                                            if(gP2T.champion_code.reduction<0)
                                            {
                                                gP2T.champion_code.hp+=gP2T.champion_code.reduction;
                                                gP2T.champion_code.reduction=0;

                                            }
                                            else
                                                gP2T.champion_code.reduction=0;


                                        }
                                    }
                                }
                                removeSequence(1,(tick+1)%3);
                                tick++;
                                r=SDL_GetTicks()/1000-benchmark+1;

                            }
                            else if(gP1T.hand[l-5].type=="O"||gP1T.hand[l-5].type=="*O"||gP1T.hand[l-5].type=="IO")
                            {
                                p1stat=l-3;
                                o=600;
                                playOtherCard(&gP1T,l-5);
                                removeSequence(1,(tick+1)%3);
                                tick++;
                                r=SDL_GetTicks()/1000-benchmark+1;

                            }
                            else
                            {
                                removeSequence(1,(tick+1)%3);
                                tick++;
                                r=SDL_GetTicks()/1000-benchmark+1;
                            }
                        }
                    }//nie gracz pierwszy
                    else if(getAction(tick)/10==2 && (tick==2|| tick==6 || tick==10))
                    {
                        if(getAction(tick)%10<=4)
                            l=1;
                        else
                            l=getAction(tick)%10;
                       if(l==1)
                        {
                            if(isPossible(gP2T.posX,gP2T.posY,getAction(tick)%10)==true)
                            {
                                if(getAction(tick)%10==1 || getAction(tick)%10==3)
                                {
                                                    if(y1>=y2+m)
                                {
                                    gP1T.render(x1,y1,&(gP1T.champion_code.animation[animIdle][T]),0.0,0,gP1T.toLeft);
                                    gP2T.render(x2,y2+m,&(gP2T.champion_code.animation[animWalk][T]),0.0,0,gP2T.toLeft);
                                }
                                else
                                {
                                    gP2T.render(x2,y2+m,&(gP2T.champion_code.animation[animWalk][T]),0.0,0,gP2T.toLeft);
                                    gP1T.render(x1,y1,&(gP1T.champion_code.animation[animIdle][T]),0.0,0,gP1T.toLeft);
                                }
                                    if(getAction(tick)%10==1)
                                    m--;
                                    else
                                    m++;
                                    if(m==-60 || m==60)
                                    {
                                        m=0;
                                    if(getAction(tick)%10==1)
                                        gP2T.posY--;
                                        else
                                            gP2T.posY++;
                                        y2=posToRend('y',gP2T.posY);
                                        removeSequence(2,(tick+1)%3);
                                        tick++;
                                    }
                                }
                                else if(getAction(tick)%10==2 || getAction(tick)%10==4)
                                {
                                                    if(y1>=y2)
                                {
                                    gP1T.render(x1,y1,&(gP1T.champion_code.animation[animIdle][T]),0.0,0,gP1T.toLeft);
                                    gP2T.render(x2+m,y2,&(gP2T.champion_code.animation[animWalk][T]),0.0,0,gP2T.toLeft);
                                }
                                else
                                {
                                    gP2T.render(x2+m,y2,&(gP2T.champion_code.animation[animWalk][T]),0.0,0,gP2T.toLeft);
                                    gP1T.render(x1,y1,&(gP1T.champion_code.animation[animIdle][T]),0.0,0,gP1T.toLeft);
                                }
                                    if(getAction(tick)%10==2)
                                     m--;
                                     else
                                        m++;
                                     if((gP2T.toLeft==SDL_FLIP_HORIZONTAL && getAction(tick)%10==2) ||(gP2T.toLeft==SDL_FLIP_NONE && getAction(tick)%10==4) || n==1){}
                                     else
                                        {
                                            if(n!=1)
                                            {
                                                if(getAction(tick)%10==2)
                                            gP2T.toLeft=SDL_FLIP_HORIZONTAL;
                                            else
                                            gP2T.toLeft=SDL_FLIP_NONE;
                                            }
                                            n=1;
                                        }
                                     if(m==-250 || m==250)
                                     {
                                         if(getAction(tick)%10==2)
                                         gP2T.posX--;
                                         else
                                         gP2T.posX++;
                                         x2=posToRend('x',gP2T.posX);
                                         m=0;
                                         if(n==1)
                                         {
                                              if(gP2T.toLeft==SDL_FLIP_NONE)
                                             gP2T.toLeft=SDL_FLIP_HORIZONTAL;
                                             else
                                                gP2T.toLeft=SDL_FLIP_NONE;
                                            n=0;
                                         }
                                        removeSequence(2,(tick+1)%3);
                                        tick++;
                                        }
                                }
                            }
                            else
                                {
                    if(y1>=y2)
				{
				    gP1T.render(x1,y1,&(gP1T.champion_code.animation[animIdle][T]),0.0,0,gP1T.toLeft);
                    gP2T.render(x2,y2,&(gP2T.champion_code.animation[animIdle][T]),0.0,0,gP2T.toLeft);
				}
				else
                {
                    gP2T.render(x2,y2,&(gP2T.champion_code.animation[animIdle][T]),0.0,0,gP2T.toLeft);
                    gP1T.render(x1,y1,&(gP1T.champion_code.animation[animIdle][T]),0.0,0,gP1T.toLeft);
                }
                                removeSequence(2,(tick+1)%3);
                                    tick++;
                                }
                        }
                        else//nie chodzenie
                        {
                                if(gP2T.hand[l-5].type=="A"||gP2T.hand[l-5].type=="*A"||gP2T.hand[l-5].type=="IA")
                            {
                                p2stat=l-3;
                                p=600;
                                for(int i=0;i<15;i++)
                                {
                                    if(gP2T.hand[l-5].where[i].cX==0 && gP2T.hand[l-5].where[i].cY==0)
                                        break;
                                    else
                                    {

                                        if(((gP2T.posX+gP2T.hand[l-5].where[i].cX==gP1T.posX && gP2T.toLeft==SDL_FLIP_NONE)
                                            ||(gP2T.posX-gP2T.hand[l-5].where[i].cX==gP1T.posX && gP2T.toLeft==SDL_FLIP_HORIZONTAL))
                                            && gP2T.posY-gP2T.hand[l-5].where[i].cY==gP1T.posY)
                                        {

                                            gP1T.champion_code.reduction-=gP2T.hand[l-5].value;
                                            if(gP1T.champion_code.reduction<0)
                                            {
                                                gP1T.champion_code.hp+=gP1T.champion_code.reduction;
                                                gP1T.champion_code.reduction=0;

                                            }
                                            else
                                                gP1T.champion_code.reduction=0;

                                        }
                                    }
                                }
                                removeSequence(2,(tick+1)%3);
                                tick++;
                                r=SDL_GetTicks()/1000-benchmark+1;
                            }
                            else if(gP2T.hand[l-5].type=="O"||gP2T.hand[l-5].type=="*O"||gP2T.hand[l-5].type=="IO")
                            {
                                p2stat=l-3;
                                p=600;
                                playOtherCard(&gP2T,l-5);
                                removeSequence(2,(tick+1)%3);
                                tick++;
                                r=SDL_GetTicks()/1000-benchmark+1;
                            }
                            else
                            {
                                removeSequence(2,(tick+1)%3);
                                tick++;
                            r=SDL_GetTicks()/1000-benchmark+1;}
                        }
                    }
                    else if(getAction(tick)/10==1 && (tick==3|| tick==7 || tick==11))
                    {
                        if(getAction(tick)%10<=4)
                            l=1;
                        else
                            l=getAction(tick)%10;
                       if(l==1)
                        {
                            if(isPossible(gP1T.posX,gP1T.posY,getAction(tick)%10)==true)
                            {
                                if(getAction(tick)%10==1 || getAction(tick)%10==3)
                                {
                                                    if(y1+m>=y2)
                                {
                                    gP1T.render(x1,y1+m,&(gP1T.champion_code.animation[animWalk][T]),0.0,0,gP1T.toLeft);
                                    gP2T.render(x2,y2,&(gP2T.champion_code.animation[animIdle][T]),0.0,0,gP2T.toLeft);
                                }
                                else
                                {
                                    gP2T.render(x2,y2,&(gP2T.champion_code.animation[animIdle][T]),0.0,0,gP2T.toLeft);
                                    gP1T.render(x1,y1+m,&(gP1T.champion_code.animation[animWalk][T]),0.0,0,gP1T.toLeft);
                                }
                                    if(getAction(tick)%10==1)
                                    m--;
                                    else
                                    m++;
                                    if(m==-60 || m==60)
                                    {
                                        m=0;
                                    if(getAction(tick)%10==1)
                                        gP1T.posY--;
                                        else
                                            gP1T.posY++;
                                        y1=posToRend('y',gP1T.posY);
                                        removeSequence(1,tick%3);
                                        tick++;
                                    }
                                }
                                else if(getAction(tick)%10==2 || getAction(tick)%10==4)
                                {
                                                    if(y1>=y2)
                                {
                                    gP1T.render(x1+m,y1,&(gP1T.champion_code.animation[animWalk][T]),0.0,0,gP1T.toLeft);
                                    gP2T.render(x2,y2,&(gP2T.champion_code.animation[animIdle][T]),0.0,0,gP2T.toLeft);
                                }
                                else
                                {
                                    gP2T.render(x2,y2,&(gP2T.champion_code.animation[animIdle][T]),0.0,0,gP2T.toLeft);
                                    gP1T.render(x1+m,y1,&(gP1T.champion_code.animation[animWalk][T]),0.0,0,gP1T.toLeft);
                                }
                                    if(getAction(tick)%10==2)
                                     m--;
                                     else
                                        m++;
                                     if((gP1T.toLeft==SDL_FLIP_HORIZONTAL && getAction(tick)%10==2) ||(gP1T.toLeft==SDL_FLIP_NONE && getAction(tick)%10==4) || n==1){}
                                     else
                                        {
                                            if(n!=1)
                                            {
                                            if(getAction(tick)%10==2)
                                            gP1T.toLeft=SDL_FLIP_HORIZONTAL;
                                            else
                                            gP1T.toLeft=SDL_FLIP_NONE;
                                            }
                                            n=1;
                                        }
                                     if(m==-250 || m==250)
                                     {
                                         if(getAction(tick)%10==2)
                                         gP1T.posX--;
                                         else
                                         gP1T.posX++;
                                         x1=posToRend('x',gP1T.posX);
                                         m=0;
                                         if(n==1)
                                         {
                                              if(gP1T.toLeft==SDL_FLIP_NONE)
                                             gP1T.toLeft=SDL_FLIP_HORIZONTAL;
                                             else
                                                gP1T.toLeft=SDL_FLIP_NONE;
                                            n=0;

                                         }
                                        removeSequence(1,tick%3);
                                        tick++;
                                        }
                                }
                            }
                            else
                                {
                    if(y1>=y2)
				{
				    gP1T.render(x1,y1,&(gP1T.champion_code.animation[animIdle][T]),0.0,0,gP1T.toLeft);
                    gP2T.render(x2,y2,&(gP2T.champion_code.animation[animIdle][T]),0.0,0,gP2T.toLeft);
				}
				else
                {
                    gP2T.render(x2,y2,&(gP2T.champion_code.animation[animIdle][T]),0.0,0,gP2T.toLeft);
                    gP1T.render(x1,y1,&(gP1T.champion_code.animation[animIdle][T]),0.0,0,gP1T.toLeft);
                }
                removeSequence(1,tick%3);
                tick++;
                }
                        }
                        else //nie chodzenie
                        {
                                if(gP1T.hand[l-5].type=="A"||gP1T.hand[l-5].type=="*A"||gP1T.hand[l-5].type=="IA")
                            {
                                p1stat=l-3;
                                o=600;
                                for(int i=0;i<15;i++)
                                {
                                    if(gP1T.hand[l-5].where[i].cX==0 && gP1T.hand[l-5].where[i].cY==0)
                                        break;
                                    else
                                    {

                                        if(((gP1T.posX+gP1T.hand[l-5].where[i].cX==gP2T.posX && gP1T.toLeft==SDL_FLIP_NONE)||(gP1T.posX+gP1T.hand[l-5].where[i].cX==gP2T.posX && gP1T.toLeft==SDL_FLIP_HORIZONTAL))
                                            && gP1T.posY-gP1T.hand[l-5].where[i].cY==gP2T.posY)
                                        {
                                            gP2T.champion_code.reduction-=gP1T.hand[l-5].value;
                                            if(gP2T.champion_code.reduction<0)
                                            {
                                                gP2T.champion_code.hp+=gP2T.champion_code.reduction;
                                                gP2T.champion_code.reduction=0;

                                            }
                                            else
                                                gP2T.champion_code.reduction=0;

                                        }
                                    }
                                }
                                removeSequence(1,tick%3);
                                tick++;
                                r=SDL_GetTicks()/1000-benchmark+1;
                            }
                            else if(gP1T.hand[l-5].type=="O"||gP1T.hand[l-5].type=="*O"||gP1T.hand[l-5].type=="IO")
                            {
                                p1stat=l-3;
                                o=600;
                                playOtherCard(&gP1T,l-5);
                                removeSequence(1,tick%3);
                                tick++;
                                r=SDL_GetTicks()/1000-benchmark+1;
                            }
                            else
                            {
                                removeSequence(1,tick%3);
                                tick++;
                                r=SDL_GetTicks()/1000-benchmark+1;
                            }
                        }
                    }
                    else if(getAction(tick)/10==2 && (tick==3|| tick==7 || tick==11))
                    {

                        if(getAction(tick)%10<=4)
                            l=1;
                        else
                            l=getAction(tick)%10;
                       if(l==1)
                        {
                            if(isPossible(gP2T.posX,gP2T.posY,getAction(tick)%10)==true)
                            {
                                if(getAction(tick)%10==1 || getAction(tick)%10==3)
                                {
                                                    if(y1>=y2+m)
                                {
                                    gP1T.render(x1,y1,&(gP1T.champion_code.animation[animIdle][T]),0.0,0,gP1T.toLeft);
                                    gP2T.render(x2,y2+m,&(gP2T.champion_code.animation[animWalk][T]),0.0,0,gP2T.toLeft);
                                }
                                else
                                {
                                    gP2T.render(x2,y2+m,&(gP2T.champion_code.animation[animWalk][T]),0.0,0,gP2T.toLeft);
                                    gP1T.render(x1,y1,&(gP1T.champion_code.animation[animIdle][T]),0.0,0,gP1T.toLeft);
                                }
                                    if(getAction(tick)%10==1)
                                    m--;
                                    else
                                    m++;
                                    if(m==-60 || m==60)
                                    {
                                        m=0;
                                    if(getAction(tick)%10==1)
                                        gP2T.posY--;
                                        else
                                            gP2T.posY++;
                                        y2=posToRend('y',gP2T.posY);
                                        removeSequence(2,tick%3);
                                        tick++;
                                    }
                                }
                                else if(getAction(tick)%10==2 || getAction(tick)%10==4)
                                {
                                                    if(y1>=y2)
                                {
                                    gP1T.render(x1,y1,&(gP1T.champion_code.animation[animIdle][T]),0.0,0,gP1T.toLeft);
                                    gP2T.render(x2+m,y2,&(gP2T.champion_code.animation[animWalk][T]),0.0,0,gP2T.toLeft);
                                }
                                else
                                {
                                    gP2T.render(x2+m,y2,&(gP2T.champion_code.animation[animWalk][T]),0.0,0,gP2T.toLeft);
                                    gP1T.render(x1,y1,&(gP1T.champion_code.animation[animIdle][T]),0.0,0,gP1T.toLeft);
                                }
                                    if(getAction(tick)%10==2)
                                     m--;
                                     else
                                        m++;
                                     if((gP2T.toLeft==SDL_FLIP_HORIZONTAL && getAction(tick)%10==2) ||(gP2T.toLeft==SDL_FLIP_NONE && getAction(tick)%10==4) || n==1){}
                                     else
                                        {
                                            if(n!=1)
                                            {
                                                if(getAction(tick)%10==2)
                                            gP2T.toLeft=SDL_FLIP_HORIZONTAL;
                                            else
                                            gP2T.toLeft=SDL_FLIP_NONE;
                                            }
                                            n=1;
                                        }
                                     if(m==-250 || m==250)
                                     {
                                         if(getAction(tick)%10==2)
                                         gP2T.posX--;
                                         else
                                         gP2T.posX++;
                                         x2=posToRend('x',gP2T.posX);
                                         m=0;
                                         if(n==1)
                                         {
                                              if(gP2T.toLeft==SDL_FLIP_NONE)
                                             gP2T.toLeft=SDL_FLIP_HORIZONTAL;
                                             else
                                                gP2T.toLeft=SDL_FLIP_NONE;
                                            n=0;
                                         }
                                        removeSequence(2,tick%3);
                                        tick++;
                                        }
                                }
                            }
                            else
                                {
                                if(y1>=y2)
                                {
                                    gP1T.render(x1,y1,&(gP1T.champion_code.animation[animIdle][T]),0.0,0,gP1T.toLeft);
                                    gP2T.render(x2,y2,&(gP2T.champion_code.animation[animIdle][T]),0.0,0,gP2T.toLeft);
                                }
                                else
                                {
                                    gP2T.render(x2,y2,&(gP2T.champion_code.animation[animIdle][T]),0.0,0,gP2T.toLeft);
                                    gP1T.render(x1,y1,&(gP1T.champion_code.animation[animIdle][T]),0.0,0,gP1T.toLeft);
                                }
                                removeSequence(2,tick%3);
                                tick++;
                                }
                        }
                        else//nie ruch
                        {
                            if(gP2T.hand[l-5].type=="A"||gP2T.hand[l-5].type=="*A"||gP2T.hand[l-5].type=="IA")
                            {
                                p2stat=l-3;
                                p=600;
                                for(int i=0;i<15;i++)
                                {
                                    if(gP2T.hand[l-5].where[i].cX==0 && gP2T.hand[l-5].where[i].cY==0)
                                        break;
                                    else
                                    {
                                        if(((gP2T.posX+gP2T.hand[l-5].where[i].cX==gP1T.posX && gP2T.toLeft==SDL_FLIP_NONE)||
                                            (gP2T.posX-gP2T.hand[l-5].where[i].cX==gP1T.posX && gP2T.toLeft==SDL_FLIP_HORIZONTAL))
                                            && gP2T.posY-gP2T.hand[l-5].where[i].cY==gP1T.posY)
                                        {
                                            gP1T.champion_code.reduction-=gP2T.hand[l-5].value;
                                            if(gP1T.champion_code.reduction<0)
                                            {
                                                gP1T.champion_code.hp+=gP1T.champion_code.reduction;
                                                gP1T.champion_code.reduction=0;

                                            }
                                            else
                                                gP1T.champion_code.reduction=0;

                                        }
                                    }
                                }
                                removeSequence(2,tick%3);
                                tick++;
                                r=SDL_GetTicks()/1000-benchmark+1;
                            }
                            else if(gP2T.hand[l-5].type=="O"||gP2T.hand[l-5].type=="*O"||gP2T.hand[l-5].type=="IO")
                            {
                                p2stat=l-3;
                                p=600;
                                playOtherCard(&gP2T,l-5);
                                removeSequence(2,tick%3);
                                tick++;
                                r=SDL_GetTicks()/1000-benchmark+1;
                            }
                            else
                            {
                                removeSequence(2,tick%3);
                                tick++;
                                r=SDL_GetTicks()/1000-benchmark+1;
                            }                        }
                    }
                }
                else
                {
                    if(r>0)
                        {
                            if(tick==3 || tick==4 || tick==7 || tick==8 || tick==10 || tick== 11)
                            {
                                if((getAction(tick-1)/10==1)
                                &&(getAction(tick-1)%10>4))
                                    {
                                        if(gP1T.hand[getAction(tick-1)%10-5].type=="A"
                                           || gP1T.hand[getAction(tick-1)%10-5].type=="*A"
                                           || gP1T.hand[getAction(tick-1)%10-5].type=="IA")
                                        for(int i=0;i<15;i++)
                                        {
                                            if(gP1T.hand[getAction(tick-1)%10-5].where[i].cY==0 && gP1T.hand[getAction(tick-1)%10-5].where[i].cX==0)
                                                break;
                                            else
                                            if(gP1T.toLeft==SDL_FLIP_NONE)
                                            buttons.render(renderFloorLights('x',gP1T.posX+gP1T.hand[getAction(tick-1)%10-5].where[i].cX),
                                                        renderFloorLights('y',gP1T.posY+gP1T.hand[getAction(tick-1)%10-5].where[i].cY),&highlight);
                                            else
                                            buttons.render(renderFloorLights('x',gP1T.posX-gP1T.hand[getAction(tick-1)%10-5].where[i].cX),
                                                    renderFloorLights('y',gP1T.posY+gP1T.hand[getAction(tick-1)%10-5].where[i].cY),&highlight);
                                        }
                                    }
                                    else if((getAction(tick-1)/10==2)
                                &&(getAction(tick-1)%10>4))
                                {
                                        if(gP2T.hand[getAction(tick-1)%10-5].type=="A"
                                           || gP2T.hand[getAction(tick-1)%10-5].type=="*A"
                                           || gP2T.hand[getAction(tick-1)%10-5].type=="IA")
                                        for(int i=0;i<15;i++)
                                        {
                                            if(gP2T.hand[getAction(tick-1)%10-5].where[i].cY==0 && gP2T.hand[getAction(tick-1)%10-5].where[i].cX==0)
                                                break;
                                            else
                                            if(gP2T.toLeft==SDL_FLIP_NONE)
                                            buttons.render(renderFloorLights('x',gP2T.posX+gP2T.hand[getAction(tick-1)%10-5].where[i].cX),
                                                        renderFloorLights('y',gP2T.posY+gP2T.hand[getAction(tick-1)%10-5].where[i].cY),&highlight);
                                            else
                                            buttons.render(renderFloorLights('x',gP2T.posX-gP2T.hand[getAction(tick-1)%10-5].where[i].cX),
                                                        renderFloorLights('y',gP2T.posY+gP2T.hand[getAction(tick-1)%10-5].where[i].cY),&highlight);
                                        }
                                }
                            }

                        //if(W!=0)
                            //r=k-2;
                        if(r+2==k)
                        r=0;
                        else if(r-2==k && W!=0)
                            r++;
                        else if(r-3==k && W!=0)
                            r=0;
                        }
                if(gP1T.champion_code.hp<=0)
                    {
                        p1stat=animDead;
                        W=2;
                    }
                if(gP2T.champion_code.hp<=0)
                    {
                        p2stat=animDead;
                        W=1;
                    }
                if(o>0)
                    {
                        o--;
                    }
                else
                {
                    if(p1stat!=animDead)
                        p1stat=animIdle;
                        else
                            tick=12;
                    T1=T;
                }
                if(p>0)
                {
                    p--;
                }
                else
                {
                    if(p2stat!=animDead)
                    p2stat=animIdle;
                    else
                        tick=12;

                    T2=T;
                }
                    if(y1>=y2)
				{
				    gP1T.render(x1,y1,&(gP1T.champion_code.animation[p1stat][T1]),0.0,0,gP1T.toLeft);
                    gP2T.render(x2,y2,&(gP2T.champion_code.animation[p2stat][T2]),0.0,0,gP2T.toLeft);
				}
				else
                {
                    gP2T.render(x2,y2,&(gP2T.champion_code.animation[p2stat][T2]),0.0,0,gP2T.toLeft);
                    gP1T.render(x1,y1,&(gP1T.champion_code.animation[p1stat][T1]),0.0,0,gP1T.toLeft);
                }
                }
                //bars
                buttons.render(100,15,&hp_bar[3]);
                buttons.render(1030,15,&hp_bar[0]);
                buttons.render(105,20,&hp_bar[1]);
                buttons.render(1035,20,&hp_bar[2]);
                buttons.render(0,480,&button[2]);

                if(getSequence(1,0)>0)
                pom.render(158,501,NULL);
                else if(getAction(2)/10==1)
                {
                    if(getAction(2)%10>4)
                        gP1T.render(158,501,&gP1T.hand[getAction(2)%10-5].graphic);
                    else
                        gTexture.render(170,526,&move_button[getAction(2)%10]);
                }
                else if(getAction(3)/10==1)
                {
                    if(getAction(3)%10>4)
                        gP1T.render(158,501,&gP1T.hand[getAction(3)%10-5].graphic);
                    else
                        gTexture.render(170,526,&move_button[getAction(3)%10]);
                }


                if(getSequence(1,1)>0)
                pom.render(251,501,NULL);
                else if(getAction(6)/10==1)
                {
                    if(getAction(6)%10>4)
                        gP1T.render(251,501,&gP1T.hand[getAction(6)%10-5].graphic);
                    else
                        gTexture.render(263,526,&move_button[getAction(6)%10]);
                }
                else if(getAction(7)/10==1)
                {
                    if(getAction(7)%10>4)
                        gP1T.render(251,501,&gP1T.hand[getAction(7)%10-5].graphic);
                    else
                        gTexture.render(263,526,&move_button[getAction(7)%10]);
                }
                if(getSequence(1,2)>0)
                pom.render(344,501,NULL);
                else if(getAction(10)/10==1)
                {
                    if(getAction(10)%10>4)
                        gP1T.render(344,501,&gP1T.hand[getAction(10)%10-5].graphic);
                    else
                        gTexture.render(356,526,&move_button[getAction(10)%10]);
                }
                else if(getAction(11)/10==1)
                {
                    if(getAction(11)%10>4)
                        gP1T.render(344,501,&gP1T.hand[getAction(11)%10-5].graphic);
                    else
                        gTexture.render(356,526,&move_button[getAction(11)%10]);
                }


                if(getSequence(2,0)>0)
                pom.render(860,501,NULL);
                else if(getAction(2)/10==2)
                {
                    if(getAction(2)%10>4)
                        gP2T.render(860,501,&gP2T.hand[getAction(2)%10-5].graphic);
                    else
                        gTexture.render(872,526,&move_button[getAction(2)%10]);
                }
                else if(getAction(3)/10==2)
                {
                    if(getAction(3)%10>4)
                        gP2T.render(860,501,&gP2T.hand[getAction(3)%10-5].graphic);
                    else
                        gTexture.render(872,526,&move_button[getAction(3)%10]);
                }
                if(getSequence(1,1)>0)
                pom.render(953,501,NULL);
                else if(getAction(6)/10==2)
                {
                    if(getAction(6)%10>4)
                        gP2T.render(953,501,&gP2T.hand[getAction(6)%10-5].graphic);
                    else
                        gTexture.render(965,526,&move_button[getAction(6)%10]);
                }
                else if(getAction(7)/10==2)
                {
                    if(getAction(7)%10>4)
                        gP2T.render(953,501,&gP2T.hand[getAction(7)%10-5].graphic);
                    else
                        gTexture.render(965,526,&move_button[getAction(7)%10]);
                }
                if(getSequence(1,2)>0)
                pom.render(1046,501,NULL);
                else if(getAction(10)/10==2)
                {
                    if(getAction(10)%10>4)
                        gP2T.render(1046,501,&gP2T.hand[getAction(10)%10-5].graphic);
                    else
                        gTexture.render(1058,526,&move_button[getAction(10)%10]);
                }
                else if(getAction(11)/10==2)
                {
                    if(getAction(11)%10>4)
                        gP2T.render(1046,501,&gP2T.hand[getAction(11)%10-5].graphic);
                    else
                        gTexture.render(1058,526,&move_button[getAction(11)%10]);
                }
                if(getAction(0)==1)
                    buttons.render(145,604,&move_button[0]);
                if(getAction(4)==1)
                    buttons.render(238,604,&move_button[0]);
                if(getAction(8)==1)
                    buttons.render(331,604,&move_button[0]);

                if(getAction(1)==1)
                    buttons.render(847,604,&move_button[0]);
                if(getAction(5)==1)
                    buttons.render(940,604,&move_button[0]);
                if(getAction(9)==1)
                    buttons.render(1033,604,&move_button[0]);

				SDL_RenderPresent( gRenderer );
				if(tick==12)
                    {
                        tick=-1;
                    }
                    else if(tick==-1)
                        break;

                if(W!=0 && r==0)
                {
                    break;
                }
        }
        if(W!=0)
        {
            Screen=Ending_Screen;

        }
        else
            Screen=Before_Player_1_Turn;


        buttons.freeT();
        pom.freeT();

}
void Result(int player)
{
    if(player==1)
        gTexture.loadFromFile("grafika/ekrany/w1.png");
    else
        gTexture.loadFromFile("grafika/ekrany/w2.png");
    int benchmark=SDL_GetTicks()/1000;
    int k;
 while(!quit)
        {
            //timer
            k=SDL_GetTicks()/1000-benchmark;
        //obsluga eventow
        while( SDL_PollEvent( &e ) != 0 )
            {
                //Kliknieto X lub escape'a
            if( e.type == SDL_QUIT || (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_ESCAPE))
                {
                            quit = true;
                }
            }
            SDL_SetRenderDrawColor( gRenderer, 255, 0xFF, 0xFF, 0xFF );
            SDL_RenderClear( gRenderer );
            gTexture.render(0,0,NULL);
            SDL_RenderPresent( gRenderer );
            if(k==7)
                break;
        }

    P1="0";
    P2="0";
    Screen=Starting_Screen;
    W=0;
}
