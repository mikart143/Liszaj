#pragma once
#include <sfml-imgui/sfml-imgui/imgui-SFML.hpp>
#include <imgui.h>
/**
 * Klasa, która odpowiada za kartę Statystyki w Panelu Sterowania.
 */
class Statistics
{
public:
	/**
	 * Domyślny konstruktor.
	 */
	Statistics();
	/**
	 * Destruktor.
	 */
	~Statistics();

	/**
	 * Metoda która rysuje zakładkę Statystyki.
	 */
	void draw();
};

