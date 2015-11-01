#include "UserInterface.h"

namespace liteForge
{
	void UserInterface::init( SDL_Renderer *renderer, LayerHandler *lhandler )
	{
		this->renderer = renderer;
		this->lhandler = lhandler;

		storeLayers();
	}

	void UserInterface::storeLayers()
	{
		lhandler->add( "ui-header-bg", new UIHeader( renderer ) );
		//lhandler->createLayer( "ui-header", header.layer_id );
	}
}