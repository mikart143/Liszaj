#include "Utility.h"




Utility::Utility()
{
}


Utility::~Utility()
{
}

bool Utility::yesOrNo(float probability)
{
	return rand() % 100 < (probability * 100);
}

void Utility::generateNearbyElements(std::vector<Quad> *tileQuads, std::vector<Quad*> *nearbyQuads,
	 sf::Vector2u tileSize, sf::Vector2u position)
{

	//Left top
	if (existQuad(sf::Vector2u(position.x - 1, position.y - 1), tileSize))
		nearbyQuads->push_back(&tileQuads->at((position.y - 1) + ((position.x - 1)*tileSize.y)));
	//Left
	if (existQuad(sf::Vector2u(position.x - 1, position.y), tileSize))
		nearbyQuads->push_back(&tileQuads->at((position.y) + ((position.x - 1)*tileSize.y)));
	//Left bottom
	if (existQuad(sf::Vector2u(position.x - 1, position.y + 1), tileSize))
		nearbyQuads->push_back(&tileQuads->at((position.y + 1) + ((position.x - 1)*tileSize.y)));
	//Top
	if (existQuad(sf::Vector2u(position.x, position.y - 1), tileSize))
		nearbyQuads->push_back(&tileQuads->at((position.y - 1) + ((position.x)*tileSize.y)));
	//Bottom
	if (existQuad(sf::Vector2u(position.x, position.y + 1), tileSize))
		nearbyQuads->push_back(&tileQuads->at((position.y + 1) + ((position.x)*tileSize.y)));
	//Right top
	if (existQuad(sf::Vector2u(position.x + 1, position.y - 1), tileSize))
		nearbyQuads->push_back(&tileQuads->at((position.y - 1) + ((position.x + 1)*tileSize.y)));
	//Right
	if (existQuad(sf::Vector2u(position.x + 1, position.y), tileSize))
		nearbyQuads->push_back(&tileQuads->at((position.y) + ((position.x + 1)*tileSize.y)));
	//Right bottom
	if (existQuad(sf::Vector2u(position.x + 1, position.y + 1), tileSize))
		nearbyQuads->push_back(&tileQuads->at((position.y + 1) + ((position.x + 1)*tileSize.y)));

}

bool Utility::clickedInWindow(sf::Vector2f windowSize, sf::Vector2f windowPosition, sf::Vector2u mousePosition)
{
	if (mousePosition.x >= windowPosition.x && mousePosition.x <= windowPosition.x + windowSize.x && mousePosition.y >= windowPosition.y && mousePosition.y <= windowPosition.y + windowSize.y) return true;
	return false;
}


void Utility::allDivisors(std::vector<std::string> *v_factors)
{
	int n, m;


	v_factors->clear();
	v_factors->shrink_to_fit();


	if(TileSettings::getInstance()->mainWindowSize.x > TileSettings::getInstance()->mainWindowSize.y )
	{
		m = TileSettings::getInstance()->mainWindowSize.x;
		n = TileSettings::getInstance()->mainWindowSize.y;
	}else
	{
		n = TileSettings::getInstance()->mainWindowSize.x;
		m = TileSettings::getInstance()->mainWindowSize.y;
	}


	for (int i = 1; i <= n; i++)
	{
		if (n%i == 0 && m%i == 0)
		{
			v_factors->push_back(std::to_string(n/i));
		}
	}
}

bool Utility::existQuad(sf::Vector2u point, sf::Vector2u tileSize)
{

	if (point.x >= 0 && point.x < tileSize.x && point.y >= 0 && point.y < tileSize.y && (point.y + point.x*tileSize.x) < tileSize.x*tileSize.y) return true;
	return false;
}



