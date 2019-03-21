#include "SimulationSettings.h"

SimulationSettings *SimulationSettings::s_simulation_settings = nullptr;

SimulationSettings* SimulationSettings::getInstance()
{
	if (!s_simulation_settings)
		s_simulation_settings = new SimulationSettings();
	return s_simulation_settings;
}

SimulationSettings::SimulationSettings()
{
	lengthOfInfection = sf::seconds(6);
	lengthOfResistance = sf::seconds(3);
	lengthOfInfectionGap = sf::seconds(0.1f);
	globalClock.restart();

	probabilityOfInfection = 0.1f;

	multiInfectionsOfQuad = false;

	pointOfInfection = false;

	stopLogic = false;

	colorGradation = true;

	currentFPS = 0.f;
}


SimulationSettings::~SimulationSettings()
{
	delete s_simulation_settings;
}
