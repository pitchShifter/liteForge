#ifndef __SPRITE_H__
#define __SPRITE_H__

#include <memory>
#include "SDL.h"
#include "SDL_image.h"
#include <iostream>

namespace liteForge
{
	struct texture_deleter
	{
		void operator()( SDL_Texture * stexture ) const
		{
			if( stexture != nullptr )
				SDL_DestroyTexture( stexture );
		}
	};

	typedef std::unique_ptr<SDL_Texture, texture_deleter> texturePtr;
	typedef std::unique_ptr<SDL_Rect> rectPtr;

	class Sprite
	{
	protected:
		std::string path = std::string();
		SDL_Renderer *renderer;
		texturePtr texture = nullptr;
		rectPtr props = nullptr;

		bool visible = true;
	public:
		void setRenderer( SDL_Renderer *renderer );
		void defaults();
		void setPos( SDL_Rect pos );
		void setPos( unsigned int x, unsigned int y );
		void setSize( SDL_Rect size );
		void setSize( unsigned int w, unsigned int h );
		void setPath( std::string path );
		void setTexture( SDL_Texture *texture = nullptr );
		void render();

		SDL_Texture *getTexture();
		SDL_Rect *getProperties();

		Sprite(){};
		Sprite( SDL_Renderer *r );
		Sprite( SDL_Renderer *r, std::string path );
	};
}

#endif