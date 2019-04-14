#include "Global.h"
#include "sequence.h"
#include <iostream>
int coin=rand()%1;
int PlayerSequence[3][3];
bool turnPlayer[3][3];
int actionSequence[12];
extern Character gP1T, gP2T;
void throw_a_coin()
{
    coin=rand()%2+1;
}
void clearSequences()
{
    for(int i=0;i<3;i++)
    {
        PlayerSequence[1][i]=0;
        PlayerSequence[2][i]=0;
        turnPlayer[1][i]=false;
        turnPlayer[2][i]=false;
    }

}
void addSequence(int player, int place, int sequence_numb)
{
        if(place!=-1 && sequence_numb!=-1)
        PlayerSequence[player][place]=sequence_numb;

}
void addSequenceToFirstEmptyPlace(int player, int sequence_numb)
{
    if(sequence_numb!=-1)
    for(int i=0;i<3;i++)
    {
        if(PlayerSequence[player][i]==0)
            {
                addSequence(player,i,sequence_numb);
                break;
            }
    }
}
bool canIEndMyTurn(int player)
{
    bool canI=true;
    for(int i =0; i<3;i++)
        {
            if(PlayerSequence[player][i]==0)
                    {
                        canI=false;
                        break;
                    }
        }

    return canI;

}
void removeSequence(int player, int place)
{
    PlayerSequence[player][place]=0;
   // printf("%d removed %d\n",player,place);
}
void turnPlayerAround(int player, int when)
{
    if(turnPlayer[player][when])
        turnPlayer[player][when]=false;
    else
        turnPlayer[player][when]=true;
}
int getSequence(int player,int place)
{
    return PlayerSequence[player][place];
}
int isTurned(int player,int when)
{
    if(turnPlayer[player][when])
        return 1;
    else
        return 0;
}
void clearCombination()
{
    for(int i=0;i<12;i++)
        actionSequence[i]=0;
}
void clearONLYoneCombination(int index)
{
        actionSequence[index]=0;
}
void combineSequences()
{
    //!P1 turn/P2 turn/first card of one of players/ first card of second/ P1 turn/ P2 turn ect...
    actionSequence[0]=turnPlayer[1][0];
    actionSequence[1]=turnPlayer[2][0];
    actionSequence[4]=turnPlayer[1][1];
    actionSequence[5]=turnPlayer[2][1];
    actionSequence[8]=turnPlayer[1][2];
    actionSequence[9]=turnPlayer[2][2];
    for(int i=0, ii=2;i<3;i++,ii+=4)
    {

        if(PlayerSequence[1][i]<=4 && PlayerSequence[2][i]<=4)
        {
            throw_a_coin();
            if(coin==1)
            {
                actionSequence[ii]=10+PlayerSequence[1][i];
                actionSequence[ii+1]=20+PlayerSequence[2][i];
            }
            else
            {
                actionSequence[ii]=20+PlayerSequence[2][i];
                actionSequence[ii+1]=10+PlayerSequence[1][i];
            }

        }
        else if(PlayerSequence[1][i]<=4 && PlayerSequence[2][i]>4)
        {
            if((gP2T.hand[PlayerSequence[2][i]-5].type).size()<2 && gP2T.hand[PlayerSequence[2][i]-5].type!="M")
                {
                actionSequence[ii]=10+PlayerSequence[1][i];
                actionSequence[ii+1]=20+PlayerSequence[2][i];
                }
                else if(gP2T.hand[PlayerSequence[2][i]-5].type=="M")
                {
                    throw_a_coin();
                    if(coin==1)
                    {
                        actionSequence[ii]=10+PlayerSequence[1][i];
                        actionSequence[ii+1]=20+PlayerSequence[2][i];
                    }
                    else
                    {
                        actionSequence[ii]=20+PlayerSequence[2][i];
                        actionSequence[ii+1]=10+PlayerSequence[1][i];
                    }
                }
                else
                {
                    actionSequence[ii]=20+PlayerSequence[2][i];
                    actionSequence[ii+1]=10+PlayerSequence[1][i];
                }
        }
        else if(PlayerSequence[1][i]>4 && PlayerSequence[2][i]<=4)
        {
                if((gP1T.hand[PlayerSequence[1][i]-5].type).size()<2 && gP1T.hand[PlayerSequence[1][i]-5].type!="M")
                {
                actionSequence[ii]=20+PlayerSequence[2][i];
                actionSequence[ii+1]=10+PlayerSequence[1][i];
                }
                else if(gP1T.hand[PlayerSequence[1][i]-5].type=="M")
                {
                    throw_a_coin();
                    if(coin==1)
                    {
                        actionSequence[ii]=10+PlayerSequence[1][i];
                        actionSequence[ii+1]=20+PlayerSequence[2][i];
                    }
                    else
                    {
                        actionSequence[ii]=20+PlayerSequence[2][i];
                        actionSequence[ii+1]=10+PlayerSequence[1][i];
                    }
                }
                else
                {
                actionSequence[ii]=10+PlayerSequence[1][i];
                actionSequence[ii+1]=20+PlayerSequence[2][i];
                }
        }
        else
        {
            //typy
            if(gP1T.hand[PlayerSequence[1][i]-5].type==gP2T.hand[PlayerSequence[2][i]-5].type)
            {
                //randomizuj
                throw_a_coin();
            if(coin==1)
            {
                actionSequence[ii]=10+PlayerSequence[1][i];
                actionSequence[ii+1]=20+PlayerSequence[2][i];
            }
            else
            {
                actionSequence[ii]=20+PlayerSequence[2][i];
                actionSequence[ii+1]=10+PlayerSequence[1][i];
            }

            }
            else if((gP1T.hand[PlayerSequence[1][i]-5].type=="IA" || gP1T.hand[PlayerSequence[1][i]-5].type=="IM"|| gP1T.hand[PlayerSequence[1][i]-5].type=="IO") ||
                     (gP2T.hand[PlayerSequence[2][i]-5].type=="IA" || gP2T.hand[PlayerSequence[2][i]-5].type=="IM"|| gP2T.hand[PlayerSequence[2][i]-5].type=="IO"))
            {
                if(gP2T.hand[PlayerSequence[2][i]-5].type!="IA" && gP2T.hand[PlayerSequence[2][i]-5].type!="IM"&& gP2T.hand[PlayerSequence[2][i]-5].type!="IO"
                        && (gP1T.hand[PlayerSequence[1][i]-5].type=="IA" || gP1T.hand[PlayerSequence[1][i]-5].type=="IM"|| gP1T.hand[PlayerSequence[1][i]-5].type=="IO"))
                {
                actionSequence[ii]=10+PlayerSequence[1][i];
                actionSequence[ii+1]=20+PlayerSequence[2][i];
                }
                else if(gP1T.hand[PlayerSequence[1][i]-5].type!="IA" && gP1T.hand[PlayerSequence[1][i]-5].type!="IM"&& gP1T.hand[PlayerSequence[1][i]-5].type!="IO"
                        && (gP2T.hand[PlayerSequence[2][i]-5].type=="IA" || gP2T.hand[PlayerSequence[2][i]-5].type=="IM"|| gP2T.hand[PlayerSequence[2][i]-5].type=="IO"))
                        {
                actionSequence[ii]=20+PlayerSequence[2][i];
                actionSequence[ii+1]=10+PlayerSequence[1][i];
                        }
                    else if(gP1T.hand[PlayerSequence[1][i]-5].type=="IM")
                        {
                actionSequence[ii]=10+PlayerSequence[1][i];
                actionSequence[ii+1]=20+PlayerSequence[2][i];
                        }
                    else if(gP2T.hand[PlayerSequence[2][i]-5].type=="IM")
                    {
                actionSequence[ii]=20+PlayerSequence[2][i];
                actionSequence[ii+1]=10+PlayerSequence[1][i];
                    }
                    else if(gP1T.hand[PlayerSequence[1][i]-5].type=="IA")
                    {
                    actionSequence[ii]=10+PlayerSequence[1][i];
                    actionSequence[ii+1]=20+PlayerSequence[2][i];
                    }
                    else
                    {
                actionSequence[ii]=20+PlayerSequence[2][i];
                actionSequence[ii+1]=10+PlayerSequence[1][i];
                    }

            }
            else if((gP1T.hand[PlayerSequence[1][i]-5].type=="*A" || gP1T.hand[PlayerSequence[1][i]-5].type=="*M"|| gP1T.hand[PlayerSequence[1][i]-5].type=="*O") ||
                     (gP2T.hand[PlayerSequence[2][i]-5].type=="*A" || gP2T.hand[PlayerSequence[2][i]-5].type=="*M"|| gP2T.hand[PlayerSequence[2][i]-5].type=="*O"))
            {
                if(gP2T.hand[PlayerSequence[2][i]-5].type!="*A" && gP2T.hand[PlayerSequence[2][i]-5].type!="*M"&& gP2T.hand[PlayerSequence[2][i]-5].type!="*O"
                    && (gP1T.hand[PlayerSequence[1][i]-5].type=="*A" || gP1T.hand[PlayerSequence[1][i]-5].type=="*M"|| gP1T.hand[PlayerSequence[1][i]-5].type=="*O"))
            {
                actionSequence[ii]=10+PlayerSequence[1][i];
                actionSequence[ii+1]=20+PlayerSequence[2][i];
            }
                else if(gP1T.hand[PlayerSequence[1][i]-5].type!="*A" && gP1T.hand[PlayerSequence[1][i]-5].type!="*M"&& gP1T.hand[PlayerSequence[1][i]-5].type!="*O"
            && (gP2T.hand[PlayerSequence[2][i]-5].type=="*A" || gP2T.hand[PlayerSequence[2][i]-5].type=="*M"|| gP2T.hand[PlayerSequence[2][i]-5].type=="*O"))
            {
                actionSequence[ii]=20+PlayerSequence[2][i];
                actionSequence[ii+1]=10+PlayerSequence[1][i];
            }
             else if(gP1T.hand[PlayerSequence[1][i]-5].type=="*M")
                        {
                actionSequence[ii]=10+PlayerSequence[1][i];
                actionSequence[ii+1]=20+PlayerSequence[2][i];
                        }
                    else if(gP2T.hand[PlayerSequence[2][i]-5].type=="*M")
                    {
                actionSequence[ii]=20+PlayerSequence[2][i];
                actionSequence[ii+1]=10+PlayerSequence[1][i];
                    }
                    else if(gP1T.hand[PlayerSequence[1][i]-5].type=="*A")
                    {
                    actionSequence[ii]=10+PlayerSequence[1][i];
                    actionSequence[ii+1]=20+PlayerSequence[2][i];
                    }
                    else
                    {
                actionSequence[ii]=20+PlayerSequence[2][i];
                actionSequence[ii+1]=10+PlayerSequence[1][i];
                    }

            }
                     else if(gP1T.hand[PlayerSequence[1][i]-5].type=="M")
                        {
                actionSequence[ii]=10+PlayerSequence[1][i];
                actionSequence[ii+1]=20+PlayerSequence[2][i];
                        }
                    else if(gP2T.hand[PlayerSequence[2][i]-5].type=="M")
                    {
                actionSequence[ii]=20+PlayerSequence[2][i];
                actionSequence[ii+1]=10+PlayerSequence[1][i];
                    }
                    else if(gP1T.hand[PlayerSequence[1][i]-5].type=="A")
                    {
                    actionSequence[ii]=10+PlayerSequence[1][i];
                    actionSequence[ii+1]=20+PlayerSequence[2][i];
                    }
                    else
                    {
                actionSequence[ii]=20+PlayerSequence[2][i];
                actionSequence[ii+1]=10+PlayerSequence[1][i];
                    }
        }
    }
       // for(int i=0;i<12;i++)
       // printf("%d\t",actionSequence[i]);
       // printf("\n");
}
int getAction(int index)
{
    return actionSequence[index];
}
bool isThere(int player, int sequence_numb)
{
    bool is=false;
    for(int i =0; i<3;i++)
        {
            if(PlayerSequence[player][i]==sequence_numb)
                    {
                        is=true;
                        break;
                    }
        }

    return is;
}
