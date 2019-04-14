#include "Global.h"
#include "ScreenControl.h"
/*
-lmingw32
-lSDL2main
-lSDL2
-lSDL2_image
-lSDL2_mixer
-lSDL2_ttf
*/

const int SCREEN_WIDTH = 1280;//1280
const int SCREEN_HEIGHT = 720;//720
SDL_Window* gWindow = NULL;
SDL_Renderer* gRenderer = NULL;


Character gP1T;
Character gP2T;
Texture gTexture;


void close();

bool init()
{
    bool success = true;


    if( SDL_Init(SDL_INIT_EVERYTHING) < 0 )
    {
        printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
        success = false;
    }
    else
    {
        gWindow = SDL_CreateWindow( "Mind Games", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
        if( gWindow == NULL )
        {
            printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
            success = false;
        }
		else
		{
			gRenderer = SDL_CreateRenderer( gWindow, -1, SDL_RENDERER_ACCELERATED );
			if( gRenderer == NULL )
			{
				printf( "Renderer could not be created! SDL Error: %s\n", SDL_GetError() );
				success = false;
			}
			else
			{
				SDL_SetRenderDrawColor( gRenderer, 250, 0xFF, 0xFF, 0xFF );

				int imgFlags = IMG_INIT_PNG;
				if( !( IMG_Init( imgFlags ) & imgFlags ) )
				{
					printf( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() );
					success = false;
				}
			}

    }
    }

    return success;
}


int main( int argc, char* args[] )
{

    srand( time( NULL ) );

    //Inicjalizacja SDL'a i tworzenie okna
    if( !init() )
    {
        printf( "Failed to initialize!\n" );
    }
    else
    {
        {
            ScreenControl();

            }

    }

    close();

    return 0;
}



void close()
{

	gTexture.freeT();
	gP1T.freeT();
	gP2T.freeT();
    SDL_DestroyRenderer( gRenderer );
	SDL_DestroyWindow( gWindow );
	gWindow = NULL;
	gRenderer = NULL;

	IMG_Quit();
    SDL_Quit();
}


