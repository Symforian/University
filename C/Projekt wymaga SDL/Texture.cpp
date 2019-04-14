#include <SDL2/SDL_image.h>
#include <stdio.h>

#include "Texture.h"
extern SDL_Renderer* gRenderer;


Texture::Texture()
{

	mTexture = NULL;
	mWidth = 0;
	mHeight = 0;
}

Texture::~Texture()
{

	freeT();
}

bool Texture::loadFromFile( std::string path )
{

	freeT();


	SDL_Texture* newTexture = NULL;

	SDL_Surface* loadedSurface = IMG_Load( path.c_str() );
	if( loadedSurface == NULL )
	{
		printf( "Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError() );
	}
	else
	{

		SDL_SetColorKey( loadedSurface, SDL_TRUE, SDL_MapRGB( loadedSurface->format, 255, 0, 0 ) );

        newTexture = SDL_CreateTextureFromSurface( gRenderer, loadedSurface );
		if( newTexture == NULL )
		{
			printf( "Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
		}
		else
		{

			mWidth = loadedSurface->w;
			mHeight = loadedSurface->h;
		}


		SDL_FreeSurface( loadedSurface );
	}

	mTexture = newTexture;
	return mTexture != NULL;
}



void Texture::freeT()
{

	if( mTexture != NULL )
	{
		SDL_DestroyTexture( mTexture );
		mTexture = NULL;
		mWidth = 0;
		mHeight = 0;
	}
}

void Texture::render( int x, int y, SDL_Rect* clip )
{

	SDL_Rect renderQuad = { x, y, mWidth, mHeight };
	   if( clip != NULL )
    {
        renderQuad.w = clip->w;
        renderQuad.h = clip->h;
    }
	SDL_RenderCopy( gRenderer, mTexture, clip, &renderQuad );
}

int Texture::getWidth()
{
	return mWidth;
}

int Texture::getHeight()
{
	return mHeight;
}

