#ifndef __LFSYS_H__
#define __LFSYS_H__

#include <iostream>
#include "SDL.h"

#include "Control.h"
#include "Build.h"

namespace liteForge
{
	class LFSys
	{
	private:
		SDL_Window *WIND;
		SDL_Renderer *REND;
		SDL_Event EVENT;

		Control input;
		Build build;

		bool RUNNING = true;

		void init();

		void loop();

		void events();

		void draw();

	public:
		LFSys( std::string win_t, unsigned int win_w, unsigned int win_h );
		~LFSys() { SDL_Quit(); }
	};
};

#endif