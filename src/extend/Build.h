#ifndef __BUILD_H__
#define __BUILD_H__

#include <iostream>
#include <unordered_map>
#include <memory>

#include "LayerHandler.h"
#include "UserInterface.h"

namespace liteForge
{
	class Build
	{
	private:
		LayerHandler lhandler;
		UserInterface ui;

		SDL_Window *windowref;
		SDL_Renderer *renderref;
	public:
		void init( SDL_Window *window, SDL_Renderer *renderer );
		void render();
	};

}

#endif