#include <fstream>
#include "Character.h"
#include <iostream>
extern SDL_Renderer* gRenderer;

Character::Character()
{
	mTexture = NULL;
	mWidth = 0;
	mHeight = 0;
	toLeft = SDL_FLIP_NONE;
	posX = 0;
	posY = 0;
}

void Character::render( int x, int y, SDL_Rect* clip, double angle, SDL_Point* center, SDL_RendererFlip flip )
{

    SDL_Rect renderQuad = { x, y, mWidth, mHeight };


    if( clip != NULL )
    {
        renderQuad.w = clip->w;
        renderQuad.h = clip->h;
    }

    SDL_RenderCopyEx( gRenderer, mTexture, clip, &renderQuad, angle, center, flip );
}

void loadCharacter(string Cname, Character *player)
{
    (*player).champion_code.name=Cname;
    string pathS="files/stats/"+Cname+".txt";
    string pathG="grafika/champ/"+Cname+"/animacje/"+Cname+".png";
    string pathC="files/stats/"+Cname+"Cards.txt";
    (*player).loadFromFile(pathG);
    loadStats(pathS,player);
    loadCards(pathC,player);
   // std::string pathC="grafika/";
}
void loadStats(string path, Character *player)
{
    const char *cstr = path.c_str();
    fstream file;
    file.open(cstr,ios::in);
    if(file.good()==false)
    {
        printf("Error file doesnot exist\n");
    }
    else
    {
        file>>(*player).champion_code.hp;
        file>>(*player).champion_code.animNidle;
        file>>(*player).champion_code.animNwalk;
        file>>(*player).champion_code.animNcard1;
        file>>(*player).champion_code.animNcard2;
        file>>(*player).champion_code.animNcard3;
        file>>(*player).champion_code.animNcard4;
        file>>(*player).champion_code.animNcard5;
        file>>(*player).champion_code.animNhurt;
        file>>(*player).champion_code.animNdead;

        for(int i=0;i<((*player).champion_code.animNidle);i++)
            loadRect(animIdle,i,&((*player).champion_code.animation[animIdle][i]));
        for(int i=0;i<((*player).champion_code.animNwalk);i++)
            loadRect(animWalk,i,&((*player).champion_code.animation[animWalk][i]));
        for(int i=0;i<((*player).champion_code.animNcard1);i++)
            loadRect(animCard1,i,&((*player).champion_code.animation[animCard1][i]));
        for(int i=0;i<((*player).champion_code.animNcard2);i++)
            loadRect(animCard2,i,&((*player).champion_code.animation[animCard2][i]));
        for(int i=0;i<((*player).champion_code.animNcard3);i++)
            loadRect(animCard3,i,&((*player).champion_code.animation[animCard3][i]));
        for(int i=0;i<((*player).champion_code.animNcard4);i++)
            loadRect(animCard4,i,&((*player).champion_code.animation[animCard4][i]));
        for(int i=0;i<((*player).champion_code.animNcard5);i++)
            loadRect(animCard5,i,&((*player).champion_code.animation[animCard5][i]));
        for(int i=0;i<((*player).champion_code.animNhurt);i++)
            loadRect(animHurt,i,&((*player).champion_code.animation[animHurt][i]));
        for(int i=0;i<((*player).champion_code.animNdead);i++)
            loadRect(animDead,i,&((*player).champion_code.animation[animDead][i]));

    }

    file.close();
    delete [] cstr;
}
void loadCards(string path, Character *player)
{

    const char *cstr = path.c_str();
    fstream file;
    file.open(cstr,ios::in);
    if(file.good()==false)
    {
        printf("Error file doesnot exist\n");
    }
 else
    {
        (*player).champion_code.reduction=0;
        for(int j=0;j<5;j++)
        {
            for(int i=0;i<15;i++)
            {
            (*player).hand[j].where[i].cX=0;
            (*player).hand[j].where[i].cY=0;
            }
            (*player).hand[j].status="-";
        }
        string buff="";
        int how_much;
        int counting=2;
        for(int i=0;i<5;i++)
        {
            counting=2;
            loadCardGraphicRect(i,&((*player).hand[i].graphic));
            how_much=0;
            buff="";
            file>>(*player).hand[i].id;

            while(counting>0)
            {
                getline(file,buff);
                counting--;
            }

            (*player).hand[i].type=buff;

            if(buff=="A"|| buff=="*A" || buff=="IA")
                {
                    file>>(*player).hand[i].value;

                    file>>how_much;
                    for(int j=0;j<how_much;j++)
                    {
                        file>>(*player).hand[i].where[j].cX;
                        file>>(*player).hand[i].where[j].cY;
                    }
                    continue;
                }
                else if(buff=="M"|| buff=="*M" || buff=="IM")
                {
                        file>>(*player).hand[i].where[0].cX;
                        file>>(*player).hand[i].where[0].cY;
                        continue;
                }
                else if(buff=="O"|| buff=="*O" || buff=="IO")
                {
                    file>>(*player).hand[i].value;
                    file>>how_much;
                    if(how_much!=-1)
                    {
                        for(int j=0;j<how_much;j++)
                        {
                            file>>(*player).hand[i].where[j].cX;
                            file>>(*player).hand[i].where[j].cY;
                        }
                    }
                    counting=2;
                    while(counting>0)
                    {
                        getline(file,(*player).hand[i].status);
                        counting--;
                    }
                    continue;
                }
                else printf("Error while reading from file");


        }

    }


    file.close();
    delete [] cstr;
}
