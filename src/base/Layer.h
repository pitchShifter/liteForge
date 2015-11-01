#ifndef __LAYER_H__
#define __LAYER_H__

#include <memory>
#include <unordered_map>
#include <iostream>

#include "Sprite.h"

namespace liteForge
{
	typedef std::unique_ptr<Sprite> spritePtr;
	typedef std::unordered_map<std::string, spritePtr> spriteMap;

	class Layer
	{
	protected:
		spriteMap sprites;

		void add( std::string name );
		bool find( std::string name );
		void del( std::string name );

		Sprite *get( std::string name );
	public:
		unsigned int layer_id;
		spriteMap &getAll();

	};
}

#endif