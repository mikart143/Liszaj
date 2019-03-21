#include "Quad.h"



Quad::Quad():p_animation(&QuadSettings::getInstance()->infectionGradient)
{
	healthy = true;
	infected = false;
	resistant = false;
	m_nearbyInfected = false;
	pointOfInfection = false;

	sprite.setTexture(QuadSettings::getInstance()->transparentTexture);
}


Quad::~Quad()
{

}

void Quad::setHealthy()
{
	healthy = true;
	infected = false;
	resistant = false;
	sprite.setTexture(QuadSettings::getInstance()->transparentTexture);
	
}

void Quad::setInfected()
{
	healthy = false;
	infected = true;
	resistant = false;
	sprite.setTexture(QuadSettings::getInstance()->solidTexture);

	p_animation = thor::ColorAnimationModified(&QuadSettings::getInstance()->infectionGradient);
	p_animation(sprite, 0.0f);

	hitTime = SimulationSettings::getInstance()->globalClock.getElapsedTime();


	m_nearbyQuads.clear();
	m_nearbyQuads.shrink_to_fit();

	Utility().generateNearbyElements(&TileSettings::getInstance()->tileQuads,&m_nearbyQuads, TileSettings::getInstance()->tileSize,position);
}

void Quad::setResistance()
{
	healthy = false;
	infected = false;
	resistant = true;
	m_nearbyInfected = false;

	sprite.setTexture(QuadSettings::getInstance()->solidTexture);

	p_animation = thor::ColorAnimationModified(&QuadSettings::getInstance()->resistanceGradient);
	p_animation(sprite, 0.0f);
}

void Quad::updateState()
{
	if (healthy) return;
	if(infected || pointOfInfection)
	{	
		if(SimulationSettings::getInstance()->globalClock.getElapsedTime() - hitTime < SimulationSettings::getInstance()->lengthOfInfection || pointOfInfection)
		{			
			if (SimulationSettings::getInstance()->colorGradation)
			{
				if (!pointOfInfection)p_animation(sprite, (SimulationSettings::getInstance()->globalClock.getElapsedTime() - hitTime) / SimulationSettings::getInstance()->lengthOfInfection);
				
			}
			else p_animation(sprite, 0.0f);
			if(!m_nearbyInfected && !(SimulationSettings::getInstance()->globalClock.getElapsedTime() - hitTime < SimulationSettings::getInstance()->lengthOfInfectionGap))
			{

				if (SimulationSettings::getInstance()->multiInfectionsOfQuad) m_nearbyInfected = true;
				for(auto &ne : m_nearbyQuads)
				{
					if(Utility().yesOrNo(SimulationSettings::getInstance()->probabilityOfInfection) && ne->healthy)
					{
						ne->setInfected();
						ne->hitTime = SimulationSettings::getInstance()->globalClock.getElapsedTime();
					}
				}
			}
		}else
		{
			setResistance();
			hitTime = SimulationSettings::getInstance()->globalClock.getElapsedTime();	
		}
	}else if(resistant)
	{
		if (SimulationSettings::getInstance()->globalClock.getElapsedTime() - hitTime < SimulationSettings::getInstance()->lengthOfResistance)
		{
			if (SimulationSettings::getInstance()->colorGradation)
			{
				if (!pointOfInfection)p_animation(sprite, (SimulationSettings::getInstance()->globalClock.getElapsedTime() - hitTime) / SimulationSettings::getInstance()->lengthOfResistance);

			}
			else p_animation(sprite, 0.0f);
			return;
		}
		else setHealthy();
	}
}

void Quad::setPosition(int x, int y)
{
	position = sf::Vector2u(x, y);
	sprite.setPosition(x * QuadSettings::getInstance()->quadDimensions.x, y* QuadSettings::getInstance()->quadDimensions.y);
}

void Quad::updateNearbyElements()
{
	m_nearbyQuads.clear();
	m_nearbyQuads.shrink_to_fit();

	Utility().generateNearbyElements(&TileSettings::getInstance()->tileQuads, &m_nearbyQuads, TileSettings::getInstance()->tileSize, position);
}


sf::Sprite* Quad::getSprite()
{
	return &sprite;
}
