#include "TileSettings.h"

TileSettings *TileSettings::s_tile_settings = nullptr;

TileSettings* TileSettings::getInstance()
{
	if (!s_tile_settings)
		s_tile_settings = new TileSettings();
	return s_tile_settings;
}

TileSettings::TileSettings()
{
	tileQuads.clear();
	tileQuads.shrink_to_fit();

	tileSize = sf::Vector2u(0, 0);

	mainWindowSize = sf::Vector2u(0, 0);
}


TileSettings::~TileSettings()
{
	delete s_tile_settings;
}
