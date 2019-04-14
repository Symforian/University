#include "Texture.h"

using namespace std;
enum anim
{
    animIdle,
    animWalk,
    animCard1,
    animCard2,
    animCard3,
    animCard4,
    animCard5,
    animHurt,
    animDead,
    Total
};

extern void loadRect(anim which,int number,SDL_Rect *old);
extern void loadCardGraphicRect(int number,SDL_Rect *Graph);
typedef struct champion
{
  string name;
  int hp;
    int reduction;
  int animNidle,animNwalk,animNcard1,animNcard2,animNcard3,animNcard4,animNcard5,animNhurt,animNdead;
  SDL_Rect animation[Total][6];

} champion;

typedef struct grid_reff
{
    int cX, cY;
}coordinates;

typedef struct card
{
    int id;
    string type;
    int value;
    coordinates where[15];
    string status;
    SDL_Rect graphic;
} card;


// Card types
/*
normal:
    A
    M
    O
fast:
    *A
    *M
    *O
instant:
    IA
    IM
    IO
instant>fast>normal
M>A>O
where
a>b mean a is faster then b
*/
//statuses
/*
None - no status
Red - damage taken reduced by value
Heal - restores value point of health points
*/
class Character:public Texture
{
    friend class Card;
    public:
    Character();
    SDL_RendererFlip toLeft;
    champion champion_code;
    card hand[5];
    void play_a_card(int id_c);
    void render( int x, int y, SDL_Rect* clip = NULL, double angle = 0.0, SDL_Point* center = NULL, SDL_RendererFlip flip = SDL_FLIP_NONE );
    int posX,posY;

};

void loadCharacter(string Cname, Character *player);
void loadStats(string path, Character *player);
void loadCards(string path, Character *player);
