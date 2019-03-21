#include "QuadSettings.h"

QuadSettings *QuadSettings::s_quad_settings = nullptr;

QuadSettings* QuadSettings::getInstance()
{
	if (!s_quad_settings)
		s_quad_settings = new QuadSettings();
	return s_quad_settings;

}

void QuadSettings::updateResistanceTextureColor(ImVec4 resisted)
{
	resistanceColor = sf::Color(255 * resisted.x, 255 * resisted.y, 255 * resisted.z, 255 * resisted.w);
	resistanceGradient[0.0f] = resistanceColor;
	resistanceGradient[1.0f] = healthyColor;
}


void QuadSettings::updateInfectedTextureColor(ImVec4 infected)
{
	infectedColor = sf::Color(255*infected.x, 255 * infected.y, 255 * infected.z, 255 * infected.w);
	infectionGradient[0.0f] = infectedColor;
	infectionGradient[1.0f] = resistanceColor;

}

void QuadSettings::updateHealthyTextureColor(ImVec4 healthy)
{
	healthyColor = sf::Color(255 * healthy.x, 255 * healthy.y, 255 * healthy.z, 255 * healthy.w);
	resistanceGradient[0.0f] = resistanceColor;
	resistanceGradient[1.0f] = healthyColor;
}

void QuadSettings::updateTextures()
{
	transparentImage.create(quadDimensions.x, quadDimensions.y, sf::Color(0, 0, 0, 0));
	transparentTexture.loadFromImage(transparentImage);

	solidImage.create(quadDimensions.x, quadDimensions.y, sf::Color::White);
	solidTexture.loadFromImage(solidImage);

}

QuadSettings::QuadSettings()
{
	infectedColor = sf::Color::Red;
	resistanceColor = sf::Color::Yellow;
	healthyColor = sf::Color(255, 170, 128, 255);

	quadDimensions = sf::Vector2f(10, 10);

	solidImage.create(quadDimensions.x, quadDimensions.y, sf::Color::White);
	solidTexture.loadFromImage(solidImage);
	
	transparentImage.create(quadDimensions.x, quadDimensions.y, sf::Color(0, 0, 0, 0));
	transparentTexture.loadFromImage(transparentImage);

	infectionGradient[0.0f] = infectedColor;
	infectionGradient[1.0f] = resistanceColor;

	resistanceGradient[0.0f] = resistanceColor;
	resistanceGradient[1.0f] = healthyColor;
}


QuadSettings::~QuadSettings()
{
	delete s_quad_settings;
}
