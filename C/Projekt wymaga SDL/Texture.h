#include <SDL2/SDL.h>
#include <string>

class Texture
{
	public:

		Texture();

		~Texture();

		bool loadFromFile( std::string path );

		void freeT();

		void render( int x, int y, SDL_Rect* clip  );

		int getWidth();
		int getHeight();

	protected:
		SDL_Texture* mTexture;

		int mWidth;
		int mHeight;
};

