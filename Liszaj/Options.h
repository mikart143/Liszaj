#pragma once
#include <SFML/System/Vector2.hpp>
#include <imgui.h>
#include "SimulationSettings.h"
#include "Tile.h"
/**
 * Klasa służąca do obsługi i wyświetlania Opcji w Panelu Sterowania.
 */
class Options
{
public:
	/**
	 * Domyślny konstruktor.
	 */
	Options();
	/**
	 * Destruktor.
	 */
	~Options();
	/**
	 * Metoda obsługująca rysowanie wszystkich elementów.
	 */
	void draw();
	/**
	 * Metoda służąca do ustawienia wskaźnika zmiennej m_tile.
	 */
	void setTile(Tile *tile);
	/**
	 * Zmienna pomocnicza przechowująca czas infekcji.
	 */
	float infectionTime;
	/**
	 * Zmienna pomocnicza przechowująza czas odporności.
	 */
	float resistanceTime;
	/**
	 * Zmienna pomocnicza przechowująza czas pomiędzy infekcjami.
	 */
	float infectionGapTime;
	/**
	 * Wektor przechowujący wszystkie całkowite dzielniki szerokośći i wysokości ekranu.
	 */
	std::vector<std::string> factors;
	/**
	 * Zmienna pomocnicza przechowująca numer wybranego elementu z listy możliwych dzielników.
	 */
	int selected;
	/**
	 * Zmienna pomocnicza przechowująca kolor zarażonej komórki.
	 */
	ImVec4 infectedColor;
	/**
	 * Zmienna pomocnicza przechowująca kolor odpornej komórki.
	 */
	ImVec4 resistanceColor;
	/**
	 * Zmienna pomocnicza przechowująca kolor zdrowej komórki.
	 */
	ImVec4 healthyColor;
private:
	/**
	 * Zmienna przechowująca wskaźnik do siatki w której mają być wdrażane zmiany. Zmiennej przypisywany jest wskaźnik przez metodę: \ref void Options::setTile(Tile *tile);
	 */
	Tile *m_tile;
};

