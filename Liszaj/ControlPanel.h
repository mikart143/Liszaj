#pragma once
#include <imgui.h>
#include <SFML/System/Vector2.hpp>
#include "Tile.h"
#include "Options.h"
#include "Statistics.h"

/**
 *  Klasa odpowiadająca za rysowania głównego okna Panelu Sterowania.
 */
class ControlPanel
{
public:
	/**
	 *	Domyślny konstruktor.
	 */
	ControlPanel();
	/**
	 *	Destruktor
	 */
	~ControlPanel();
	/**
	 * Metoda odpowiadajaća za rysowanie (wyświetlanie) okna Panelu Sterowania.
	 */
	void draw();
	/**
	 * Metoda odpowiadająca za ustawienie zmiennej prywatnej m_tile.
	 * 
	 * \param tile Przekazuje wskaźnik do siatki (Tile), do której będą odnosiły się opcje w panelu.
	 */
	void setTile(Tile *tile);
	/**
	 * Zmienna przechowująca pozycję okna Panelu Sterowania.
	 */

	sf::Vector2f windowPosition;
	/**
	 * Zmienna przechowująca rozmiar okna Panelu Sterowania.
	 */
	sf::Vector2f windowSize;
private:
	/**
	 * Zmienna, która odpowiada za zakładkę Opcje w Panelu Sterowania i zawiera wszystkie kontroli wchodzące w skłąd tej sekcji.
	 */
	Options m_options;
	/**
	 *  Zmienna, która odpowiada za zakładkę Statystyki w Panelu sterowania i zawiera wszystkie kontroli wchodzące w skłąd tej sekcji.
	 */
	Statistics m_statistics;
	/**
	 * Zmienna do której przypisywany jest wskaźnik przez metodę: \ref void ControlPanel::setTile(Tile *tile)
	 */
	Tile *m_tile;
};

