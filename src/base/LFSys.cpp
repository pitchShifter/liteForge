#include "LFSys.h"

namespace liteForge
{
	LFSys::LFSys( std::string win_t, unsigned int win_w, unsigned int win_h )
	{
		if( SDL_Init( SDL_INIT_EVERYTHING ) != 0 )
			return;

		WIND = SDL_CreateWindow( win_t.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, win_w, win_h, 0 );

		if( WIND == NULL )
			return;

		REND = SDL_CreateRenderer( WIND, -1, 0 );

		if( REND == NULL )
			return;

		init();

		loop();

	}

	void LFSys::init()
	{
		build.init( WIND, REND );
	}

	void LFSys::loop()
	{
		while( RUNNING )
		{
			events();

			draw();
		}
	}

	void LFSys::events()
	{
		while( SDL_PollEvent( &EVENT ) )
		{
			input.EventHandler( &EVENT );
			if( EVENT.type == SDL_QUIT )
				RUNNING = false;
		}
	}

	void LFSys::draw()
	{
		SDL_RenderClear( REND );

		build.render();

		SDL_RenderPresent( REND );
	}
}