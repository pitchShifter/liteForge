#include "Layer.h"

namespace liteForge
{
	void Layer::add( std::string name )
	{
		if( !find( name ) )
			sprites.insert( std::make_pair( name, spritePtr( new Sprite() ) ) );
	}

	bool Layer::find( std::string name )
	{
		auto it = sprites.find( name );

		// Found
		if( it != sprites.end() )
			return true;

		return false;
	}

	void Layer::del( std::string name )
	{
		if( find( name ) )
			sprites.erase( name );
	}

	Sprite *Layer::get( std::string name )
	{
		return sprites[name].get();
	}

	spriteMap &Layer::getAll()
	{
		return sprites;
	}
}