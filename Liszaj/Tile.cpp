#include "Tile.h"



Tile::Tile()
{
}

void Tile::init()
{

	TileSettings::getInstance()->tileSize = sf::Vector2u(TileSettings::getInstance()->mainWindowSize.x/QuadSettings::getInstance()->quadDimensions.x,
		TileSettings::getInstance()->mainWindowSize.y / QuadSettings::getInstance()->quadDimensions.y);
	TileSettings::getInstance()->tileQuads.clear();
	TileSettings::getInstance()->tileQuads.shrink_to_fit();
	TileSettings::getInstance()->tileQuads.reserve(TileSettings::getInstance()->tileSize.x * TileSettings::getInstance()->tileSize.y);

	QuadSettings::getInstance()->updateTextures();

	   for(unsigned int i = 0; i < TileSettings::getInstance()->tileSize.x; i++)
	   {
		   for(unsigned int j = 0; j < TileSettings::getInstance()->tileSize.y; j++)
		   {
			   Quad quad;
			   quad.setPosition(i, j);
			   TileSettings::getInstance()->tileQuads.push_back(quad);
		   }
	   }

	
}

void Tile::infect(sf::Vector2f mousePosition)
{
	for (auto &element : TileSettings::getInstance()->tileQuads) {
		if (element.getSprite()->getGlobalBounds().contains(mousePosition) /*&& element.healthy */) {
			if(SimulationSettings::getInstance()->pointOfInfection)element.pointOfInfection = true;
			element.setInfected();
		}
	}
}

void Tile::remove()
{

	if (TileSettings::getInstance()->tileSize.x == 0 || TileSettings::getInstance()->tileSize.y == 0) return;


	TileSettings::getInstance()->tileQuads.erase(TileSettings::getInstance()->tileQuads.end() - TileSettings::getInstance()->tileSize.y, TileSettings::getInstance()->tileQuads.end());
	TileSettings::getInstance()->tileQuads.shrink_to_fit();
	for (unsigned int i = 0; i < TileSettings::getInstance()->tileSize.y - 1; i++)
	{
		int index = TileSettings::getInstance()->tileSize.y + i * TileSettings::getInstance()->tileSize.y - (i + 1);
		TileSettings::getInstance()->tileQuads.erase(TileSettings::getInstance()->tileQuads.begin() + index);
	}
	TileSettings::getInstance()->tileQuads.shrink_to_fit();
	TileSettings::getInstance()->tileSize = sf::Vector2u(TileSettings::getInstance()->tileSize.x -1, TileSettings::getInstance()->tileSize.y -1);

	QuadSettings::getInstance()->quadDimensions = sf::Vector2f(float(TileSettings::getInstance()->mainWindowSize.x) / TileSettings::getInstance()->tileSize.x, float(TileSettings::getInstance()->mainWindowSize.y) / TileSettings::getInstance()->tileSize.y);
	QuadSettings::getInstance()->updateTextures();

	updatePositions();
	
}

void Tile::add()
{

	if (TileSettings::getInstance()->tileSize.x == TileSettings::getInstance()->mainWindowSize.x || TileSettings::getInstance()->tileSize.y == TileSettings::getInstance()->mainWindowSize.y) return;

	if(TileSettings::getInstance()->tileQuads.empty())
	{
		TileSettings::getInstance()->tileSize = sf::Vector2u(1,1);
		QuadSettings::getInstance()->quadDimensions = sf::Vector2f(TileSettings::getInstance()->mainWindowSize.x, TileSettings::getInstance()->mainWindowSize.y);
		QuadSettings::getInstance()->updateTextures();
		Quad quad;
		quad.setPosition(0, 0);
		quad.getSprite()->setTextureRect(sf::IntRect(0, 0, QuadSettings::getInstance()->quadDimensions.x, QuadSettings::getInstance()->quadDimensions.y));
		TileSettings::getInstance()->tileQuads.push_back(quad);

		return;
	}

	TileSettings::getInstance()->tileSize = sf::Vector2u(TileSettings::getInstance()->tileSize.x, TileSettings::getInstance()->tileSize.y + 1);

	for (unsigned int i = 0; i < TileSettings::getInstance()->tileSize.x; i++)
	{
		Quad quad;
		quad.setPosition(i, TileSettings::getInstance()->tileSize.y - 1);
		unsigned int index = (TileSettings::getInstance()->tileSize.y - 1) * (i + 1) + i;
		if(index == TileSettings::getInstance()->tileQuads.size())
		{
			TileSettings::getInstance()->tileQuads.push_back(quad);
		}else
		{
			TileSettings::getInstance()->tileQuads.insert(TileSettings::getInstance()->tileQuads.begin() + index, quad);
		}
	}

	TileSettings::getInstance()->tileSize = sf::Vector2u(TileSettings::getInstance()->tileSize.x + 1, TileSettings::getInstance()->tileSize.y);

	for (unsigned int j = 0; j < TileSettings::getInstance()->tileSize.y; j++)
	{
		Quad quad;
		quad.setPosition(TileSettings::getInstance()->tileSize.x - 1, j);
		TileSettings::getInstance()->tileQuads.push_back(quad);
	}

	// Dodanie tego do funkcji updatePosition();
	QuadSettings::getInstance()->quadDimensions = sf::Vector2f(float(TileSettings::getInstance()->mainWindowSize.x) / TileSettings::getInstance()->tileSize.x, float(TileSettings::getInstance()->mainWindowSize.y) / TileSettings::getInstance()->tileSize.y);
	QuadSettings::getInstance()->updateTextures();

	updatePositions();


}


Tile::~Tile()
{

}

void Tile::updatePositions()
{
	for (unsigned int i = 0; i < TileSettings::getInstance()->tileSize.x; i++)
	{
		for (unsigned int j = 0; j < TileSettings::getInstance()->tileSize.y; j++)
		{
			Quad *quad = &TileSettings::getInstance()->tileQuads.at(j + i * TileSettings::getInstance()->tileSize.y);
			quad->setPosition(i, j);
			quad->getSprite()->setTextureRect(sf::IntRect(0, 0, QuadSettings::getInstance()->quadDimensions.x, QuadSettings::getInstance()->quadDimensions.y));
			if (quad->infected) quad->updateNearbyElements();
		}
	}
}
