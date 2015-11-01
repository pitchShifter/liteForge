#include "UIHeader.h"

namespace liteForge
{
	UIHeader::UIHeader( SDL_Renderer *renderer )
	{
		// Layer
		layer_id = 1;

		add( "ui-header-bg" );
		get( "ui-header-bg" )->setRenderer( renderer );
		get( "ui-header-bg" )->setPath( "includes/h-bg.png" );
		get( "ui-header-bg" )->defaults();
		get( "ui-header-bg" )->setSize( 1280, 49 );
	}
}