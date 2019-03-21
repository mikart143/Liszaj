#pragma once
#include <SFML/System/Time.hpp>
#include <Thor/Time/StopWatch.hpp>
/**
 *	Singleton, który przechwuje najważniejsze informacje o symulacji. Informacje wykorzystywane są przez wszystkie komórki oraz zakładkę Statystyki w Panelu Sterowania.
 */
class SimulationSettings
{
public:
	/**
	 *  Zegar globalny dla symulacji.
	 */
	thor::StopWatch globalClock;
	/**
	 *  Czas w sekundach, jak długo ma trwać choroba.
	 */
	sf::Time lengthOfInfection;
	/**
	 *  Czas w sekundach, jak długo ma trwać odporność.
	 */
	sf::Time lengthOfResistance;
	/**
	 * Czas w sekundach pomiędzy kolejnymi infekcjami.
	 */
	sf::Time lengthOfInfectionGap;

	/**
	 * Zmienna przechowująca prawdopodobieństwo zarażenia.
	 */
	float probabilityOfInfection;

	/**
	 * Zmienna, która mówi o tym czy jest dozwolone wielokrotne zarażanie przez komórkę.
	 */
	bool multiInfectionsOfQuad;

	/**
	 * Zmienna, która służy do zatrzymywania symulacji. Tylko i wyłącznie logika symulacji jest zatrzymywana.
	 */
	bool stopLogic;

	/**
	 * Zmienna mówiąca o tym czy aktualnie zarażane komórki są stałymi punktami zarażenia.
	 */
	bool pointOfInfection;

	/**
	 * Zmienna, która włącza bądź wyłącza gradacje kolorów.
	 */
	bool colorGradation;

	/**
	 * Zmienna przechowująca aktualną liczbę klatek na sekundę.
	 */
	float currentFPS;

	/**
	 * Metoda zwracająca instancje klasy.
	 * \return SimulationSettings*
	 */
	static SimulationSettings *getInstance();
private:
	/**
	 * Domyślny konstruktor.
	 */
	SimulationSettings();
	/**
	 * Destruktor.
	 */
	~SimulationSettings();

	/**
	 * Jedyna instancja klasy SimulationSettings, która jest udostępniana przez \ref static SimulationSettings* SimulationSettings::getInstance()
	 */
	static SimulationSettings *s_simulation_settings;

};

