#ifndef __LAYERHANDLER_H__
#define __LAYERHANDLER_H__

#include <memory>
#include <unordered_map>
#include <iostream>

#include "Layer.h"

namespace liteForge
{
	typedef std::unique_ptr<Layer> layerPtr;
	typedef std::unordered_map<std::string, layerPtr> layerMap;

	class LayerHandler
	{
	private:
		layerMap layers;
	public:
		void add( std::string name, Layer *layer );
		bool find( std::string name );
		void del( std::string name );

		void createLayer( std::string name, unsigned int id );

		Layer *get( std::string name );
		layerMap &getAll();
	};
}

#endif