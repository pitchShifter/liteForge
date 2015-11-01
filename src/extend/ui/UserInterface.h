#ifndef __USERINTERFACE_H__
#define __USERINTERFACE_H__

#include "SDL.h"

#include "LayerHandler.h"
#include "UIHeader.h"

namespace liteForge
{
	class UserInterface
	{
	private:
		SDL_Renderer *renderer;
		LayerHandler *lhandler;
	public:
		void init( SDL_Renderer *renderer, LayerHandler *lhandler );
		void storeLayers();
	};
}

#endif