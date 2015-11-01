#include "Build.h"

/**
 * Build class is the main extender to the system classes
 * This class will set the default information (such as UI elements, 
 * options, etc.)
 */

namespace liteForge
{
	void Build::init( SDL_Window *window, SDL_Renderer *renderer )
	{
		windowref = window;
		renderref = renderer;

		// Initialize user interface
		ui.init( renderref, &lhandler );
	}
	
	void Build::render()
	{
		for( auto &i : lhandler.getAll() )
		{
			for( auto &j : i.second->getAll() )
			{
				j.second->render();
			}
		}
	}
}