#include "LayerHandler.h"

namespace liteForge
{
	void LayerHandler::add( std::string name, Layer *layer )
	{
		if( !find( name ) )
			layers.insert( std::make_pair( name, layerPtr( layer ) ) );
	}

	bool LayerHandler::find( std::string name )
	{
		auto it = layers.find( name );

		// Found
		if( it != layers.end() )
			return true;

		return false;
	}

	void LayerHandler::del( std::string name )
	{
		if( find( name ) )
			layers.erase( name );
	}

	void LayerHandler::createLayer( std::string name, unsigned int id )
	{
		//add( name );
		//get( name )->layer_id = id;
	}

	Layer *LayerHandler::get( std::string name )
	{
		return layers[name].get();
	}

	layerMap &LayerHandler::getAll()
	{
		return layers;
	}
}