#include "Sprite.h"

namespace liteForge
{
	void Sprite::setRenderer( SDL_Renderer *renderer )
	{
		this->renderer = renderer;
	}

	void Sprite::defaults()
	{
		setTexture();

		if( texture != nullptr && props == nullptr )
		{
			SDL_Rect p;
			p.x = p.y = p.w = p.h = 0;

			SDL_QueryTexture( getTexture(), NULL, NULL, &p.w, &p.h );

			props = rectPtr( new SDL_Rect( p ) );
		}
	}

	void Sprite::setPos( SDL_Rect pos )
	{
		props->x = pos.x;
		props->y = pos.y;
	}

	void Sprite::setPos( unsigned int x, unsigned int y )
	{
		props->x = x;
		props->y = y;
	}

	void Sprite::setSize( SDL_Rect size )
	{
		props->w = size.w;
		props->h = size.h;
	}

	void Sprite::setSize( unsigned int w, unsigned int h )
	{
		props->w = w;
		props->h = h;
	}

	void Sprite::setPath( std::string path )
	{
		this->path = path;
	}

	void Sprite::setTexture( SDL_Texture *texture )
	{
		if( !path.empty() && this->texture == nullptr )
			this->texture = texturePtr( IMG_LoadTexture( renderer, path.c_str() ) );
		else if( path.empty() && this->texture == nullptr )
			this->texture = texturePtr( texture );
	}

	void Sprite::render()
	{
		if( visible )
			if( renderer != nullptr && texture != nullptr && props != nullptr )
				SDL_RenderCopy( renderer, getTexture(), NULL, getProperties() );
	}

	SDL_Texture *Sprite::getTexture()
	{
		return texture.get();
	}

	SDL_Rect *Sprite::getProperties()
	{
		return props.get();
	}

	Sprite::Sprite( SDL_Renderer *r )
	{
		setRenderer( r );
	}

	Sprite::Sprite( SDL_Renderer *r, std::string path )
	{
		setRenderer( r );
		setPath( path );
	}
}