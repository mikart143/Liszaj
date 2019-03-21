#pragma once
#include <SFML/System/Vector2.hpp>
#include<iostream>
#include "Quad.h"

class Quad;

/**
 * Singleton odpowiadający za ustawienia siatki komórek. Przechowuje najważniejsze zmienne.
 */
class TileSettings
{
public:
	/**
	 * Zmienna opisująca szerokość i długość siatki.
	 */
	sf::Vector2u tileSize;
	/**
	 * Wektor przechowujący wszystkie komórki.
	 */
	std::vector<Quad> tileQuads;
	/**
	 * Zmienna przechowująca rozmiar głównego okna.
	 */
	sf::Vector2u mainWindowSize;
	/**
	 * Metoda zwracająca instancje klasy.
	 * \return TileSettings*
	 */
	static TileSettings *getInstance();
private:
	/**
	 * Domyślny konstruktor.
	 */
	TileSettings();
	/**
	 * Destruktor.
	 */
	~TileSettings();

	/**
	 * Jedyna instancja klasy TileSettings, która jest udostępniana przez \ref static TileSettings* TileSettings::getInstance()
	 */
	static TileSettings *s_tile_settings;
};

